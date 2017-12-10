//
//  SummerRouter.h
//  Summer
//
//  Created by Chenly on 2017/9/11.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (SummerRouter)

@property (nonatomic, copy) NSString *summer_tag;

@end

@interface SummerRouter : NSObject

@property (nonatomic, copy) NSString *wwwFolderName;
@property (nonatomic, readonly) UIViewController *topViewController;

+ (instancetype)sharedRouter;

- (UIViewController *)viewControllerWithTag:(NSString *)tag;
- (UIViewController *)viewControllerWithTag:(NSString *)tag appid:(NSString *)appid;

- (void)pushViewControllerWithParams:(NSDictionary *)params;
- (void)pushViewController:(UIViewController *)viewController;
- (void)pushViewController:(UIViewController *)viewController animation:(NSDictionary *)animation isKeep:(BOOL)isKeep;

- (void)pullOutViewController:(UIViewController *)viewController;

- (void)popViewControllerWithAnimation:(NSDictionary *)animation;
- (void)popToViewController:(UIViewController *)viewController animation:(NSDictionary *)animation;

@end
