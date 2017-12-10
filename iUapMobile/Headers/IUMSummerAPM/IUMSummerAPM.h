//
//  IUMSummerAPM.h
//  IUMSummerAPM
//
//  Created by zm on 2017/6/5.
//  Copyright © 2017年 zm. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _IUMSUMMERAPM_
#define _IUMSUMMERAPM_

#if __has_include(<IUMSummerAPM/IUMSummerAPM.h>)

FOUNDATION_EXPORT double IUMSummerAPMVersionNumber;
FOUNDATION_EXPORT const unsigned char IUMSummerAPMVersionString[];

#import <IUMSummerAPM/IUMAPM.h>

#elif __has_include(<iUapMobile/iUapMobile.h>)

#import <iUapMobile/IUMAPM.h>

#else

#import "IUMAPM.h"

#endif /* __has_include */

#endif /* _IUMSUMMERAPM_ */
