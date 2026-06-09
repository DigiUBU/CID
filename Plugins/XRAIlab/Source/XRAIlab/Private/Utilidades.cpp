// Author: Universidad de Burgos


#include "Utilidades.h"
#include "Misc/DateTime.h"
#include "HAL/PlatformTime.h"
#include "Kismet/KismetStringLibrary.h"


/**
 * @brief Gets the current Unix timestamp in UTC with millisecond precision.
 * 
 * @return float Current Unix time.
 */
int64 UUtilidades::GetCustomUnixTime()
{
    // Gets the current time in UTC
    FDateTime now = FDateTime::UtcNow();

    // Unix timestamp in seconds
    int64 UnixTimestampInSeconds = now.ToUnixTimestamp();

    // Gets the milliseconds of the current second
    int32 Milliseconds = now.GetMillisecond();

    // Calculates the total timestamp with milliseconds
    int64 UnixTimestampWithMilliseconds = (UnixTimestampInSeconds * 1000) + Milliseconds;

    return UnixTimestampWithMilliseconds;
}
 FString UUtilidades::GetAndroidGamePath()
    {
#if PLATFORM_ANDROID
        extern FString GFilePathBase;
        return GFilePathBase + FString("/UnrealGame/") + FApp::GetProjectName() + FString("/");
#else
        return FString("");
#endif
 }