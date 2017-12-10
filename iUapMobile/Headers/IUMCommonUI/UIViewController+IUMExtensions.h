//
//  UIViewController+IUMExtensions.h
//  IUMUIComponents
//
//  Created by Chenly on 2017/2/22.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (IUMExtensions)

+ (void)setDefaultBackButtonBackgroundImage:(UIImage *)image;
- (void)setBackBarButtonItemWithoutTitle;
- (void)setRightBarButtonItemWithImage:(UIImage *)image target:(id)target action:(SEL)action;

@end
