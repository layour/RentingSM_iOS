//
//  IUMFileTransfer.h
//  IUMCore
//
//  Created by Chenly on 2017/3/17.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IUMFileTransfer : NSObject

+ (instancetype)sharedInstance;

- (void)downloadWithRequest:(NSURLRequest *)request
                   progress:(void (^)(NSProgress *downloadProgress))progress
                destination:(NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destination
                 completion:(void (^)(NSURLResponse *response, NSURL *filePath, NSError *error))completion;

- (void)uploadWithRequest:(NSURLRequest *)request
                 fromFile:(NSURL *)fileURL
                 progress:(void (^)(NSProgress *uploadProgress))progress
               completion:(void (^)(NSURLResponse *response, NSData *responseData, NSError *error))completion;

- (void)uploadWithRequestURL:(NSURL *)url
                     timeout:(float)timeout
                     headers:(NSDictionary *)headers
                   fromFiles:(NSArray *)files
                  withParams:(NSDictionary *)params
                    progress:(void (^)(NSProgress *))progress
                  completion:(void (^)(NSURLResponse *response, NSData *responseData, NSError *error))completion;

@end
