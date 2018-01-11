/*
 * YNCSDKCamera.h
 * YUNEEC_SDK_IOS
 *
 * Copyright @ 2016 Yuneec.
 * All rights reserved.
 *
*/

#import <Foundation/Foundation.h>

@class YNCCameraSettings;

/**
 Data type for completion blocks for camera commands that contain error results, if any.
 */
typedef void (^YNCCameraCompletion)(NSError *error);

/**
 Data type for the different color modes.
 */
typedef NS_ENUM (NSInteger, YNCCameraColorMode) {
    /**
     Neutral mode
     */
    YNCCameraColorModeNeutral = 0,
    /**
     Enhanced mode
     */
    YNCCameraColorModeEnhanced,
    /**
     Night mode
     */
    YNCCameraColorModeNight,
    /**
     Unprocessed mode. In this mode, no additional color processing and no artificial sharpening will be performed.
     */
    YNCCameraColorModeUnprocessed,
    /**
     Unknown color mode
     */
    YNCCameraColorModeUnknown
};

/**
 Data type for completion blocks for color mode camera setting that contain error results, if any.
 */
typedef void (^YNCColorModeCompletion)(YNCCameraColorMode colorMode, NSError *error);

/**
 This class provides methods to set and get camera settings.
 */
@interface YNCSDKCameraSettings: NSObject
/**
 * Get color mode
 *
 * @param completion the callback function after completion
 */
+ (void)getColorModeWithCompletion:(YNCColorModeCompletion) completion;

/**
 * Set color mode
 * @param colorMode the color mode to be set
 * @param completion the callback function after completion
 */
+ (void)setColorMode:(YNCCameraColorMode)colorMode WithCompletion:(YNCColorModeCompletion) completion;

@end

/**
 This class provides methods for performing camera actions.
 */
@interface YNCSDKCamera : NSObject

/**
 Triggers the take photo command.

 @param completion the callback function after completion
 */
+ (void)takePhotoWithCompletion:(YNCCameraCompletion)completion;

/**
 Starts video recording.

 @param completion the callback function after completion
 */
+ (void)startVideoWithCompletion:(YNCCameraCompletion)completion;

/**
 Stops video recording.

 @param completion the callback function after completion
 */
+ (void)stopVideoWithCompletion:(YNCCameraCompletion)completion;

/**
 Starts taking photos in burst mode (every n intervals).

 @param intervalS the interval (in seconds) between photos in burst mode
 @param completion the callback function after completion
 */
+ (void)startPhotoInterval:(double)intervalS Completion:(YNCCameraCompletion)completion;

/**
 Stops taking photos in burst mode.

 @param completion the callback function after completion
 */
+ (void)stopPhotoIntervalWithCompletion:(YNCCameraCompletion)completion;

@end
