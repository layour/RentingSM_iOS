//
//  SUMViewController.h
//  Summer
//
//  Created by Chenly on 2017/4/5.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Cordova/CDV.h>

#import "SUMViewControllerProtocol.h"

@interface SUMCordovaController : CDVViewController <SUMEmbeddable>

@property (nonatomic, copy) NSString *bgcolor;
@property (nonatomic, assign) BOOL opaque;
@property (nonatomic, assign) BOOL hidden;
@property (nonatomic, assign) BOOL bounces;

// Window 参数
@property (nonatomic, assign) BOOL sum_navigationBarHidden;         // 导航栏是否隐藏
@property (nonatomic, assign) BOOL sum_statusBarAppearance;         // 状态栏是否显示
@property (nonatomic, assign) BOOL sum_bottomBarHidden;             // 底部栏是否隐藏
@property (nonatomic, assign) BOOL sum_fullScreen;                  // 是否使用状态栏的20高度
@property (nonatomic, assign) NSUInteger sum_preferredOrientation;  // 优先方向
@property (nonatomic, assign) NSUInteger sum_orientation;           // 支持方向
@property (nonatomic, copy)   NSString  *sum_statusBarStyle;        // 状态栏风格: dark | light
@property (nonatomic, copy) NSString *sum_title;

@property (nonatomic, assign) BOOL preload; // 预渲染

- (instancetype)init NS_UNAVAILABLE;
- (void)pageFinishLoad:(NSNotification *)notification;

// showProgress
@property (nonatomic, copy) void(^startLoading)(UIView *view);
@property (nonatomic, copy) void(^finishLoading)(UIView *view);

// =============== <SUMEmbeddable> ===============

@property (nonatomic, assign) BOOL embeded;
@property (nonatomic, assign) BOOL fixedPosition;
@property (nonatomic, copy) NSDictionary *position;
@property (nonatomic, weak) UIViewController<SUMViewController> *embedingViewController;

@end
