//
//  IUMMediator+Summer.h
//  ModuleCategories
//
//  Created by Chenly on 2017/2/23.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import "Mediator.h"

extern NSString * const SummerSettingKeyTintColor;
extern NSString * const SummerSettingKeySelectedTintColor;

@interface IUMMediator (Summer)

// VC
- (UIViewController *)Summer_launchViewController;
- (UIViewController *)Summer_viewControllerWithParams:(id)params;
- (UIViewController *)Summer_viewControllerWithClass:(NSString *)className params:(NSDictionary *)params;
- (void)Summer_pushViewControllerWithParams:(id)params;
- (void)Summer_pushViewController:(UIViewController *)viewController;
- (UIViewController *)Summer_topViewController;
- (UIViewController *)Summer_viewControllerWithTag:(NSString *)tag;
- (UIViewController *)Summer_viewControllerWithTag:(NSString *)tag appid:(NSString *)appid;

// Event Center
- (void)Summer_addListener:(id)listener forEvent:(NSString *)event handler:(NSString *)handler;
- (void)Summer_removeListener:(id)listener forEvent:(NSString *)event;
- (void)Summer_removeListener:(id)listener;
- (void)Summer_trigger:(id)listener event:(NSString *)event object:(id)object;

- (NSDictionary *)Summer_allSettings;

@end
