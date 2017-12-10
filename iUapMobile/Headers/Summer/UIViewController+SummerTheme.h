//
//  UIViewController+SummerTheme.h
//  iUapMobile
//
//  Created by Chenly on 2017/9/1.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SummerBarItemPosition) {
    SummerBarItemPositionLeft,
    SummerBarItemPositionRight,
};

@interface UIViewController (SummerTheme)

- (UIControl *)theme_backItemCustomView;
- (UIControl *)theme_itemCustomViewWithText:(NSString *)text
                                      image:(UIImage *)image
                                   position:(SummerBarItemPosition)position;
- (UIControl *)theme_itemCustomViewWithInfo:(NSDictionary *)itemInfo;
- (void)theme_setNavigationBarStyle;

@end
