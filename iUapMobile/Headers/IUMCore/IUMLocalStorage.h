//
//  IUMLocalStorage.h
//  IUMCore
//
//  Created by Chenly on 2017/3/10.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const IUMLocalStorageSharedAccount;

/**
 持久化本地存储，通过 account 区分不同模块，避免互相干扰。
 */
@interface IUMLocalStorage : NSObject

+ (instancetype)sharedInstance;

- (id)itemForAccount:(NSString *)accountName key:(NSString *)key;
- (NSDictionary *)itemsForAccount:(NSString *)accountName;
- (BOOL)setItem:(NSObject<NSCoding> *)item forAccount:(NSString *)accountName key:(NSString *)key;
- (BOOL)setItems:(NSDictionary *)items forAccount:(NSString *)accountName;
- (BOOL)removeItemForAccount:(NSString *)accountName key:(NSString *)key;
- (BOOL)removeItemsForAccount:(NSString *)accountName;
- (void)clean;

@end
