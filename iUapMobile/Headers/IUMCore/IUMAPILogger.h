//
//  IUMAPILogger.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IUMService;
@class IUMURLResponse;

@interface IUMAPILogger : NSObject

+ (void)turnOn:(BOOL)flag;

+ (void)logDebugInfoWithRequest:(NSURLRequest *)request
                        apiName:(NSString *)apiName
                        service:(IUMService *)service
                  requestParams:(id)requestParams
                     httpMethod:(NSString *)httpMethod;

+ (void)logDebugInfoWithResponse:(NSHTTPURLResponse *)response
                  responseString:(NSString *)responseString
                         request:(NSURLRequest *)request
                           error:(NSError *)error;

+ (void)logDebugInfoWithCachedResponse:(IUMURLResponse *)response
                            methodName:(NSString *)methodName
                     serviceIdentifier:(IUMService *)service;

@end
