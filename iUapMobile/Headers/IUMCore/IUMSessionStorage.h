//
//  IUMSessionStorage.h
//  IUMCore
//
//  Created by Chenly on 2017/3/11.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const IUMSessionStorageSharedAccount;

/**
 临时存储单次应用运行中的数据，通过 account 区分不同模块，避免互相干扰。。
 */
@interface IUMSessionStorage : NSObject

+ (instancetype)sharedInstance;

- (id)itemForAccount:(NSString *)accountName key:(NSString *)key;
- (NSDictionary *)itemsForAccount:(NSString *)accountName;
- (void)setItem:(id)item forAccount:(NSString *)accountName key:(NSString *)key;
- (void)setItems:(NSDictionary *)items forAccount:(NSString *)accountName;
- (void)removeItemForAccount:(NSString *)accountName key:(NSString *)key;
- (void)removeItemsForAccount:(NSString *)accountName;
- (void)clean;

@end
