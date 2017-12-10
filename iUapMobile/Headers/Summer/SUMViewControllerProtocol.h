//
//  SUMViewControllerProtocol.h
//  Summer
//
//  Created by Chenly on 2017/4/6.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#ifndef SUMViewControllerProtocol_h
#define SUMViewControllerProtocol_h

#import <UIKit/UIKit.h>

#ifndef SUMImplementation

#define SUMImplementation(ClassName) \
_Pragma("clang diagnostic ignored \"-Wprotocol\"") \
@implementation ClassName \
@synthesize appid = _appid; \
@synthesize identifier = _identifier; \
@synthesize viewid = _viewid; \
@synthesize pageParam = _pageParam; \
@synthesize reformer = _reformer; \
_Pragma("clang diagnostic pop") \

#endif

static NSString * const SUMTagComponentSeparatorChar = @"|";
static NSString * const SUMViewControllerTypeDefault = @"cordova";

#define Summer_Tag(components, ...) \
    [[NSArray arrayWithObjects:components, __VA_ARGS__, nil] componentsJoinedByString:SUMTagComponentSeparatorChar]

@class SUMSegue;

@protocol SUMEmbeddable;
@protocol SUMViewControllerReformer;

// ========================== <SUMViewController> ==============================

@protocol SUMViewController <NSObject>

@required

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *viewid;
@property (nonatomic, copy) id pageParam;   // 传递页面参数
@property (nonatomic, strong) id<SUMViewControllerReformer> reformer;

- (instancetype)initWithParams:(NSDictionary *)params reformer:(id<SUMViewControllerReformer>)reformer;
- (void)setParameters:(NSDictionary *)params;

- (id)pageInfo;

@optional

- (instancetype)initWithParams:(NSDictionary *)params;

@property (nonatomic, readonly) BOOL shouldViewPreload;
@property (nonatomic, copy) void (^preloadCompletion)(UIViewController<SUMEmbeddable> *);

- (void)evaluateJavaScript:(NSString *)script completion:(void (^)(id, NSError *error))completion;

- (void)embedViewController:(UIViewController<SUMEmbeddable> *)viewController;

@end

// ======================== <SUMViewControllerReformer> ========================

@protocol SUMViewControllerReformer <NSObject>

@property (nonatomic, assign) BOOL viewEmbedded;
- (NSDictionary *)reformParams:(NSDictionary *)params;
- (NSDictionary *)reformParamsWithDefaultValues:(NSDictionary *)params;

@end

// ======================== <SUMViewControllerGenerator> =======================

@protocol SUMViewControllerGenerator <NSObject>

@required
- (UIViewController<SUMViewController> *)viewControllerWithArguments:(NSDictionary *)arguments;

@optional
@property (nonatomic, assign) BOOL viewEmbedded;

@end

// ============================== <SUMEmbeddable> ==============================

/**
 SUMEmbeddable 允许被嵌入，如作为 Frame
 */
@protocol SUMEmbeddable <SUMViewController>

@property (nonatomic, assign) BOOL embeded;
@property (nonatomic, weak) UIViewController<SUMViewController> *embedingViewController;

- (void)unembedFromContainner;

@optional

@property (nonatomic, assign) BOOL fixedPosition;   // 忽略 position，由 containner 确定位置
@property (nonatomic, copy) NSDictionary *position;

- (void)didEmbededIntoViewController:(UIViewController<SUMViewController> *)viewController;

@end

#endif /* SUMViewControllerProtocol_h */
