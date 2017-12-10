//
//  IUMServiceFactory.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IUMService;
@protocol IUMServiceProtocol;

@interface IUMServiceFactory : NSObject

+ (instancetype)sharedInstance;
- (IUMService<IUMServiceProtocol> *)serviceWithIdentifier:(NSString *)identifier;
- (IUMService<IUMServiceProtocol> *)newServiceWithIdentifier:(NSString *)identifier;
- (void)registerServiceWithIdentifier:(NSString *)identifier forClass:(Class)aClass;

@end
