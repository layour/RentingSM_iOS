//
//  SIDCard.h
//  SIDCard
//
//  Created by ocrgroup on 15/12/22.
//  Copyright (c) 2015年 ocrgroup. All rights reserved.
//


#import <UIKit/UIKit.h>

@interface SIDCard : NSObject

//二代证正面识别结果

/** 名字 */
@property(copy, nonatomic) NSString *nsName;
/** 性别 */
@property(copy, nonatomic) NSString *nsSex;
/** 民族 */
@property(copy, nonatomic) NSString *nsNation;
/** 出生日期 */
@property(copy, nonatomic) NSString *nsBirth;
/** 地址 */
@property(copy, nonatomic) NSString *nsAddress;
/** 身份证号 */
@property(copy, nonatomic) NSString *nsIDNum;

//二代证背面识别结果

/** 签发机关 */
@property(copy, nonatomic) NSString *nsIssuingAuthority;
/** 有效期限 */
@property(copy, nonatomic) NSString *nsExpDate;

/** 头像 */
@property(strong, nonatomic) UIImage *imageHead;
/** 全图(裁切后) */
@property(strong, nonatomic) UIImage *imageCard;

//初始化核心
-(int)initSIDCard:(NSString *)nsUserID nsReserve:(NSString *) nsReserve;

/**
 设置证件识别类型

 @param nType 0-自动、1-正面、2-背面
 @return 是否设置成功 0为成功
 */
-(int) setRecognizeType:(int)nType;

/**
 预览识别
 
 @param buffer 缓冲区
 @param width buffer宽度
 @param height buffer高度
 @return 是否识别成功 0为成功
 */
-(int) recognizeSIDCard:(UInt8 *)buffer Width:(int)width Height:(int)height;

/**
 拍照识别
 
 @param image 照片
 @return 是否识别成功 0为成功
 */
-(int) recognizeSIDCardPhoto:(UIImage *)image;

/**
 导入识别
 
 @param image 照片
 @return 是否识别成功 0为成功
 */
-(int) recognizeSIDCardImage:(UIImage *)image;

/**
 图像检四边
 
 @param image 图像
 @param bLastDetect 是否是最后一帧
 @param cornerArray 存储四个角点的数组
 @return 是否检边成功
 */
-(int)detectSIDCardSideWithImage:(UIImage *)image lastDetect:(bool)bLastDetect corner:(NSMutableArray *)cornerArray;

/**
 识别
 
 @param image 图片
 @param corner 存储四个角的数组
 @return 是否识别成功
 */
- (int)recognizeSIDCard:(UIImage *)image corners:(NSMutableArray *)corner;

/**
 获取证件是正面还是背面

 @return 1-正面、2-背面
 */
-(int) getRecognizeType;

/**
 获取证件方向

 @return 0-0度 1-180度
 */
-(int) getIDCardDirection;

/**
 是否为复印件

 @return 0 不是、 1 是、 -1 错误
 */
-(int) SIDCardCheckIsCopy;

/**
 释放核心
 */
- (void) freeSIDCard;

@end
