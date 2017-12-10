//
//  SUMNavigationBarController.h
//  Summer
//
//  Created by zm on 2017/6/24.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SUMCordovaController.h"

@interface SUMNavigationBarController : SUMCordovaController

@property (nonatomic, copy) NSDictionary *actionBar;
@property (nonatomic, copy) NSString *actionBarType;
@property (nonatomic, copy) NSDictionary *nav;

@end
