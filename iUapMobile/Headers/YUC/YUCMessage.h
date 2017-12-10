//
//  YUCMessage.h
//  YUCApplication
//
//  Created by 熊悦阅 on 2017/10/25.
//  Copyright © 2017年 熊悦阅. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "YUCMessageCallBack.h"

@interface YUCMessage : NSObject

@property (nonatomic, copy) NSString *componentId;
@property (nonatomic, copy) NSString *componentName;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, copy) NSDictionary *params;

// @property (nonatomic, strong) id<YUCMessageCallBack> callback;
//@property (nonatomic, assign) int taskType;

@end

