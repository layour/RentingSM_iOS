//
//  IUMExtension.h
//  Mediator
//
//  Created by Chenly on 2017/3/1.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#ifndef IUMExtension_h
#define IUMExtension_h

#import <Foundation/Foundation.h>

@protocol IUMExtension <NSObject, NSCopying>

@property (nonatomic, copy) NSDictionary *params;

- (id)sender;
- (NSString *)action;
- (BOOL)shouldCallback;

@end

@interface NSObject (IUMExtension)

- (void)retainByObject:(id)object;

@end

#endif /* IUMExtension_h */
