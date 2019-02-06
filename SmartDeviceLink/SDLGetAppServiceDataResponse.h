//
//  SDLGetAppServiceDataResponse.h
//  SmartDeviceLink
//
//  Created by Nicole on 2/6/19.
//  Copyright © 2019 smartdevicelink. All rights reserved.
//

#import "SDLRPCResponse.h"
#import "SDLAppServiceData.h"

NS_ASSUME_NONNULL_BEGIN

/*
 *  This response includes the data that is requested from the specific service.
 */
@interface SDLGetAppServiceDataResponse : SDLRPCResponse

/**
 *  Contains all the current data of the app service.
 *
 *  SDLAppServiceData, Required
 */
@property (strong, nonatomic) SDLAppServiceData *serviceData;

@end

NS_ASSUME_NONNULL_END
