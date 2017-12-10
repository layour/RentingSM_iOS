//
//  YUCMessageCallBack.h
//  YUCApplication
//
//  Created by 熊悦阅 on 2017/10/25.
//  Copyright © 2017年 熊悦阅. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YUCMessage;

@protocol YUCComponentInterface <NSObject>

@required
@property (nonatomic, copy) NSString *componentId;

- (UIViewController *)open:(YUCMessage *)message;
- (id)doTask:(YUCMessage *)message;
- (void)close:(YUCMessage *)message;

@optional
@property (nonatomic, copy) NSDictionary *settings;
- (void)close;
- (void)closeWithMessage:(YUCMessage *)message;

@end

