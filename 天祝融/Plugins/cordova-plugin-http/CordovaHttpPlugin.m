#import "CordovaHttpPlugin.h"

NS_ASSUME_NONNULL_BEGIN
typedef void (^CompletionHandler)(NSHTTPURLResponse *response, id responseObject, NSError *error);

@interface CordovaHttpPlugin () <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>

@property (nonatomic, strong) NSURLSession *session;

@property NSMutableDictionary <NSString *, CompletionHandler> *completionHandlers;
@property NSMutableDictionary <NSString *, NSMutableData *> *receiveDatas;

@end
NS_ASSUME_NONNULL_END

@implementation CordovaHttpPlugin

- (void)pluginInitialize {
    
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    self.session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    
    self.completionHandlers = [NSMutableDictionary dictionary];
    self.receiveDatas = [NSMutableDictionary dictionary];
}

- (void)setHeaders:(NSDictionary *)headers forRequest:(NSMutableURLRequest *)request {
    
    [headers enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [request setValue:obj forHTTPHeaderField:key];
    }];
    
    NSString *userAgent = headers[@"User-Agent"];
    if (!userAgent) {
        // from AFNetworking
        userAgent = [NSString stringWithFormat:@"%@/%@ (%@; iOS %@; Scale/%0.2f)", [[NSBundle mainBundle] infoDictionary][(__bridge NSString *)kCFBundleExecutableKey] ?: [[NSBundle mainBundle] infoDictionary][(__bridge NSString *)kCFBundleIdentifierKey], [[NSBundle mainBundle] infoDictionary][@"CFBundleShortVersionString"] ?: [[NSBundle mainBundle] infoDictionary][(__bridge NSString *)kCFBundleVersionKey], [[UIDevice currentDevice] model], [[UIDevice currentDevice] systemVersion], [[UIScreen mainScreen] scale]];
        [request setValue:userAgent forHTTPHeaderField:@"User-Agent"];
    }
    
    NSString *acceptLanguage = headers[@"Accept-Language"];
    if (!acceptLanguage) {
        // from AFNetworking
        NSMutableArray *acceptLanguagesComponents = [NSMutableArray array];
        [[NSLocale preferredLanguages] enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
            float q = 1.0f - (idx * 0.1f);
            [acceptLanguagesComponents addObject:[NSString stringWithFormat:@"%@;q=%0.1g", obj, q]];
            *stop = q <= 0.5f;
        }];
        acceptLanguage = [acceptLanguagesComponents componentsJoinedByString:@", "];
        [request setValue:acceptLanguage forHTTPHeaderField:@"Accept-Language"];
    }
}

#pragma mark - public method

- (void)post:(CDVInvokedUrlCommand *)command {
    
    NSString *urlString      = [command.arguments objectAtIndex:0];
    NSDictionary *parameters = [command.arguments objectAtIndex:1];
    NSDictionary *headers    = [command.arguments objectAtIndex:2];
    NSDictionary *settings   = command.arguments.count >= 4 ? [command.arguments objectAtIndex:3] : nil;
    
    urlString = [urlString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    
    NSURL *URL = [NSURL URLWithString:urlString];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:URL];
    request.HTTPMethod = @"POST";
    
    if (settings[@"timeout"]) {
        NSTimeInterval timeout = [settings[@"timeout"] floatValue] / 1000;
        request.timeoutInterval = timeout;
    }
    
    [self setHeaders:headers forRequest:request];
    
    NSString *contentType = request.allHTTPHeaderFields[@"Content-Type"];
    if (contentType && [contentType containsString:@"json"]) {
        
        if ([parameters isKindOfClass:[NSString class]]) {
            request.HTTPBody = [(NSString *)parameters dataUsingEncoding:NSUTF8StringEncoding];
        }
        else {
            request.HTTPBody = [NSJSONSerialization dataWithJSONObject:parameters options:0 error:NULL];
        }
    }
    else {
        NSMutableArray *params = [NSMutableArray array];
        [parameters enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSString *value, BOOL *stop) {
            [params addObject:[NSString stringWithFormat:@"%@=%@", key, value]];
        }];
        NSString *bodyString = [params componentsJoinedByString:@"&"];
        bodyString = [bodyString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        request.HTTPBody = [bodyString dataUsingEncoding:NSUTF8StringEncoding];
    }
    
    NSURLSessionTask *task = [self.session dataTaskWithRequest:request];
    
    __weak __typeof(self) weakSelf = self;
    NSString *identifier = @(task.taskIdentifier).stringValue;
    self.completionHandlers[identifier] = ^(NSHTTPURLResponse *response, id responseObject, NSError *error) {
        
        NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
        dictionary[@"status"] = @(response.statusCode);
        dictionary[@"headers"] = response.allHeaderFields;
        if (!error && response.statusCode == 200) {
            
            dictionary[@"data"] = responseObject;
            CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dictionary];
            [weakSelf.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }
        else {
            dictionary[@"error"] = error ? error.localizedDescription : responseObject;
            CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsDictionary:dictionary];
            [weakSelf.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }
    };
    
    [task resume];
}

- (void)get:(CDVInvokedUrlCommand*)command {
    
    NSString *urlString      = [command.arguments objectAtIndex:0];
    NSDictionary *parameters = [command.arguments objectAtIndex:1];
    NSDictionary *headers    = [command.arguments objectAtIndex:2];
    NSDictionary *settings   = command.arguments.count >= 4 ? [command.arguments objectAtIndex:3] : nil;
    
    NSMutableArray *params = [NSMutableArray array];
    if(parameters.count > 0){
        [parameters enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSString *value, BOOL *stop) {
            [params addObject:[NSString stringWithFormat:@"%@=%@", key, value]];
        }];
    }
    if (params.count > 0) {
        NSString *query = [params componentsJoinedByString:@"&"];
        urlString = [NSString stringWithFormat:@"%@?%@", urlString, query];
    }
    urlString = [urlString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    
    NSURL *URL = [NSURL URLWithString:urlString];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:URL];
    request.HTTPMethod = @"GET";
    
    if (settings[@"timeout"]) {
        NSTimeInterval timeout = [settings[@"timeout"] floatValue] / 1000;
        request.timeoutInterval = timeout;
    }
    
    [self setHeaders:headers forRequest:request];
    
    NSURLSessionTask *task = [self.session dataTaskWithRequest:request];
    
    __weak __typeof(self) weakSelf = self;
    NSString *identifier = @(task.taskIdentifier).stringValue;
    self.completionHandlers[identifier] = ^(NSHTTPURLResponse *response, id responseObject, NSError *error) {
        
        NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
        dictionary[@"status"] = @(response.statusCode);
        dictionary[@"headers"] = response.allHeaderFields;
        if (!error && response.statusCode == 200) {
            
            dictionary[@"data"] = responseObject;
            CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dictionary];
            [weakSelf.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }
        else {
            dictionary[@"error"] = error ? error.localizedDescription : responseObject;
            CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsDictionary:dictionary];
            [weakSelf.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }
    };
    
    [task resume];
}

#pragma mark - <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
    didReceiveData:(NSData *)data {
    
    NSString *identifier = @(dataTask.taskIdentifier).stringValue;
    NSMutableData *receiveData = self.receiveDatas[identifier] ?: [NSMutableData data];
    [receiveData appendData:data];
    self.receiveDatas[identifier] = receiveData;
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(NSError *)error {
    
    NSString *identifier = @(task.taskIdentifier).stringValue;
    CompletionHandler completion = self.completionHandlers[identifier];
    if (completion) {
        
        NSHTTPURLResponse *response = (NSHTTPURLResponse *)task.response;
        id responseObject = nil;
        
        NSData *data = self.receiveDatas[identifier];
        if (data) {
            NSStringEncoding stringEncoding = NSUTF8StringEncoding;
            if (response.textEncodingName) {
                CFStringEncoding encoding = CFStringConvertIANACharSetNameToEncoding((CFStringRef)response.textEncodingName);
                if (encoding != kCFStringEncodingInvalidId) {
                    stringEncoding = CFStringConvertEncodingToNSStringEncoding(encoding);
                }
            }
            responseObject = [[NSString alloc] initWithData:data encoding:stringEncoding];
        }
        completion(response, responseObject, error);
    }
    
    self.completionHandlers[identifier] = nil;
    self.receiveDatas[identifier] = nil;
}

@end
