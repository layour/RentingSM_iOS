//
//  IUMRequestAttachment.h
//  IUMCore
//
//  Created by Chenly on 2016/11/10.
//  Copyright © 2016年 Yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const IUMRequestAttachmentKey;

@interface IUMRequestAttachment : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *mimeType;
@property (nonatomic, strong) NSData *data;

- (NSDictionary *)jsonDescription;

@end
