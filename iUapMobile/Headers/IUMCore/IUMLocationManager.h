//
//  IUMLocationManager.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSUInteger, IUMLocationStatus) {
    IUMLocationStatusDefault,               //默认状态
    IUMLocationStatusOK,                    //定位功能正常
    IUMLocationStatusUnknownError,          //未知错误
    IUMLocationStatusUnAvailable,           //定位功能关掉了
    IUMLocationStatusNoAuthorization,       //定位功能打开，但是用户不允许使用定位
    IUMLocationStatusNoNetwork,             //没有网络
    IUMLocationStatusNotDetermined          //用户还没做出是否要允许应用使用定位功能的决定，第一次安装应用的时候会提示用户做出是否允许使用定位功能的决定
};

typedef NS_ENUM(NSUInteger, IUMLocationResult) {
    IUMLocationResultDefault,              //默认状态
    IUMLocationResultLocating,             //定位中
    IUMLocationResultSuccess,              //定位成功
    IUMLocationResultFail,                 //定位失败
    IUMLocationResultParamsError,          //调用API的参数错了
    IUMLocationResultTimeout,              //超时
    IUMLocationResultNoNetwork,            //没有网络
    IUMLocationResultNoContent             //API没返回数据或返回数据是错的
};

extern NSString * const IUMDidUpdateLocationNotification;

@interface IUMLocationManager : NSObject

@property (nonatomic, assign, readonly) IUMLocationResult locationResult;
@property (nonatomic, assign, readonly) IUMLocationStatus locationStatus;
@property (nonatomic, copy, readonly) CLLocation *currentLocation;

+ (instancetype)sharedInstance;

- (void)startLocation;
- (void)stopLocation;
- (void)restartLocation;

@end

@interface CLLocation (TianChaoLocation)

- (CLLocation *)transformToGCJ;

@end
