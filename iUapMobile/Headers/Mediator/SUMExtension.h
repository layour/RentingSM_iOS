//
//  SUMExtension.h
//  ModuleCategories
//
//  Created by Chenly on 2017/3/1.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#ifndef SUMExtension_h
#define SUMExtension_h

#import "IUMExtension.h"

@protocol SUMExtension <IUMExtension>

- (UIViewController *)sum_container;

@optional
- (void)evaluateJavaScriptCallbackWithObject:(id)result;
- (void)evaluateJavaScriptErrorWithObject:(id)result;
- (void)evaluateJavaScriptWithFunction:(NSString *)function object:(id)object;

@end

#endif /* SUMExtension_h */
