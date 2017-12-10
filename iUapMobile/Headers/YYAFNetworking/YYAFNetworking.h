// YYAFNetworking.h
// Copyright (c) 2011–2016 Alamofire Software Foundation ( http://alamofire.org/ )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

//! Project version number for YYAFNetworking.
FOUNDATION_EXPORT double YYAFNetworkingVersionNumber;

//! Project version string for YYAFNetworking.
FOUNDATION_EXPORT const unsigned char YYAFNetworkingVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <YYAFNetworking/PublicHeader.h>

#import <Availability.h>
#import <TargetConditionals.h>

#ifndef _YYAFNETWORKING_
#define _YYAFNETWORKING_

#import <YYAFNetworking/YYAFURLSessionManager.h>
#import <YYAFNetworking/YYAFHTTPSessionManager.h>
#import <YYAFNetworking/YYAFURLRequestSerialization.h>
#import <YYAFNetworking/YYAFURLResponseSerialization.h>
#import <YYAFNetworking/YYAFSecurityPolicy.h>
#import <YYAFNetworking/YYAFNetworkReachabilityManager.h>

#endif /* _YYAFNETWORKING_ */
