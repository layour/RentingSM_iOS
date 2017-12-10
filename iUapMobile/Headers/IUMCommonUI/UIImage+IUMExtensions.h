//
//  UIImage+IUMExtensions.h
//  IUMUIComponents
//
//  Created by Chenly on 2017/2/21.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Size)

+ (UIImage *)scaleImage:(UIImage *)image toSize:(CGSize)newSize;

@end

@interface UIImage (Color)

+ (instancetype)imageWithColor:(UIColor *)color size:(CGSize)size;
+ (instancetype)imageWithGradientColors:(NSArray<UIColor *> *)colors size:(CGSize)size;
- (instancetype)imageRenderWithColor:(UIColor *)color;

@end

@interface UIImage (FixOrientation)

- (UIImage *)fixOrientation;

@end
