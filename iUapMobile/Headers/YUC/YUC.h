//
//  YUC.h
//  YUC
//
//  Created by Chenly on 2017/10/27.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _YUC_
#define _YUC_

#if __has_include(<YUC/YUC.h>)

FOUNDATION_EXPORT double YUCVersionNumber;
FOUNDATION_EXPORT const unsigned char YUCVersionString[];

#import <YUC/YUCApplication.h>
#import <YUC/YUCMessage.h>
#import <YUC/YUCComponentInterface.h>

#else

#import "YUCApplication.h"
#import "YUCMessage.h"
#import "YUCComponentInterface.h"

#endif /* __has_include */

#endif /* YUC */
