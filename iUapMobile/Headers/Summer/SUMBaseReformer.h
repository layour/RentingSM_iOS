//
//  SUMBaseReformer.h
//  Summer
//
//  Created by Chenly on 2017/4/20.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SUMViewControllerProtocol.h"

@interface SUMBaseReformer : NSObject <SUMViewControllerReformer>

@property (nonatomic, assign) BOOL viewEmbedded;

- (NSArray *)effectiveKeys;
- (NSDictionary *)keysMapper;
- (void)setupDefaultValues:(NSMutableDictionary *)params;
- (NSDictionary *)reformParamsWithDefaultValues:(NSDictionary *)params;
- (NSDictionary *)reformParams:(NSDictionary *)params;

@end
