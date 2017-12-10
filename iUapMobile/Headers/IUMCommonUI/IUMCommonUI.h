//
//  IUMCommonUI.h
//  IUMCommonUI
//
//  Created by Chenly on 2017/2/23.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _IUMCOMMONUI_
#define _IUMCOMMONUI_

#if __has_include(<IUMCommonUI/IUMCommonUI.h>)

FOUNDATION_EXPORT double IUMCommonUIVersionNumber;
FOUNDATION_EXPORT const unsigned char IUMCommonUIVersionString[];

#import <IUMCommonUI/UIAlertController+IUMExtensions.h>
#import <IUMCommonUI/UIColor+HexString.h>
#import <IUMCommonUI/UIImage+IUMExtensions.h>
#import <IUMCommonUI/UIViewController+IUMExtensions.h>
#import <IUMCommonUI/IUMQRCodeViewController.h>
#import <IUMCommonUI/IUMDialog.h>

#elif __has_include(<iUapMobile/iUapMobile.h>)

#import <iUapMobile/UIAlertController+IUMExtensions.h>
#import <iUapMobile/UIColor+HexString.h>
#import <iUapMobile/UIImage+IUMExtensions.h>
#import <iUapMobile/UIViewController+IUMExtensions.h>
#import <iUapMobile/IUMQRCodeViewController.h>
#import <iUapMobile/IUMDialog.h>

#else

#import "UIAlertController+IUMExtensions.h"
#import "UIColor+HexString.h"
#import "UIImage+IUMExtensions.h"
#import "UIViewController+IUMExtensions.h"
#import "IUMQRCodeViewController.h"
#import "IUMDialog.h"

#endif /* __has_include */

#endif /* _IUMCOMMONUI_ */
