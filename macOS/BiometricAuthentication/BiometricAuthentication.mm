#if _MSC_VER
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

#import <Foundation/Foundation.h>
#import <LocalAuthentication/LocalAuthentication.h>

extern "C" {
    EXPORT_API bool Authenticate() {
        __block bool result;
        
        dispatch_group_t group = dispatch_group_create();
        LAContext *context = [[LAContext alloc] init];
        NSError *error = nil;

        if ([context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometricsOrWatch error:&error]) {
            
            dispatch_group_enter(group);
            
            [context evaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometricsOrWatch
                    localizedReason:@"authenticate Using Biometrics"
                              reply:^(BOOL success, NSError * _Nullable error) {
                if (success) {
                    result = true;
                } else {
                    result = false;
                }
                
                dispatch_group_leave(group);
            }];
            
            dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        } else {
            result = false;
        }

        return result;
    }
}
