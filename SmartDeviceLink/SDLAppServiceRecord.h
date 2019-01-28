//
//  SDLAppServiceRecord.h
//  SmartDeviceLink
//
//  Created by Nicole on 1/25/19.
//  Copyright © 2019 smartdevicelink. All rights reserved.
//

#import "SDLRPCRequest.h"
#import "SDLAppServiceManifest.h"

NS_ASSUME_NONNULL_BEGIN

/*
 *  This is the record of an app service publisher that the module has. It should contain the most up to date information including the service's active state.
 */
@interface SDLAppServiceRecord : SDLRPCStruct

/**
 *  A unique ID tied to this specific service record. The ID is supplied by the module that services publish themselves.
 *
 *  String, Required
 */
@property (strong, nonatomic) NSString *serviceId;

/**
 *  Manifest for the service that this record is for.
 *
 *  SDLAppServiceManifest, Required
 */
@property (strong, nonatomic) SDLAppServiceManifest *serviceManifest;

/**
 *  If true, the service is published and available. If false, the service has likely just been unpublished, and should be considered unavailable.
 *
 *  Boolean, Required
 */
@property (strong, nonatomic) NSNumber<SDLBool> *servicePublished;

/**
 *  If true, the service is the active primary service of the supplied service type. It will receive all potential RPCs that are passed through to that service type. If false, it is not the primary service of the supplied type. See servicePublished for its availability.
 *
 *  Boolean, Required
 */
@property (strong, nonatomic) NSNumber<SDLBool> *serviceActive;

@end

NS_ASSUME_NONNULL_END
