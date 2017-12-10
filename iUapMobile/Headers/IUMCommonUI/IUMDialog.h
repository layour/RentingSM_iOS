//
//  IUMDialog.h
//  友文化
//
//  Created by Chenly on 2017/7/11.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, IUMDialogMode) {
    IUMDialogModeToast,
};

typedef NS_ENUM(NSUInteger, IUMDialogSite) {
    IUMDialogSiteCenter = 0,
    IUMDialogSiteTop,
    IUMDialogSiteBottom,
};

@interface IUMDialog : NSObject

+ (void)toast:(NSString *)message;
+ (void)toast:(NSString *)message duration:(NSTimeInterval)duration;
+ (void)toastInView:(UIView *)view message:(NSString *)message site:(IUMDialogSite)site offset:(CGFloat)offset duration:(NSTimeInterval)duration;

@end
