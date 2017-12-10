//
//  IUMMediator.h
//  IUMMediator
//
//  Created by Chenly on 2017/2/20.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IUMMediator : NSObject

+ (instancetype)sharedInstance;

- (id)performTarget:(NSString *)targetName action:(NSString *)actionName params:(NSDictionary *)params shouldCacheTarget:(BOOL)shouldCacheTarget;
- (void)releaseCachedTargetWithTargetName:(NSString *)targetName;

// 扩展服务
- (BOOL)respondsToExtension:(NSString *)extensionName;
- (void)registerExtension:(NSString *)extensionName forClass:(NSString *)className;
- (id)performExtension:(NSString *)extensionName action:(NSString *)action params:(id)params;

@end

