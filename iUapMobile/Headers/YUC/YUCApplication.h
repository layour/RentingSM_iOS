//
//  YUCApplication.h
//  YUCApplication
//
//  Created by 熊悦阅 on 2017/10/25.
//  Copyright © 2017年 熊悦阅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YUCMessage.h"

@interface YUCApplication : NSObject

+ (instancetype)sharedApplication;

/**
 异步执行一次调用
 */
- (void)run:(YUCMessage *)message;

/**
 同步执行一次调用
 */
- (id)call:(YUCMessage *)message;

@end
