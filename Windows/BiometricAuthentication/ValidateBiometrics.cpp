#include "pch.h"
#include "BiometricAuthentication.h"
#include <winrt/base.h>
#include <winrt/Windows.Security.Credentials.UI.h>
#include <winrt/Windows.Foundation.h>

using namespace winrt;
using namespace Windows::Security::Credentials::UI;


extern "C" bool Authenticate()
{
	init_apartment();

	auto result = UserConsentVerifier::RequestVerificationAsync(L"Verify using Windows Hello").get();
	return result == UserConsentVerificationResult::Verified;
}