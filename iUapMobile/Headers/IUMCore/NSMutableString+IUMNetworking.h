//
//  NSMutableString+IUMNetworking.h
//  IUMCore
//
//  Created by Chenly on 2016/11/1.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableString (IUMNetworking)

- (void)IUM_appendURLRequest:(NSURLRequest *)request;

@end
