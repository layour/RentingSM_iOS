//
//  EMM.h
//  EMM
//
//  Created by Chenly on 2016/10/28.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _EMM_
#define _EMM_

#if __has_include(<EMM/EMM.h>)

FOUNDATION_EXPORT double EMMVersionNumber;
FOUNDATION_EXPORT const unsigned char EMMVersionString[];

#import <EMM/EMMService.h>
#import <EMM/AgentService.h>
#import <EMM/EMMSimpleDataReformer.h>
#import <EMM/EMMComplexDataReformer.h>
#import <EMM/EMMResponseReformer.h>
#import <EMM/AgentDataReformer.h>
#import <EMM/EMMLocationService.h>
#import <EMM/EMMAppsManager.h>
#import <EMM/EMMRegisterAPI.h>
#import <EMM/EMMFeedbackAPI.h>
#import <EMM/EMMAutofindAPI.h>
#import <EMM/EMMUpdateAvatarAPI.h>
#import <EMM/EMMUserInfoAPI.h>
#import <EMM/EMMModifyPasswordAPI.h>
#import <EMM/EMMVersionInfoAPI.h>
#import <EMM/EMMGetAppsAPI.h>
#import <EMM/EMMGetDocsAPI.h>
#import <EMM/EMMLogoutAPI.h>
#import <EMM/AgentLoginAPI.h>

#elif __has_include(<iUapMobile/iUapMobile.h>)

#import <iUapMobile/EMMService.h>
#import <iUapMobile/AgentService.h>
#import <iUapMobile/EMMSimpleDataReformer.h>
#import <iUapMobile/EMMComplexDataReformer.h>
#import <iUapMobile/EMMResponseReformer.h>
#import <iUapMobile/AgentDataReformer.h>
#import <iUapMobile/EMMLocationService.h>
#import <iUapMobile/EMMAppsManager.h>
#import <iUapMobile/EMMRegisterAPI.h>
#import <iUapMobile/EMMFeedbackAPI.h>
#import <iUapMobile/EMMAutofindAPI.h>
#import <iUapMobile/EMMUpdateAvatarAPI.h>
#import <iUapMobile/EMMUserInfoAPI.h>
#import <iUapMobile/EMMModifyPasswordAPI.h>
#import <iUapMobile/EMMVersionInfoAPI.h>
#import <iUapMobile/EMMGetAppsAPI.h>
#import <iUapMobile/EMMGetDocsAPI.h>
#import <iUapMobile/EMMLogoutAPI.h>
#import <iUapMobile/AgentLoginAPI.h>

#else

#import "EMMService.h"
#import "AgentService.h"
#import "EMMSimpleDataReformer.h"
#import "EMMComplexDataReformer.h"
#import "EMMResponseReformer.h"
#import "AgentDataReformer.h"
#import "EMMLocationService.h"
#import "EMMAppsManager.h"
#import "EMMRegisterAPI.h"
#import "EMMFeedbackAPI.h"
#import "EMMAutofindAPI.h"
#import "EMMUpdateAvatarAPI.h"
#import "EMMUserInfoAPI.h"
#import "EMMModifyPasswordAPI.h"
#import "EMMVersionInfoAPI.h"
#import "EMMGetAppsAPI.h"
#import "EMMGetDocsAPI.h"
#import "EMMLogoutAPI.h"
#import "AgentLoginAPI.h"

#endif /* __has_include */

#endif /* _EMM_ */
