////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2014 by SafeNet, Inc., (collectively herein  "SafeNet"), Belcamp, Maryland
// All Rights Reserved
// The SafeNet software that accompanies this License (the "Software") is the property of
// SafeNet, or its licensors and is protected by various copyright laws and international
// treaties.
// While SafeNet continues to own the Software, you will have certain non-exclusive,
// non-transferable rights to use the Software, subject to your full compliance with the
// terms and conditions of this License.
// All rights not expressly granted by this License are reserved to SafeNet or
// its licensors.
// SafeNet grants no express or implied right under SafeNet or its licensors’ patents,
// copyrights, trademarks or other SafeNet or its licensors’ intellectual property rights.
// Any supplemental software code, documentation or supporting materials provided to you
// as part of support services provided by SafeNet for the Software (if any) shall be
// considered part of the Software and subject to the terms and conditions of this License.
// The copyright and all other rights to the Software shall remain with SafeNet or
// its licensors.
// For the purposes of this Agreement SafeNet, Inc. includes SafeNet, Inc and all of
// its subsidiaries.
//
// Any use of this software is subject to the limitations of warranty and liability
// contained in the end user license.
// SafeNet disclaims all other liability in connection with the use of this software,
// including all claims for  direct, indirect, special  or consequential regardless
// of the type or nature of the cause of action.
////////////////////////////////////////////////////////////////////////////////////////////

/*
 *  @File   :   MPIncludes.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      Main header file to be included in Applications, which are using MobilePASS SDK
 */

#ifndef __MP_INCLUDES_H__
#define __MP_INCLUDES_H__


/* Token Modes */
#define     EVENT_SYNCHRONOUS           @"Event Synchronous"
#define     TIME_SYNCHRONOUS            @"Time Synchronous"
#define     CHALLENGE_RESPONSE          @"Challenge Response"
#define     MULTI_HOST                  @"Multi-Host"

/* Token States */
#define     INSTALLED_STATE             1
#define     PRE_INIT_STATE              2
#define     READY_STATE                 3
#define     UNKNOWN_TOKEN_STATE         4
#define     CORRUPTED_TOKEN_STATE       5

/* Keys defined for Auto-Enrollment */
#define     MP_KEY_PORTAL_URL           @"MP_KEY_PORTAL_URL"
#define     MP_KEY_USERNAME             @"MP_KEY_USERNAME"
#define     MP_KEY_PASSWORD             @"MP_KEY_PASSWORD"
#define     MP_KEY_ACCEPT_CERTIFICATES  @"MP_KEY_ACCEPT_CERTIFICATES"
#define     MP_KEY_TOKEN_NAME           @"MP_KEY_TOKEN_NAME"
#define     MP_KEY_SOFTPIN              @"MP_KEY_SOFTPIN"
#define     MP_KEY_CONNECTION_TIMEOUT   @"MP_KEY_CONNECTION_TIMEOUT"
#define     MP_KEY_CERTIFICATES         @"MP_KEY_CERTIFICATES"
#define     MP_KEY_ENABLE_CERTIFICATE_PINNING           @"MP_KEY_ENABLE_CERTIFICATE_PINNING"
#define     MP_KEY_ALLOW_HOSTNAME_MISMATCH              @"MP_KEY_ALLOW_HOSTNAME_MISMATCH"
#define     MP_KEY_ALLOW_SELF_SIGNED_CERT               @"MP_KEY_ALLOW_SELF_SIGNED_CERT"

#define     MP_MIN_SOFT_PIN_LEN         3
#define     MP_MAX_SOFT_PIN_LEN         16

#define     ENROLLMENT_BASE64_MAX_LEN       2048
#define     ENROLLMENT_URL_MAX_LEN          2048

#define     HTTPS_PREFIX                                @"https://"

#define     USER_ID_MAX_LEN                 128
#define     USER_PSWD_MAX_LEN               128
#define     SOFT_PIN_MAX_LEN                4

#endif //__MP_INCLUDES_H__
