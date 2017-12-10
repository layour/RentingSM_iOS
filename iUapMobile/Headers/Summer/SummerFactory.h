//
//  SummerFactory.h
//  Summer
//
//  Created by Chenly on 2017/4/9.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SUMViewControllerProtocol.h"

@interface SummerFactory : NSObject

+ (void)registerGenerator:(Class)generatorClass forType:(NSString *)type;

+ (instancetype)factory;
- (UIViewController<SUMViewController> *)createViewControllerWithArguments:(NSDictionary *)arguments;

@end
