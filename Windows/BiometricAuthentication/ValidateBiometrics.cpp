#include "pch.h"
#include <winrt/base.h>
#include <winrt/Windows.Security.Credentials.UI.h>
#include <winrt/Windows.Foundation.h>

using namespace winrt;
using namespace Windows::Security::Credentials::UI;


bool Authenticate()
{
	init_apartment();

	auto result = UserConsentVerifier::RequestVerificationAsync(L"Verify using Windows Hello").get();
	return result == UserConsentVerificationResult::Verified;
}