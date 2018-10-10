//
//  GJPGLXAPI.h
//  Pods
//
//  Created by Gabriel Jensen on 11/30/16.
//
//

#import <Foundation/Foundation.h>

@interface GJPGLXAPI : NSObject

+ (instancetype)sharedInstance;


- (void) startWithApiKey :(NSString*) apiKey;
- (void) startWithApiKey :(NSString*) apiKey isLocationInForegroundOnly: (BOOL) hasClientSpecifiedForegroundOnlyLocation; //keeping 'isLocationInForegroundOnly' for backward compatibility, but it's a client setting
- (void) startWithApiKey :(NSString*) apiKey useBeaconsInSpace:(BOOL) useBeaconsInSpace;
- (void) startWithApiKey :(NSString*) apiKey usePushSpring:(BOOL) usePushSpring;
- (void) startWithApiKeyAndNoLocation :(NSString*) apiKey;
- (void) setEmailAddress :(NSString*) email;
- (void) setEmailAddress:(NSString *) email name:(NSString*) name phoneNumber:(NSString*) phoneNumber;
- (void) debugSetSendBatchWhenLocationReceived : (BOOL) isSending;
- (void) startPartnerSdksRequiringLocationPermission;
- (void) stopBackgroundLocation;
- (void) startBackgroundLocation;

- (void) gdprAssumeUserRejected; // Used in case where dev doesn't care about EU and doesn't want dialog. Will assume user has said NO in EU.
- (void) gdprPassConsentValue: (int)consentVal apiKey:(NSString *)apiKey;
- (void) gdprShowConsentDialog;
- (void) debugGdprPretendToBeInEngland;


+ (void) debugLocal: (NSString*) lineToAdd;

@property (nonatomic) NSString *apiKey;
@property (nonatomic) BOOL isDebugMode;
@property (nonatomic) NSString *debugApiVersionSuffix; // Used to differentiate between tests versions.
@property (nonatomic) BOOL recordLatestToUserDefaults;
@property (nonatomic) BOOL hasClientSpecifiedForegroundOnlyLocation;

@end
