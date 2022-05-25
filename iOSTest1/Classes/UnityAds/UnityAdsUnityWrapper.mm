//
//  UnityAdsUnityWrapper.m
//  Copyright(c) 2015 Unity Technologies. All rights reserved.
//

#import "UnityAdsConfig.h"

extern "C" {
    typedef void (*UnityAdsReadyCallback)(const char * placementId);
    typedef void (*UnityAdsDidErrorCallback)(long rawError, const char * message);
    typedef void (*UnityAdsDidStartCallback)(const char * placementId);
    typedef void (*UnityAdsDidFinishCallback)(const char * placementId, long rawFinishState);
}

#if USE_UNITYADS

#import "UnityAppController.h"
#import "Unity/UnityInterface.h"

#import "UnityAds/UnityAds.h"
#import "UnityAds/UADSMetaData.h"

extern "C" {

    const char * UnityAdsCopyString(const char * string) {
        char * copy = (char *)malloc(strlen(string) + 1);
        strcpy(copy, string);
        return copy;
    }

    static UnityAdsReadyCallback readyCallback = NULL;
    static UnityAdsDidErrorCallback errorCallback = NULL;
    static UnityAdsDidStartCallback startCallback = NULL;
    static UnityAdsDidFinishCallback finishCallback = NULL;

}

@interface UnityAdsUnityWrapperDelegate : NSObject <UnityAdsDelegate>
@end

@implementation UnityAdsUnityWrapperDelegate

- (void)unityAdsReady:(NSString *)placementId {
    if(readyCallback != NULL) {
        const char * rawPlacementId = UnityAdsCopyString([placementId UTF8String]);
        readyCallback(rawPlacementId);
        free((void *)rawPlacementId);
    }
}

- (void)unityAdsDidError:(UnityAdsError)error withMessage:(NSString *)message {
    if(errorCallback != NULL) {
        const char * rawMessage = UnityAdsCopyString([message UTF8String]);
        errorCallback(error, rawMessage);
        free((void *)rawMessage);
    }
}

- (void)unityAdsDidStart:(NSString *)placementId {
    UnityPause(1);
    if(startCallback != NULL) {
        const char * rawPlacementId = UnityAdsCopyString([placementId UTF8String]);
        startCallback(rawPlacementId);
        free((void *)rawPlacementId);
    }
}

- (void)unityAdsDidFinish:(NSString *)placementId withFinishState:(UnityAdsFinishState)state {
    UnityPause(0);
    if(finishCallback != NULL) {
        const char * rawPlacementId = UnityAdsCopyString([placementId UTF8String]);
        finishCallback(rawPlacementId, state);
        free((void *)rawPlacementId);
    }
}

@end

extern "C" {

    void UnityAdsEngineInitialize(const char * gameId, bool testMode) {
        static UnityAdsUnityWrapperDelegate * unityAdsUnityWrapperDelegate = NULL;
        if(unityAdsUnityWrapperDelegate == NULL) {
            unityAdsUnityWrapperDelegate = [[UnityAdsUnityWrapperDelegate alloc] init];
        }
        [UnityAds initialize:[NSString stringWithUTF8String:gameId] delegate:unityAdsUnityWrapperDelegate testMode:testMode];
    }

    void UnityAdsEngineShow(const char * placementId) {
        if(placementId == NULL) {
            [UnityAds show:UnityGetGLViewController()];
        } else {
            [UnityAds show:UnityGetGLViewController() placementId:[NSString stringWithUTF8String:placementId]];
        }
    }

    bool UnityAdsEngineGetDebugMode() {
        return [UnityAds getDebugMode];
    }

    void UnityAdsEngineSetDebugMode(bool debugMode) {
        [UnityAds setDebugMode:debugMode];
    }

    bool UnityAdsEngineIsSupported() {
        return [UnityAds isSupported];
    }

    bool UnityAdsEngineIsReady(const char * placementId) {
        if(placementId == NULL) {
            return [UnityAds isReady];
        } else {
            return [UnityAds isReady:[NSString stringWithUTF8String:placementId]];
        }
    }

    long UnityAdsEngineGetPlacementState(const char * placementId) {
        if(placementId == NULL) {
            return [UnityAds getPlacementState];
        } else {
            return [UnityAds getPlacementState:[NSString stringWithUTF8String:placementId]];
        }
    }

    const char * UnityAdsEngineGetVersion() {
        static const char * unityAdsVersion = NULL;

        if(unityAdsVersion == NULL) {
            unityAdsVersion = UnityAdsCopyString([[UnityAds getVersion] UTF8String]);
        }

        return unityAdsVersion;
    }

    bool UnityAdsEngineIsInitialized() {
        return [UnityAds isInitialized];
    }

    void UnityAdsEngineSetMetaData(const char * category, const char * data) {
        if(category != NULL && data != NULL) {
            UADSMetaData* metaData = [[UADSMetaData alloc] initWithCategory:[NSString stringWithUTF8String:category]];
            NSDictionary* json = [NSJSONSerialization JSONObjectWithData:[[NSString stringWithUTF8String:data] dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nil];
            for(id key in json) {
                [metaData set:key value:[json objectForKey:key]];
            }
            [metaData commit];
        }
    }

    void UnityAdsEngineSetReadyCallback(UnityAdsReadyCallback callback) {
        readyCallback = callback;
    }

    void UnityAdsEngineSetDidErrorCallback(UnityAdsDidErrorCallback callback) {
        errorCallback = callback;
    }

    void UnityAdsEngineSetDidStartCallback(UnityAdsDidStartCallback callback) {
        startCallback = callback;
    }

    void UnityAdsEngineSetDidFinishCallback(UnityAdsDidFinishCallback callback) {
        finishCallback = callback;
    }

}

#else

extern "C" {
    void UnityAdsEngineInitialize(const char * gameId, bool testMode) { }
    void UnityAdsEngineShow(const char * placementId) { }
    bool UnityAdsEngineGetDebugMode() { return false; }
    void UnityAdsEngineSetDebugMode(bool debugMode) { }
    bool UnityAdsEngineIsSupported() { return false; }
    bool UnityAdsEngineIsReady(const char * placementId) { return false; }
    long UnityAdsEngineGetPlacementState(const char * placementId) { return -1; }
    const char * UnityAdsEngineGetVersion() { return NULL; }
    bool UnityAdsEngineIsInitialized() { return false; }
    void UnityAdsEngineSetMetaData(const char * category, const char * data) { }
    void UnityAdsEngineSetReadyCallback(UnityAdsReadyCallback callback) { }
    void UnityAdsEngineSetDidErrorCallback(UnityAdsDidErrorCallback callback) { }
    void UnityAdsEngineSetDidStartCallback(UnityAdsDidStartCallback callback) { }
    void UnityAdsEngineSetDidFinishCallback(UnityAdsDidFinishCallback callback) { }
}

#endif
