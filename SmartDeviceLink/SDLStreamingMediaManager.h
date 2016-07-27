//
//  SDLStreamingDataManager.h
//  SmartDeviceLink-iOS
//
//  Created by Joel Fischer on 8/11/15.
//  Copyright (c) 2015 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>
@import VideoToolbox;

#import "SDLProtocolListener.h"

@class SDLAbstractProtocol;


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, SDLStreamingVideoError) {
    SDLStreamingVideoErrorHeadUnitNACK,
    SDLSTreamingVideoErrorInvalidOperatingSystemVersion,
    SDLStreamingVideoErrorConfigurationCompressionSessionCreationFailure,
    SDLStreamingVideoErrorConfigurationAllocationFailure,
    SDLStreamingVideoErrorConfigurationCompressionSessionSetPropertyFailure
};

typedef NS_ENUM(NSInteger, SDLStreamingAudioError) {
    SDLStreamingAudioErrorHeadUnitNACK
};

extern NSString *const SDLErrorDomainStreamingMediaVideo;
extern NSString *const SDLErrorDomainStreamingMediaAudio;

typedef void (^SDLStreamingStartBlock)(BOOL success, NSError *__nullable error);


@interface SDLStreamingMediaManager : NSObject <SDLProtocolListener>

- (instancetype)initWithProtocol:(SDLAbstractProtocol *)protocol;

/**
 *  This method will attempt to start a streaming video session. It will set up iOS's video encoder,  and call out to the head unit asking if it will start a video session.
 *
 *  @warning If this method is called on an 8.0 device, it will assert (in debug), or return a failure immediately to your block (in release).
 *
 *  @param startBlock A block that will be called with the result of attempting to start a video session
 */
- (void)startVideoSessionWithStartBlock:(SDLStreamingStartBlock)startBlock;

/**
 *  This method will stop a running video session if there is one running.
 */
- (void)stopVideoSession;

/**
 *  This method receives raw image data and will run iOS8+'s hardware video encoder to turn the data into a video stream, which will then be passed to the connected head unit.
 *
 *  @param imageBuffer A CVImageBufferRef to be encoded by Video Toolbox
 *
 *  @return Whether or not the data was successfully encoded and sent.
 */
- (BOOL)sendVideoData:(CVImageBufferRef)imageBuffer;

/**
 *  This method will attempt to start an audio session
 *
 *  @param startBlock A block that will be called with the result of attempting to start an audio session
 */
- (void)startAudioStreamingWithStartBlock:(SDLStreamingStartBlock)startBlock;

/**
 *  This method will stop a running audio session if there is one running.
 */
- (void)stopAudioSession;

/**
 *  This method receives PCM audio data and will attempt to send that data across to the head unit for immediate playback
 *
 *  @param pcmAudioData The data in PCM audio format, to be played
 *
 *  @return Whether or not the data was successfully sent.
 */
- (BOOL)sendAudioData:(NSData *)pcmAudioData;

/**
 *  The settings used in a VTCompressionSessionRef encoder. These will be verified when the video stream is started. Acceptable properties for this are located in VTCompressionProperties. If set to nil, the defaultVideoEncoderSettings will be used.
 *
 *  @warning Video streaming must not be connected to update the encoder properties. If it is running, issue a stopVideoSession before updating.
 */
@property (strong, nonatomic, null_resettable) NSDictionary* videoEncoderSettings;

@property (assign, nonatomic, readonly) BOOL videoSessionConnected;
@property (assign, nonatomic, readonly) BOOL audioSessionConnected;

/**
 *  Provides default video encoder settings used. 
 */
@property (strong, nonatomic, readonly) NSDictionary* defaultVideoEncoderSettings;


@end

NS_ASSUME_NONNULL_END
