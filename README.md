# Biometric Authentication

Plugins for Unity that enable native OS authentication services, such as Windows Hello or macOS Touch ID. 
## Authors

- [@Tailspin96](https://www.github.com/Tailspin96)
## Supported Platfoms

Biometric Authentication currently supports:
 - ✅ Windows 10 (Tested)/Windows 11 (Untested)
 - ✅ macOS 11.5+
### Planned
 - Linux
 - iOS
 - Android
 ## Installation

1) Download the plugin for the target platform.
2) Add the plugin to Unity and move it to the `Plugins` folder.

```
/Assets/Plugins/macOS
/Assets/Plugins/Windows
```
3) Download `ValidateBiometrics.cs` and add it to the Unity project.
4) Add the `using` to any script where it is needed and call the method. See below for example.
## ValidateBiometrics Class

```csharp
using OS6.Authentication;
```

| Name             | Type   | Description                                               |
| :--------------- | :----- | :-------------------------------------------------------- |
| `Authenticate()` | `bool` | Returns `true` or `false` based on the Auth window result |

## Example

```csharp
using UnityEngine;
using OS6.Authentication;

public class ActionWithBiometrics : MonoBehaviour
{
    private async void ExampleMethod()
    {
        if (await ValidateBiometrics.AuthenticateBiometrics()) 
        {
            Action();
        }
    }
}
```
