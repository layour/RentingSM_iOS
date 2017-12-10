//
//  IUMAPIBaseManager.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IUMAPIBaseManager;
@class IUMURLResponse;

extern NSString * const IUMAPIBaseManagerRequestID;

@protocol IUMAPIManagerCallBackDelegate <NSObject>
@required
- (void)managerCallAPIDidSuccess:(IUMAPIBaseManager *)manager;
- (void)managerCallAPIDidFailed:(IUMAPIBaseManager *)manager;
@end


@protocol IUMAPIManagerDataReformer <NSObject>
@required
- (id)manager:(IUMAPIBaseManager *)manager reformData:(NSDictionary *)data;
@end


@protocol IUMAPIManagerValidator <NSObject>
@required
- (BOOL)manager:(IUMAPIBaseManager *)manager isCorrectWithCallBackData:(NSDictionary *)data;
- (BOOL)manager:(IUMAPIBaseManager *)manager isCorrectWithParamsData:(NSDictionary *)data;
@end


@protocol IUMAPIManagerParamSource <NSObject>
@required
- (NSDictionary *)paramsForApi:(IUMAPIBaseManager *)manager;
@end


typedef NS_ENUM (NSUInteger, IUMAPIManagerErrorType){
    IUMAPIManagerErrorTypeDefault,       //没有产生过API请求，这个是manager的默认状态。
    IUMAPIManagerErrorTypeSuccess,       //API请求成功且返回数据正确，此时manager的数据是可以直接拿来使用的。
    IUMAPIManagerErrorTypeNoContent,     //API请求成功但返回数据不正确。如果回调数据验证函数返回值为NO，manager的状态就会是这个。
    IUMAPIManagerErrorTypeParamsError,   //参数错误，此时manager不会调用API，因为参数验证是在调用API之前做的。
    IUMAPIManagerErrorTypeTimeout,       //请求超时。IUMAPIProxy设置的是20秒超时，具体超时时间的设置请自己去看IUMAPIProxy的相关代码。
    IUMAPIManagerErrorTypeNoNetWork      //网络不通。在调用API之前会判断一下当前网络是否通畅，这个也是在调用API之前验证的，和上面超时的状态是有区别的。
};

typedef NS_ENUM (NSUInteger, IUMAPIManagerRequestType){
    IUMAPIManagerRequestTypeGet,
    IUMAPIManagerRequestTypePost,
    IUMAPIManagerRequestTypePut,
    IUMAPIManagerRequestTypeDelete
};


@protocol IUMAPIManager <NSObject>

@required
- (NSString *)methodName;
- (NSString *)serviceType;
- (IUMAPIManagerRequestType)requestType;
- (BOOL)shouldCache;

@optional
- (void)cleanData;
- (NSDictionary *)reformParams:(NSDictionary *)params;
- (NSInteger)loadDataWithParams:(NSDictionary *)params;
- (BOOL)shouldLoadFromNative;   // 本地缓存

@end


@protocol IUMAPIManagerInterceptor <NSObject>

@optional
- (BOOL)manager:(IUMAPIBaseManager *)manager beforePerformSuccessWithResponse:(IUMURLResponse *)response;
- (void)manager:(IUMAPIBaseManager *)manager afterPerformSuccessWithResponse:(IUMURLResponse *)response;

- (BOOL)manager:(IUMAPIBaseManager *)manager beforePerformFailWithResponse:(IUMURLResponse *)response;
- (void)manager:(IUMAPIBaseManager *)manager afterPerformFailWithResponse:(IUMURLResponse *)response;

- (BOOL)manager:(IUMAPIBaseManager *)manager shouldCallAPIWithParams:(NSDictionary *)params;
- (void)manager:(IUMAPIBaseManager *)manager afterCallingAPIWithParams:(NSDictionary *)params;

@end


@interface IUMAPIBaseManager : NSObject

@property (nonatomic, weak) id<IUMAPIManagerCallBackDelegate> delegate;
@property (nonatomic, weak) id<IUMAPIManagerParamSource> paramSource;
@property (nonatomic, weak) id<IUMAPIManagerValidator> validator;
@property (nonatomic, weak) NSObject<IUMAPIManager> *child; //里面会调用到NSObject的方法，所以这里不用id
@property (nonatomic, weak) id<IUMAPIManagerInterceptor> interceptor;

@property (nonatomic, copy, readonly) NSString *errorMessage;
@property (nonatomic, readonly) IUMAPIManagerErrorType errorType;
@property (nonatomic, strong) IUMURLResponse *response;

@property (nonatomic, assign, readonly) BOOL isReachable;
@property (nonatomic, assign, readonly) BOOL isLoading;

- (id)fetchDataWithReformer:(id<IUMAPIManagerDataReformer>)reformer;

//尽量使用loadData这个方法,这个方法会通过param source来获得参数，这使得参数的生成逻辑位于controller中的固定位置
- (NSInteger)loadData;

- (void)cancelAllRequests;
- (void)cancelRequestWithRequestId:(NSInteger)requestID;

// 拦截器方法，继承之后需要调用一下super
- (BOOL)beforePerformSuccessWithResponse:(IUMURLResponse *)response;
- (void)afterPerformSuccessWithResponse:(IUMURLResponse *)response;

- (BOOL)beforePerformFailWithResponse:(IUMURLResponse *)response;
- (void)afterPerformFailWithResponse:(IUMURLResponse *)response;

- (BOOL)shouldCallAPIWithParams:(NSDictionary *)params;
- (void)afterCallingAPIWithParams:(NSDictionary *)params;

- (NSDictionary *)reformParams:(NSDictionary *)params;
- (void)cleanData;
- (BOOL)shouldCache;

- (void)successedOnCallingAPI:(IUMURLResponse *)response;
- (void)failedOnCallingAPI:(IUMURLResponse *)response withErrorType:(IUMAPIManagerErrorType)errorType;

@end
