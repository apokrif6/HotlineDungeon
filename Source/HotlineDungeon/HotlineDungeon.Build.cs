// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HotlineDungeon : ModuleRules
{
	public HotlineDungeon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
