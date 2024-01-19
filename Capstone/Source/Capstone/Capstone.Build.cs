// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Capstone : ModuleRules
{
	public Capstone(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput"
            , "Sockets", "Networking", "Json", "JsonUtilities", "UMG" });

        PrivateDependencyModuleNames.AddRange(new string[] { "ProtobufCore" });

        PrivateIncludePaths.AddRange(new string[]
        {
            "Capstone/",
            "Capstone/Network/",
            "Capstone/Player/",
            "Capstone/Object/",
            "Capstone/Widget/",
        });
    }
}
