// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameDemo : ModuleRules
{
	public GameDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GameDemo",
			"GameDemo/Variant_Platforming",
			"GameDemo/Variant_Platforming/Animation",
			"GameDemo/Variant_Combat",
			"GameDemo/Variant_Combat/AI",
			"GameDemo/Variant_Combat/Animation",
			"GameDemo/Variant_Combat/Gameplay",
			"GameDemo/Variant_Combat/Interfaces",
			"GameDemo/Variant_Combat/UI",
			"GameDemo/Variant_SideScrolling",
			"GameDemo/Variant_SideScrolling/AI",
			"GameDemo/Variant_SideScrolling/Gameplay",
			"GameDemo/Variant_SideScrolling/Interfaces",
			"GameDemo/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
