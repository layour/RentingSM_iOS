//
//  Summer.h
//  Summer
//
//  Created by Chenly on 2016/11/22.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _SUMMER_
#define _SUMMER_

#if __has_include(<Summer/Summer.h>)

FOUNDATION_EXPORT double SummerVersionNumber;
FOUNDATION_EXPORT const unsigned char SummerVersionString[];

#import <Summer/SUMViewControllerProtocol.h>
#import <Summer/SUMCordovaController.h>
#import <Summer/SummerFactory.h>
#import <Summer/SUMCordovaReformer.h>
#import <Summer/SUMBaseReformer.h>
#import <Summer/SUMJSSerialization.h>
#import <Summer/SUMJavaScriptBridge.h>
#import <Summer/SummerRouter.h>
#import <Summer/UIViewController+SUMProtocol.h>
#import <Summer/SUMNavigationBarController.h>
#import <Summer/SUMNavigationBarGenerator.h>
#import <Summer/SUMNavigationBarReformer.h>
#import <Summer/UIViewController+SummerTheme.h>
#import <Summer/SummerInterface.h>
#import <Summer/SUMViewControllerFactory.h>
#import <Summer/SummerWebAppManager.h>

// MWPhotoBrowser
#import <Summer/IUMPhotoBrowser.h>

#else

#import "SUMViewControllerProtocol.h"
#import "SUMCordovaController.h"
#import "SummerFactory.h"
#import "SUMCordovaReformer.h"
#import "SUMBaseReformer.h"
#import "SUMJSSerialization.h"
#import "SUMJavaScriptBridge.h"
#import "SummerRouter.h"
#import "UIViewController+SUMProtocol.h"
#import "SUMNavigationBarController.h"
#import "SUMNavigationBarGenerator.h"
#import "SUMNavigationBarReformer.h"
#import "UIViewController+SummerTheme.h"
#import "SummerInterface.h"
#import "SUMViewControllerFactory.h"
#import "SummerWebAppManager.h"

// MWPhotoBrowser
#import "IUMPhotoBrowser.h"

#endif /* __has_include */

#endif /* _SUMMER_ */
