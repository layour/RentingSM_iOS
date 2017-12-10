//
//  IUMMediator+PhotoBrowser.h
//  Mediator
//
//  Created by Chenly on 2017/10/20.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import "Mediator.h"

@interface IUMMediator (PhotoBrowser)

- (UIViewController *)PhotoBrowser_imageBrowserWithDelegate:(id)delegate;
- (UIViewController *)PhotoBrowser_imageBrowserWithPhotos:(NSArray *)photos;
- (UIViewController *)PhotoBrowser_videoBrowserWithDelegate:(id)delegate;
- (UIViewController *)PhotoBrowser_videoBrowserWithPhotos:(NSArray *)photos;

@end
