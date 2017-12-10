//
//  NSDictionary+IUMNetworking.h
//  IUMCore
//
//  Created by Chenly on 2016/10/31.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (IUMNetworking)

- (NSString *)IUM_urlParamsString;
- (NSString *)IUM_jsonString;
- (NSArray *)IUM_transformedUrlParamsArray;

@end
