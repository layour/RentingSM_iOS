//
//  CDVUPushService.m
//  CloudHR
//
//  Created by admin on 2017/4/11.
//  Copyright © 2017年 Yonyou. All rights reserved.
//

#import "CDVSummerAPMPlugin.h"
#import <IUMSummerAPM/IUMSummerAPM.h>

static NSString *const _Version = @"3.0.0";
@implementation CDVSummerAPMPlugin

- (void)insertAction:(CDVInvokedUrlCommand*)command{
    NSString *actionID = [command.arguments objectAtIndex:0];
    NSString *actionParam = [command.arguments objectAtIndex:1];
    
    if(actionID && actionParam){
        [[IUMAPM defaultIUMAPM] logEvent:actionID eventParams:actionParam];
    }
}

- (void)getPluginVersion:(CDVInvokedUrlCommand *)command{
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:@{@"result":_Version}];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end
