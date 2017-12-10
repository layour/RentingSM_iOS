//
//  IUMCore.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _IUMCORE_
#define _IUMCORE_

#if __has_include(<IUMCore/IUMCore.h>)

FOUNDATION_EXPORT double IUMCoreVersionNumber;
FOUNDATION_EXPORT const unsigned char IUMCoreVersionString[];

#import <IUMCore/NSURLRequest+IUMNetworking.h>
#import <IUMCore/IUMCachedObject.h>
#import <IUMCore/IUMAPILogger.h>
#import <IUMCore/IUMURLResponse.h>
#import <IUMCore/NSObject+IUMNetworking.h>
#import <IUMCore/IUMNetworkingConfiguration.h>
#import <IUMCore/IUMAppContext.h>
#import <IUMCore/IUMRequestGenerator.h>
#import <IUMCore/IUMCache.h>
#import <IUMCore/UIDevice+Hardware.h>
#import <IUMCore/IUMAPIBaseManager.h>
#import <IUMCore/NSArray+IUMNetworking.h>
#import <IUMCore/IUMService.h>
#import <IUMCore/NSMutableString+IUMNetworking.h>
#import <IUMCore/IUMServiceFactory.h>
#import <IUMCore/IUMEncryptor.h>
#import <IUMCore/NSDictionary+IUMNetworking.h>
#import <IUMCore/IUMRequestAttachment.h>
#import <IUMCore/IUMLocationManager.h>
#import <IUMCore/IUMConfiguration.h>
//#import <IUMCore/IUMW3FolderManager.h>
#import <IUMCore/IUMFileTransfer.h>
#import <IUMCore/IUMGeneralReformerKeys.h>
#import <IUMCore/IUMLocalStorage.h>
#import <IUMCore/IUMSessionStorage.h>
#import <IUMCore/NSDictionary+CaseInsensitive.h>
#import <IUMCore/NSObject+Filter.h>
#import <IUMCore/NSObject+NullSensitive.h>
#import <IUMCore/IUMConvenienceHTTP.h>
#import <IUMCore/IUMResourceMacro.h>
#import <IUMCore/GCDThrottle.h>

#elif __has_include(<iUapMobile/iUapMobile.h>)

#import <iUapMobile/NSURLRequest+IUMNetworking.h>
#import <iUapMobile/IUMCachedObject.h>
#import <iUapMobile/IUMAPILogger.h>
#import <iUapMobile/IUMURLResponse.h>
#import <iUapMobile/NSObject+IUMNetworking.h>
#import <iUapMobile/IUMNetworkingConfiguration.h>
#import <iUapMobile/IUMAppContext.h>
#import <iUapMobile/IUMRequestGenerator.h>
#import <iUapMobile/IUMCache.h>
#import <iUapMobile/UIDevice+Hardware.h>
#import <iUapMobile/IUMAPIBaseManager.h>
#import <iUapMobile/NSArray+IUMNetworking.h>
#import <iUapMobile/IUMService.h>
#import <iUapMobile/NSMutableString+IUMNetworking.h>
#import <iUapMobile/IUMServiceFactory.h>
#import <iUapMobile/IUMEncryptor.h>
#import <iUapMobile/NSDictionary+IUMNetworking.h>
#import <iUapMobile/IUMRequestAttachment.h>
#import <iUapMobile/IUMLocationManager.h>
#import <iUapMobile/IUMConfiguration.h>
#import <iUapMobile/IUMFileTransfer.h>
#import <iUapMobile/IUMGeneralReformerKeys.h>
#import <iUapMobile/IUMLocalStorage.h>
#import <iUapMobile/IUMSessionStorage.h>
#import <iUapMobile/NSDictionary+CaseInsensitive.h>
#import <iUapMobile/NSObject+Filter.h>
#import <iUapMobile/NSObject+NullSensitive.h>
#import <iUapMobile/IUMConvenienceHTTP.h>
#import <iUapMobile/IUMResourceMacro.h>
#import <iUapMobile/GCDThrottle.h>

#else

#import "NSURLRequest+IUMNetworking.h"
#import "IUMCachedObject.h"
#import "IUMAPILogger.h"
#import "IUMURLResponse.h"
#import "NSObject+IUMNetworking.h"
#import "IUMNetworkingConfiguration.h"
#import "IUMAppContext.h"
#import "IUMRequestGenerator.h"
#import "IUMCache.h"
#import "UIDevice+Hardware.h"
#import "IUMAPIBaseManager.h"
#import "NSArray+IUMNetworking.h"
#import "IUMService.h"
#import "NSMutableString+IUMNetworking.h"
#import "IUMServiceFactory.h"
#import "IUMEncryptor.h"
#import "NSDictionary+IUMNetworking.h"
#import "IUMRequestAttachment.h"
#import "IUMLocationManager.h"
#import "IUMConfiguration.h"
#import "IUMFileTransfer.h"
#import "IUMGeneralReformerKeys.h"
#import "IUMLocalStorage.h"
#import "IUMSessionStorage.h"
#import "NSDictionary+CaseInsensitive.h"
#import "NSObject+Filter.h"
#import "NSObject+NullSensitive.h"
#import "IUMConvenienceHTTP.h"
#import "IUMResourceMacro"
#import "GCDThrottle.h"

#endif /* __has_include */

#endif /* _IUMCORE_ */
