//
//  Mediator.h
//  Mediator
//
//  Created by Chenly on 2017/2/20.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef _MEDIATOR_
#define _MEDIATOR_

#if __has_include(<Mediator/Mediator.h>)

FOUNDATION_EXPORT double MediatorVersionNumber;
FOUNDATION_EXPORT const unsigned char MediatorVersionString[];

#import <Mediator/IUMMediator.h>
#import <Mediator/IUMExtension.h>
#import <Mediator/SUMExtension.h>
#import <Mediator/IUMMediator+Summer.h>
#import <Mediator/IUMMediator+PhotoBrowser.h>

#else

#import "IUMMediator.h"
#import "IUMExtension.h"
#import "SUMExtension.h"
#import "IUMMediator+Summer.h"
#import "IUMMediator+PhotoBrowser.h"

#endif /* __has_include */

#endif /* _MEDIATOR_ */


