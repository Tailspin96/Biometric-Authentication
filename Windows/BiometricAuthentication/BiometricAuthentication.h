#pragma once

#ifdef BIOMETRICAUTHENTICATION_EXPORTS
#define BIOMETRICAUTHENTICATION_API __declspec(dllexport)
#else
#define BIOMETRICAUTHENTICATION_API __declspec(dllimport)
#endif

extern "C" BIOMETRICAUTHENTICATION_API bool Authenticate();