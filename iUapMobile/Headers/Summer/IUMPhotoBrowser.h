//
//  IUMPhotoBrowser.h
//  IUMPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IUMPhoto.h"
#import "IUMPhotoProtocol.h"
#import "IUMCaptionView.h"

// Debug Logging
#if 0 // Set to 1 to enable debug logging
#define IUMLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define IUMLog(x, ...)
#endif

#define IUM_YYIMDownloadProgressNotification @"downloadProgressNotification"
#define IUM_YYIMDidDownloadCompleteNotification @"didDownloadCompleteNotification"

@class IUMPhotoBrowser;

@protocol IUMPhotoBrowserDelegate <NSObject>

- (NSUInteger)numberOfPhotosInPhotoBrowser:(IUMPhotoBrowser *)photoBrowser;
- (id <IUMPhoto>)photoBrowser:(IUMPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index;

@optional

- (id <IUMPhoto>)photoBrowser:(IUMPhotoBrowser *)photoBrowser thumbPhotoAtIndex:(NSUInteger)index;
- (IUMCaptionView *)photoBrowser:(IUMPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
- (NSString *)photoBrowser:(IUMPhotoBrowser *)photoBrowser titleForPhotoAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IUMPhotoBrowser *)photoBrowser didDisplayPhotoAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IUMPhotoBrowser *)photoBrowser actionButtonPressedForPhotoAtIndex:(NSUInteger)index;
- (BOOL)photoBrowser:(IUMPhotoBrowser *)photoBrowser isPhotoSelectedAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IUMPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index selectedChanged:(BOOL)selected;
- (void)photoBrowserDidFinishModalPresentation:(IUMPhotoBrowser *)photoBrowser;

- (void)photoBrowser:(IUMPhotoBrowser *)photoBrowser beginDownloadAtIndex:(NSInteger)index;

@end

@interface IUMPhotoBrowser : UIViewController <UIScrollViewDelegate, UIActionSheetDelegate>

@property (nonatomic, weak) IBOutlet id<IUMPhotoBrowserDelegate> delegate;

@property (nonatomic) BOOL displayDismissButton;
@property (nonatomic) BOOL zoomPhotosToFill;
@property (nonatomic) BOOL displayNavArrows;
@property (nonatomic) BOOL displayActionButton;
@property (nonatomic) BOOL displaySelectionButtons;
@property (nonatomic) BOOL alwaysShowControls;
@property (nonatomic) BOOL enableGrid;
@property (nonatomic) BOOL enableSwipeToDismiss;
@property (nonatomic) BOOL startOnGrid;
@property (nonatomic) BOOL autoPlayOnAppear;
@property (nonatomic) NSUInteger delayToHideElements;
@property (nonatomic, readonly) NSUInteger currentIndex;

// Customise image selection icons as they are the only icons with a colour tint
// Icon should be located in the app's main bundle
@property (nonatomic, strong) NSString *customImageSelectedIconName;
@property (nonatomic, strong) NSString *customImageSelectedSmallIconName;


// Init
- (id)initWithPhotos:(NSArray *)photosArray;
- (id)initWithDelegate:(id <IUMPhotoBrowserDelegate>)delegate;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setCurrentPhotoIndex:(NSUInteger)index;

// Navigation
- (void)showNextPhotoAnimated:(BOOL)animated;
- (void)showPreviousPhotoAnimated:(BOOL)animated;

// download progress
- (void)updateDownloadProgress:(float)progress atIndex:(NSInteger)index;
- (void)didDownloadCompleteAtIndex:(NSInteger)index;

- (void)setVideoURL:(NSURL *)url atIndex:(NSInteger)index;

@end
