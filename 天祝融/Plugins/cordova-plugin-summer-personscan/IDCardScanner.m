//
//  CardScanner.m
//  HelloCordova
//
//  Created by Chenly on 2017/5/15.
//
//

#import "IDCardScanner.h"
#import "SIDCard.h"

@interface IDCardScanner () <UINavigationControllerDelegate, UIImagePickerControllerDelegate>

@property (nonatomic, copy) NSString *callbackId;
@property (nonatomic, copy) NSString *authorizationCode;
@property (nonatomic, strong) SIDCard *sIDCard;

@end

@implementation IDCardScanner

- (void)pluginInitialize {
    self.authorizationCode = self.commandDelegate.settings[@"id_card_auth_code"];
}

#pragma mark - plugin method

- (void)personscan:(CDVInvokedUrlCommand *)command {
    
    [self.commandDelegate runInBackground:^{
        dispatch_async(dispatch_get_main_queue(), ^{
            UIImagePickerController *picker = [[UIImagePickerController alloc] init];
            picker.delegate = self;
            picker.sourceType = UIImagePickerControllerSourceTypeCamera;
            [self.viewController presentViewController:picker animated:YES completion:^{
                self.callbackId = command.callbackId;
            }];
        });
    }];
}

#pragma mark - <UIImagePickerControllerDelegate>

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info {
    
    // 初始化识别核心
    _sIDCard = [[SIDCard alloc] init];
    int code = [_sIDCard initSIDCard:self.authorizationCode nsReserve:@""];
    if (code == 0) {
        // 设置证件识别类型(0-自动、1-正面、2-背面)
        [self.sIDCard setRecognizeType:0];
    }
    else {
        [picker dismissViewControllerAnimated:YES completion:^{
            NSString *errorMsg = [NSString stringWithFormat:@"初始化失败!错误代码:%d", code];
            CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorMsg];
            [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
        }];
        return;
    }
    
    UIImage *image = info[UIImagePickerControllerEditedImage];
    if (!image) {
        image = info[UIImagePickerControllerOriginalImage];
    }
    {
        CGRect rect = CGRectZero;
        rect.size.width = 960.f;
        rect.size.height = rect.size.width * image.size.height / image.size.width;
        UIGraphicsBeginImageContext(rect.size);
        [image drawInRect:rect];
        image = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
    }
    
    [picker dismissViewControllerAnimated:YES completion:^{
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
            int code = [self.sIDCard recognizeSIDCardImage:image];
            dispatch_async(dispatch_get_main_queue(), ^(void) {
                if (code == 0) {
                    NSMutableDictionary *resultDic = [NSMutableDictionary dictionary];
                    if (self.sIDCard.getRecognizeType == 1) {
                        resultDic[@"name"] = self.sIDCard.nsName;
                        resultDic[@"sex"] = self.sIDCard.nsSex;
                        resultDic[@"nation"] = self.sIDCard.nsNation;
                        resultDic[@"birth_date"] = self.sIDCard.nsBirth;
                        resultDic[@"address"] = self.sIDCard.nsAddress;
                        resultDic[@"id"] = self.sIDCard.nsIDNum;
                    }
                    else {
                        resultDic[@"issuing_authority"] = self.sIDCard.nsIssuingAuthority;
                        resultDic[@"expiry_date"] = self.sIDCard.nsExpDate;
                    }
                    resultDic[@"imagePath"] = ({
                        NSData *data = UIImageJPEGRepresentation(image, 1);
                        NSString *tempDir = NSTemporaryDirectory();
                        NSString *fileName = [[NSUUID UUID].UUIDString stringByAppendingString:@".png"];
                        NSString *filePath = [tempDir stringByAppendingPathComponent:fileName];
                        if (![data writeToFile:filePath atomically:YES]) {
                            filePath = nil;
                        }
                        filePath;
                    });
                    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:resultDic];
                    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
                }
                else {
                    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"识别失败!"];
                    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
                }
                [self.sIDCard freeSIDCard];
                self.sIDCard = nil;
            });
        });
    }];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [picker dismissViewControllerAnimated:YES completion:nil];
}

@end
