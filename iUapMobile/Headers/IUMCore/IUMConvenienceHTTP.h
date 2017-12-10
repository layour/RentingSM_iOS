//
//  IUMConvenienceHTTP.h
//  IUMCore
//
//  Created by Chenly on 2017/5/10.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IUMConvenienceHTTP : NSObject

- (void)post:(NSString *)url headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters completion:(void (^)(NSURLResponse *response, id responseObject, NSError *error))completion;

- (void)get:(NSString *)url headers:(NSDictionary *)headers parameters:(NSDictionary *)parameters completion:(void (^)(NSURLResponse *response, id responseObject, NSError *error))completion;

- (void)sendRequest:(NSURLRequest *)request completion:(void (^)(NSURLResponse *response, id responseObject, NSError *error))completion;

@end
