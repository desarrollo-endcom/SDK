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
 *  @File   :   MPLibSTConst.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      Contains constants SDK
 */


#ifndef __MP_LIBSTCONST_H__
#define __MP_LIBSTCONST_H__

#import <Foundation/Foundation.h>


/**
 * A token has been obfuscated using a Mac address will have a TOKEN_NEEDS_WIFI fixed prefix
 */
#define TOKEN_NEEDS_WIFI    @"Token needs WIFI ON, last used: "
	
/**
 * A token that cannot be parsed will have a TOKEN_UNKNOWN fixed prefix
 */
#define TOKEN_UNKNOWN       @"Token unknown, last used: "
    
/**
 * Token mode - Event synchronous
 */
#define TOKEN_MODE_EVENT_SYNCHRONOUS    @"EVENT_SYNCHRONOUS"
	
/**
 * Token mode - Time synchronous
 */
#define TOKEN_MODE_TIME_SYNCHRONOUS     @"TIME_SYNCHRONOUS"
	
/**
 * Token mode - Challenge Response
 */
#define TOKEN_MODE_CHALLENGE_RESPONSE   @"CHALLENGE_RESPONSE"
	
/**
 * Policy string L1
 */
#define LEVEL_1                         @"Level 1"
	
/**
 * Policy string L2
 */
#define LEVEL_2                         @"Level 2"
	
/**
 * Policy string L3
 */
#define LEVEL_3                        @"Level 3"
	
/**
 * Policy string L4
 */
#define LEVEL_4                         @"Level 4"

/**
 * Policy string L5
 */
#define LEVEL_5                         @"Level 5"

/**
 * Policy string L6
 */
#define LEVEL_6                         @"Level 6"

/**
 * Unknown token
 */
#define TOKEN_UNKNOWN_NAME              @"Unknown token"

/**
 * Corrupted token
 */
#define TOKEN_CORRUPTED_NAME            @"Corrupted token"


//Errors

/**
 * Token state installed
 */
#define TOKEN_STATE_INSTALLED               1
	
/**
 * Token state in process
 */
#define TOKEN_STATE_IN_PROCESS              2
    
/**
 * Token state operational ready
 */
#define TOKEN_STATE_READY                   3
    
    
#define TOKEN_STATE_UNAVAILABLE_NEED_WIFI   4
    
    
#define TOKEN_STATE_UNAVAILABLE_UNKNOWN     5
    
    
/**
 * Integer value denotes True
 */
#define  VAL_TRUE           1
    
/**
 * Integer value denotes False
 */
#define VAL_FALSE           0

/**
 * Maximum length of base64 enrollment string
 */
#define  ENROLLMENT_BASE64_MAX_LEN      2048

/**
 * Maximum length of regular enrollment string
 */
#define ENROLLMENT_URL_MAX_LEN          2048

/**
 * Maximum number of tokens
 */
#define SDK_MAX_TOKEN_CAPACITY         256

/**
 * Server-side PIN minimum length
 */
#define     SERVER_SIDE_PIN_MIN_LEN     3

/**
 * Server-side PIN maximum length
 */
#define     SERVER_SIDE_PIN_MAX_LEN     16

/**
 * Different maximal string lengths
 */
#define     MAX_STR_LENGTH1             4096
#define     MAX_STR_LENGTH2             2048
#define     MAX_STR_LENGTH3             8192
    
/**
 * String parameter definitions, returned by mp_getTokenParamStr function
 */
typedef NS_ENUM(NSUInteger, MPSPARAM)
{
   	/**
   	 * ACTIVATION_CODE  - activation code - returned by mp_generateActivationCode function
   	 */
	ACTIVATION_CODE,
	
	/**
     * AUTO_ENROLL_PASSWORD - enroll password string - input to mp_performAutoEnrollment function
     */
	AUTO_ENROLL_PASSWORD,
	
	/**
     * AUTO_ENROLL_SOFT_PIN - enrollment OTP PIN string - input to mp_performAutoEnrollment function (when needed)
     */
	AUTO_ENROLL_SOFT_PIN,
	
	/**
     * AUTO_ENROLL_TIMEOUT - enrollment timeout string - input to mp_performAutoEnrollment function (as an integer e.g. "45")
     */
	AUTO_ENROLL_TIMEOUT,
	
	/**
     * AUTO_ENROLL_TOKEN_NAME - enrollment token name String - input to mp_performAutoEnrollment function
     */
	AUTO_ENROLL_TOKEN_NAME,
		
	/**
   	 * AUTO_ENROLLL_URL - URL string - input to mp_performAutoEnrollment function
   	 */
	AUTO_ENROLLL_URL,
		
    /**
     * AUTO_ENROLL_USER_ID - user ID string - input to mp_performAutoEnrollment function
     */
    AUTO_ENROLL_USER_ID,
	
	/**
     * BASE64_ENROLL_STR - base-64 string - returned by mp_getBase64EnrollString
     */
	BASE64_ENROLL_STR,
	
	/**
	 * OTP_VAL - OTP string returned by mp_genOTP function
	 */
	OTP_VAL,
		
    /**
     * TOKEN_MODE - token mode string - returned by mp_getTokenParamStr function
     */
	TOKEN_MODE,
	
	/**
     * TOKEN_NAME - token name string - returned by mp_getTokenParamStr function
     */
	TOKEN_NAME,
		
	/**
     * TOKEN_POLICY_LEVEL - token policy level string - returned by mp_getTokenParamStr function
     */
	TOKEN_POLICY_LEVEL,
		
	/**
     * TOKEN_POLICY_STR - token policy string - returned by mp_getTokenParamStr function
     */
	TOKEN_POLICY_STR,
	
	/**
     * TOKEN_SERIAL - token serial string - returned by mp_getTokenParamStr function
     */
	TOKEN_SERIAL,
    
    /**
     * MPSPARAM_UNKNOWN - unknown parameter
     */
	MPSPARAM_UNKNOWN
};

/**
 * String parameter definitions, returned by mp_getSDKParamStr function
 */
typedef NS_ENUM(NSUInteger, MPSSDKPARAM)
{
   	/**
   	 * SDK_VERSION_STR - the SDK version returned by
   	 */
    SDK_VERSION_STR,
    
    /**
     * MPSSDKPARAM_UNKNOWN - unknown parameter
     */
	MPSSDKPARAM_UNKNOWN
};
    
/**
 * Integer parameter definitions, returned by mp_getTokenParamInt function
 */
typedef NS_ENUM(NSUInteger, MPIPARAM)
{
    /**
	 * PIN_ATTACK_COUNT - PIN verification failure count
	 */
	PIN_ATTACK_COUNT,
	
	/**
	 * PIN_MAX_ATTACK_COUNT - max PIN verification failures before token is erased
	 */
	PIN_MAX_ATTACK_COUNT,
	
	/**
	 * PIN_PROTECTED - is PIN protected - 0=No 1=Yes
	 */
	PIN_PROTECTED,
	
	/**
	 * TOKEN_CHALL_LENGTH - returns the expected Challenge Code length
	 */
	TOKEN_CHALL_LENGTH,
	
	/**
	 * TOKEN_IS_IN_WAIT - returns 1 if PIN verification failure occurs and the token is in wait state
	 */
	TOKEN_IS_IN_WAIT,
	
	/**
	 * TOKEN_PIN_LENGTH - returns the PIN length definition
	 */
	TOKEN_PIN_LENGTH,
		
	/**
	 * TOKEN_STATE - token state: Installed, In-Process, Ready
	 */
	TOKEN_STATE,
	
	/**
	 * TOKEN_TICK_COUNT - time-based OTP interval, in seconds
	 */
	TOKEN_TICK_COUNT,
	
	/**
	 * TOKEN_TRIVIAL_PIN_ALLOWED - returns whether a trivial PIN is allowed - 0=No, 1=Yes
	 */
	TOKEN_TRIVIAL_PIN_ALLOWED,
		
	/**
	 * TOKEN_WAITING_TIME - returns the PIN verification failure wait time count, in minutes
	*/
	TOKEN_WAITING_TIME,
	
	/*
     * NUMERIC_TOKEN_PIN_ALLOWED - is token PIN should be numeric or alphanumeric
     */
    NUMERIC_TOKEN_PIN_ALLOWED,
    
    /*
     * SERVER_SIDE_TOKEN_PIN_MIN_LEN - min possible length for server-side token PIN
     */
    SERVER_SIDE_TOKEN_PIN_MIN_LEN,
    
    /*
     * SERVER_SIDE_TOKEN_PIN_MAX_LEN - max possible length for server-side token PIN
     */
    SERVER_SIDE_TOKEN_PIN_MAX_LEN,
    
    /*
     * SERVER_SIDE_TOKEN_PIN_TYPE - is server-side is numeric/alphanumeric/type of alphanumeric
     */
    SERVER_SIDE_TOKEN_PIN_TYPE,
		
	/*
     * TOKEN_REMAINING_TICK_COUNT - time remaining till next OTP generation
     */
    TOKEN_REMAINING_TICK_COUNT,
    
    /*
     * OTP_GEN_SUSPEND_INTERVAL - interval between OTP generations
     */
    OTP_GEN_SUSPEND_INTERVAL,
    
    /*
     * OTP_GEN_SUSPEND_TIME - time left till next OTP generated
     */
    OTP_GEN_SUSPEND_TIME,
    
    /**
     * MPIPARAM_UNKNOWN - unknown parameter
     */
    MPIPARAM_UNKNOWN
};

/**
 * Integer parameter definition, returned by mp_getSDKParamInt function
 */
typedef NS_ENUM(NSUInteger, MPISDKPARAM)
{
    /*
     * MAX_TOKENS_CAPACITY - maximum number of tokens SDK creates and supports
     */
    MAX_TOKENS_CAPACITY,
    
    /**
     * MPISDKPARAM_UNKNOWN - unknown parameter
     */
    MPISDKPARAM_UNKNOWN
};

/**
 * Integer parameter definition, defines pin type
 */
typedef NS_ENUM(NSUInteger, MPPINTYPE)
{
    /**
     * PIN used for token on the application side
     */
    USER_SIDE_PIN   = 1,
    
    /**
     * PIN used for token on the server side
     */
    SERVER_SIDE_PIN = 2,
    
    /**
     * MPPINTYPE_UNKNOWN - unknown parameter
     */
    MPPINTYPE_UNKNOWN
};

/**
 * Integer parameter definition, defines server side pin complexity
 */
typedef NS_ENUM(NSUInteger, MPSSPCOMPLEXITY)
{
    SSP_NUMERIC      = 1,
    SSP_ALPHANUMERIC = 2,
    SSP_ALPHANUMERIC_STRONG  = 3,
    SSP_ALPHANUMERIC_COMPLEX = 4
};
	
/**
 * Function returned no error
 */
#define  ERR_NONE                   0

/**
 * Function failed because mp_libInit function was not called
 */
#define  ERR_LIB_NOT_INIT           1
	
/**
 * Failed to create the token because a token with the same name already exists
 */
#define ERR_TOKEN_ALREADY_EXISTS    2
	
/**
 * Unspecified error
 */
#define ERR_OP_FAILED               3
	
/**
 * Function failed because the PIN was not yet verified
 */
#define ERR_NEED_PIN_VERIFICATION   4
	
/**
 * Function failed because a target token does not exist
 */
#define ERR_TOKEN_DOES_NOT_EXIST    5
	
/**
 * Operation requires an empty token (i.e. without seed)
 */
#define ERR_TOKEN_NOT_EMPTY         6
	
/**
 * Invalid input parameter
 */
#define ERR_INVALID_PARAMETER       7
	
/**
 * One or more of the enrollment input fields is missing
 */
#define ERR_NO_ENROLL_PARAM_FOUND    8

/**
 * PIN does not comply with PIN policy
 */
#define ERR_PIN_DOES_NOT_MEET_REQUIREMENTS  9

/**
 * Operation requires a non-empty token (seed in place)
 */
#define ERR_TOKEN_IS_EMPTY          10
	
/**
 * Operation requires that a token be selected
 */
#define ERR_NO_TOKEN_SELECTED       11
	
/**
 * PIN entered is incorrect
 */
#define ERR_PIN_VERIFY_FAILED       12
	
/**
 * PIN must be changed
 */
#define ERR_PIN_CHANGE_REQUIRED     13
	
/**
 * Enrollment server error
 */
#define ERR_AUTO_ENROLL_HTTP_SECURITY   14
	
/**
 * Enrollment unspecified error
 */
#define ERR_AUTO_ENROLL_OP_FAILED       15
	
/**
 * Enrollment requires OTP PIN
 */
#define ERR_AUTO_ENROLL_SOFTPIN_NEEDED  16
	
/**
 * OTP PIN input is not required
 */
#define ERR_AUTO_ENROLL_SOFTPIN_NOT_NEEDED  17
	
/**
 * Enrollment communication error
 */
#define ERR_AUTO_ENROLL_COM_ERROR           18
	
/**
 * Enrollment server error
 */
#define ERR_AUTO_ENROLL_SERVER_NOT_INIT     19
	
/**
 * Enrollment server timeout error
 */
#define ERR_AUTO_ENROLL_SESSION_EXPIRED     20
	
/**
 * Enrollment server abort
 */
#define ERR_AUTO_ENROLL_SESSION_ABORTED     21
	
/**
 * Enrollment OTP PIN is invalid
 */
#define ERR_AUTO_ENROLL_SOFT_PIN_INVALID    22
	
/**
 * Token was erased due to PIN verification counter exceeding max error counter
 */
#define ERR_PIN_VERIFY_FAILED_TOKEN_ERSAED  23
	
/**
 * Device is unique, android ID is not available
 */
#define ERR_DEVICE_UNIQUE_NOT_AVAILABLE     24

/**
 * MobilePASS library is not ready
 */
#define ERR_MP_IS_NOT_READY                 25

/**
 * PIN already set
 */
#define ERR_TOKEN_PIN_ALREADY_SET           26

/**
 * Token is not ready for operation
 */
#define ERR_TOKEN_NOT_READY                 27

/**
 * Maximal number of tokens has been reached
 */
#define ERR_MAX_NUMBER_OF_TOKENS_CREATED    28

/**
 * Unknown parameter value was requested
 */
#define ERR_UNKNOWN_PARAM                   29

/**
 * Invalid policy string
 */
#define ERR_INVALID_POLICY                  30

/**
 * Too early to generate a new OTP
 */
#define ERR_OTP_GEN_TIME                    31

/**
 * Too early to generate a new OTP
 */
#define ERR_OTP_GEN_SUSPEND_INTERVAL        32

/**
 * Not all data was cleaned from keychain
 */
#define ERR_DATA_CLEANING_PARTIAL           33

/**
 * Activity counter changed
 */
#define ERR_ACT_COUNTER_CHANGED             34

/**
 * Device is Jailbroaken
 */
#define ERR_JAILBROAKEN                     35

#endif  //__MP_LIBSTCONST_H__

