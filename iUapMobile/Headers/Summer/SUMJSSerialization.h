//
//  SUMJSSerializer.h
//  Summer
//
//  Created by Chenly on 2016/12/16.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SUMJSSerialization : NSObject

+ (NSString *)jsStringWithObject:(id)object;
+ (id)jsObjectForCallServiceWithResult:(id)result;

@end
