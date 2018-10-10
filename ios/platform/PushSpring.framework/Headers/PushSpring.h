//
//  PushSpring.h
//  PushSpringSample
//
//  Copyright (c) 2016 PushSpring, Inc. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for PushSpring.
FOUNDATION_EXPORT double PushSpringVersionNumber;

//! Project version string for PushSpring.
FOUNDATION_EXPORT const unsigned char PushSpringVersionString[];

#define PS_CLIENT_VERSION              @"iOS_4.0.3"      // The version of this library


// predefined, reserved event names
#define PS_EVENT_SESSION @"ps_session"
#define PS_EVENT_CLVINCREASE @"ps_clvincrease"

// gender
#define PS_GENDER_FEMALE @"f"
#define PS_GENDER_MALE @"m"

// Info.plist keys
#define PS_PLIST_APIKEY @"PushSpringAPIKey"

NS_ASSUME_NONNULL_BEGIN

// Logging macro
#define PSLog(message, ...)if ([[PushSpring sharedPushSpring] loggingEnabled]) NSLog(message, ##__VA_ARGS__)

@interface PushSpring : NSObject

@property (readonly, nullable) NSString *apiKey;
@property (nonatomic) BOOL loggingEnabled;

// Set this to YES to suspend all network operations and NO to resume them. This allows finer grained
// control over when the SDK uses the network. Call this before any of the initialization methods to
// start suspended.
// Default is NO
@property (getter=isSuspended) BOOL suspended;

+ (PushSpring *) sharedPushSpring;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions andApiKey:(NSString *)apiKey DEPRECATED_MSG_ATTRIBUTE("Method deprecated in PushSpring SDK v4.0.0");

// Put the PushSpring API key in Info.plist under 'PushSpringAPIKey'
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

// use this if you want to record an internal customer identifier (user id etc) for later matching with your own internal data
- (void) setCustomerId:(NSString *)customerId;
- (void) setCustomerBirthYear:(NSNumber *)birthYear;
- (void) setCustomerGender:(NSString *)gender;
- (void) setLatitude:(double)latitude andLongitude:(double)longitude;
- (void) setAvailableLocationInfo;
- (void) increaseCustomerLifetimeValue:(NSNumber *)value;
- (void) recordEvent:(NSString *)eventName;
- (void) recordEvent:(NSString *)eventName incrementBy:(NSNumber *)value;
- (void) getCustomerInsights:(void (^)(NSDictionary * __nullable calculatedAttributes))completionHandler;
@end

NS_ASSUME_NONNULL_END
