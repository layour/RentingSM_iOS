//
//  IUMService.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

// 所有IUMService的派生类都要符合这个protocol
@protocol IUMServiceProtocol <NSObject>

@property (nonatomic, readonly) BOOL isOnline;

@property (nonatomic, readonly) NSString *offlineApiBaseUrl;
@property (nonatomic, readonly) NSString *onlineApiBaseUrl;

@end

@interface IUMService : NSObject

@property (nonatomic, strong, readonly) NSString *apiBaseUrl;

@property (nonatomic, weak) id<IUMServiceProtocol> child;

@end
