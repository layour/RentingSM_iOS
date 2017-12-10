//
//  IUMNetworkingConfiguration.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#ifndef IUMNetworkingConfiguration_h
#define IUMNetworkingConfiguration_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IUMURLResponseStatus)
{
    IUMURLResponseStatusSuccess,
    IUMURLResponseStatusErrorTimeout,
    IUMURLResponseStatusErrorNoNetwork // 默认除了超时以外的错误都是无网络错误。
};

typedef NS_ENUM(NSUInteger, IUMSSLVerifyMode) {
    IUMSSLVerifyModeNone = 0,   // 不允许自签名
    IUMSSLVerifyModeStrict,     // 校验本地证书
    IUMSSLVerifyModePermissive, // 允许添加不校验的域名
    IUMSSLVerifyModeAllowAll,   // 允许所有
};

static BOOL kIUMServiceIsOnline = YES;
static BOOL kIUMShouldCache = YES;

static NSTimeInterval kIUMNetworkingTimeoutSeconds = 20.0f;
static NSTimeInterval kIUMCacheOutdateTimeSeconds = 300; // 5分钟的cache过期时间
static NSUInteger kIUMCacheCountLimit = 1000; // 最多1000条cache

@interface IUMNetworkingConfiguration : NSObject

+ (instancetype)configuration;

@property (nonatomic, assign) IUMSSLVerifyMode verifyMode;
@property (nonatomic, strong) NSSet <NSData *> *pinnedCertificates;

@property (nonatomic, copy, readonly) NSSet<NSString *> *allowInvalidSSLDomains;
- (void)setAllowInvalidSSLForDomain:(NSString *)domain;
- (void)removeAllowInvalidSSLForDomain:(NSString *)domain;

- (BOOL)evaluateServerTrust:(SecTrustRef)serverTrust forDomain:(NSString *)domain;

@end

#endif /* IUMNetworkingConfiguration_h */
