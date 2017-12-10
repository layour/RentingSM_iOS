//
//  IUMURLResponse.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IUMNetworkingConfiguration.h"

@interface IUMURLResponse : NSObject

@property (nonatomic, readonly, assign) NSInteger requestId;
@property (nonatomic, readonly, copy) NSURLRequest *request;
@property (nonatomic, copy) NSDictionary *requestParams;

@property (nonatomic, readonly, copy) id responseObject;
@property (nonatomic, readonly, assign) IUMURLResponseStatus status;

@property (nonatomic, readonly, strong) NSError *error;
@property (nonatomic, readonly, assign) BOOL isCache;

- (instancetype)initWithResponseObject:(id)responseObject requestId:(NSNumber *)requestId request:(NSURLRequest *)request status:(IUMURLResponseStatus)status;

- (instancetype)initWithResponseObject:(id)responseObject requestId:(NSNumber *)requestId request:(NSURLRequest *)request error:(NSError *)error;

// 使用initWithData的response，它的isCache是YES，上面两个函数生成的response的isCache是NO
- (instancetype)initWithData:(NSData *)data;

@end
