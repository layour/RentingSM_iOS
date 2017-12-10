//
//  SummerWebAppManager.h
//  Summer
//
//  Created by Chenly on 2017/11/23.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SummerWebAppManager : NSObject

+ (instancetype)shared;

- (NSString *)wwwFolderForApp:(NSString *)appid;
- (NSString *)versionForApp:(NSString *)appid;

- (void)installWebAppWithURL:(NSString *)URLString
                       appid:(NSString *)appid
                     version:(NSString *)version
                 incremental:(BOOL)incremental
                    progress:(void (^)(NSProgress *progress))progress
                  completion:(void (^)(BOOL success, id result, NSError *error))completion;

- (BOOL)uninstallWebApp:(NSString *)appid error:(NSError **)error;

@end
