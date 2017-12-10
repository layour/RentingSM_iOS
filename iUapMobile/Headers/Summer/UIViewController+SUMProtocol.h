//
//  UIViewController+SUMProtocol.h
//  Summer
//
//  Created by Chenly on 2017/7/6.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SUMViewControllerProtocol.h"

typedef NS_ENUM(NSUInteger, SUMProtocolInjectOperation) {
    SUMProtocolInjectOperationIgnore = 0,
    SUMProtocolInjectOperationOverride,
    SUMProtocolInjectOperationAssertion,
};

@interface UIViewController (SUMProtocol)

+ (void)injectMethodsWithOperation:(SUMProtocolInjectOperation)operation type:(NSString *)type;

@end
