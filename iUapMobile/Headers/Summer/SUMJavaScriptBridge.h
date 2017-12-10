//
//  SUMJavaScriptBridge.h
//  Summer
//
//  Created by Chenly on 2017/3/4.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const SUMJavaScriptBridgeName;

@interface SUMJavaScriptBridge : NSObject

+ (instancetype)sharedInstance;

- (NSString *)titleInWebView:(id)webView;
- (BOOL)webViewCanGoBack:(id)webView;
- (void)webViewGoBack:(id)webView;
    
- (void)evaluateJavaScript:(NSString *)script
                 inWebView:(id)webView
                completion:(void (^)(id, NSError *error))completion;

- (void)evaluateJavaScriptWithFunction:(NSString *)function object:(id)object inWebView:(id)webView;

- (NSString *)scriptWithFunction:(NSString *)function object:(id)object;

// 在 Javascript 注入 SummerBridge 中
- (void)injectBridgeWithName:(NSString *)name inWebView:(id)webView owner:(id)owner;

- (void)releaseWebview:(id)webView;

@end
