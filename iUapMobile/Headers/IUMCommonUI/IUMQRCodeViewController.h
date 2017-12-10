//
//  IUMQRCodeViewController.h
//  EMMKitDemo
//
//  Created by Chenly on 16/7/5.
//  Copyright © 2016年 Little Meaning. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IUMQRCodeViewController;

typedef NS_ENUM(NSUInteger, IUMQRCodeScannerType) {
    IUMQRCodeScannerTypeBoth = 0,
    IUMQRCodeScannerTypeQRCode,
    IUMQRCodeScannerTypeBarCode,
};

@protocol IUMQRCodeViewControllerDelegate <NSObject>

- (void)ium_QRCodeViewController:(IUMQRCodeViewController *)viewController didFinishScanningQRCode:(NSString *)code;

@end

@interface IUMQRCodeViewController : UIViewController

@property (nonatomic, weak) id<IUMQRCodeViewControllerDelegate> delegate;
@property (nonatomic, assign) IUMQRCodeScannerType scannerType;
    
- (void)startScanning;

@end
