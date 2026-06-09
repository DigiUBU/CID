// Author: Universidad de Burgos

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Serialization/Archive.h"
#include "Utilidades.generated.h"

// Datos de mirada (gaze) de un ojo
USTRUCT(BlueprintType)
struct XRAILAB_API FEyeGazeData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    bool bIsValid = false;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FVector Position = FVector::ZeroVector;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FVector Direction = FVector::ZeroVector;

    friend FArchive& operator<<(FArchive& Ar, FEyeGazeData& Data)
    {
        Ar << Data.bIsValid;
        Ar << Data.Position;
        Ar << Data.Direction;
        return Ar;
    }
};

// Datos de pupila de un ojo
USTRUCT(BlueprintType)
struct XRAILAB_API FEyePupilData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    bool bIsDiameterValid = false;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    bool bIsEyePositionValid = false;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    float PupilDiameter = 0.0f;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FVector2D Position = FVector2D::ZeroVector;

    friend FArchive& operator<<(FArchive& Ar, FEyePupilData& Data)
    {
        Ar << Data.bIsDiameterValid;
        Ar << Data.bIsEyePositionValid;
        Ar << Data.PupilDiameter;
        Ar << Data.Position;
        return Ar;
    }
};

// Datos geometricos de un ojo (apertura, entrecierre, apertura amplia)
USTRUCT(BlueprintType)
struct XRAILAB_API FEyeGeometricData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    bool bIsValid = false;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    float Openness = 0.0f;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    float Squeeze = 0.0f;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    float Wide = 0.0f;

    friend FArchive& operator<<(FArchive& Ar, FEyeGeometricData& Data)
    {
        Ar << Data.bIsValid;
        Ar << Data.Openness;
        Ar << Data.Squeeze;
        Ar << Data.Wide;
        return Ar;
    }
};

// Conjunto completo de datos oculares para un frame
USTRUCT(BlueprintType)
struct XRAILAB_API FGazeFrameData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyeGazeData RightGaze;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyeGazeData LeftGaze;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyePupilData RightPupil;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyePupilData LeftPupil;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyeGeometricData RightEyeGeometric;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Eye")
    FEyeGeometricData LeftEyeGeometric;

    friend FArchive& operator<<(FArchive& Ar, FGazeFrameData& Data)
    {
        Ar << Data.RightGaze;
        Ar << Data.LeftGaze;
        Ar << Data.RightPupil;
        Ar << Data.LeftPupil;
        Ar << Data.RightEyeGeometric;
        Ar << Data.LeftEyeGeometric;
        return Ar;
    }
};

// Par de valor flotante y timestamp Unix para un dato fisiologico
USTRUCT(BlueprintType)
struct XRAILAB_API FDataDuple
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    float Value = 0.0f;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    int64 UnixTime = 0;

    friend FArchive& operator<<(FArchive& Ar, FDataDuple& Data)
    {
        Ar << Data.Value;
        Ar << Data.UnixTime;
        return Ar;
    }
};

// Datos fisiologicos completos para un frame
USTRUCT(BlueprintType)
struct XRAILAB_API FPhysiologicalData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple EDA;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple HR;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple SCR_AMP;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple SCR_RIS;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple SCR_FREQ;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple PPG_RED;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple PPG_IR;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple PPG_GRN;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple TEMP1;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple THERM;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple ACC_X;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple ACC_Y;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple ACC_Z;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple GYRO_X;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple GYRO_Y;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple GYRO_Z;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple MAG_X;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple MAG_Y;

    UPROPERTY(BlueprintReadWrite, Category = "Replay|Physiological")
    FDataDuple MAG_Z;

    friend FArchive& operator<<(FArchive& Ar, FPhysiologicalData& Data)
    {
        Ar << Data.EDA;
        Ar << Data.HR;
        Ar << Data.SCR_AMP;
        Ar << Data.SCR_RIS;
        Ar << Data.SCR_FREQ;
        Ar << Data.PPG_RED;
        Ar << Data.PPG_IR;
        Ar << Data.PPG_GRN;
        Ar << Data.TEMP1;
        Ar << Data.THERM;
        Ar << Data.ACC_X;
        Ar << Data.ACC_Y;
        Ar << Data.ACC_Z;
        Ar << Data.GYRO_X;
        Ar << Data.GYRO_Y;
        Ar << Data.GYRO_Z;
        Ar << Data.MAG_X;
        Ar << Data.MAG_Y;
        Ar << Data.MAG_Z;
        return Ar;
    }
};

/**
 * */
UCLASS()
class XRAILAB_API UUtilidades : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static int64 GetCustomUnixTime();

    UFUNCTION(BlueprintPure, Category = "Email")
    static FString GetAndroidGamePath();
};