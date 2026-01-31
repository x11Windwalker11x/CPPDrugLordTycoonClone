// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPPDrugLordClone : ModuleRules
{
	public CPPDrugLordClone(ReadOnlyTargetRules Target) : base(Target)
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
			"GameplayTags",
			"UMG",
			"ModularInteractionSystem",
			"ModularInventorySystem",
			"Windwalker_Productions_SharedDefaults",
			"SimulatorFramework"
			
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "Windwalker_Productions_SharedDefaults" });

		PublicIncludePaths.AddRange(new string[] {
			"CPPDrugLordClone",
			"CPPDrugLordClone/Variant_Platforming",
			"CPPDrugLordClone/Variant_Combat",
			"CPPDrugLordClone/Variant_Combat/AI",
			"CPPDrugLordClone/Variant_SideScrolling",
			"CPPDrugLordClone/Variant_SideScrolling/Gameplay",
			"CPPDrugLordClone/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
