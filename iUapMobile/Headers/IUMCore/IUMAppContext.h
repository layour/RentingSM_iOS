//
//  IUMAppContext.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IUMAppContext : NSObject

@property (nonatomic, copy, readonly) NSString *type;
@property (nonatomic, copy, readonly) NSString *model;
@property (nonatomic, copy, readonly) NSString *os;
@property (nonatomic, copy, readonly) NSString *UUID;
@property (nonatomic, copy, readonly) NSString *SSID;
@property (nonatomic, copy, readonly) NSString *deviceName;

// 全局变量
@property (nonatomic, strong) NSMutableDictionary *globalValues;

// 运行环境相关
@property (nonatomic, assign, readonly) BOOL isReachable;
@property (nonatomic, assign, readonly) NSInteger networkStatus; // 0.NotReachable; 1.WiFi; 2.WWAN;
@property (nonatomic, assign) BOOL isOnline;

// app信息
@property (nonatomic, readonly) NSString *appid;
@property (nonatomic, readonly) NSString *displayName;
@property (nonatomic, readonly) NSString *buildVersion;
@property (nonatomic, readonly) NSString *appVersion;
@property (nonatomic, readonly) NSString *bundleIdentifier;

// 推送相关
@property (nonatomic, copy) NSString *pushToken;

// 地理位置
@property (nonatomic, assign, readonly) CGFloat latitude;
@property (nonatomic, assign, readonly) CGFloat longitude;

+ (instancetype)sharedInstance;

@end
