# CLAUDE CODE PROMPTS - COPY/PASTE LIBRARY

**Purpose:** One-line prompts for full system implementation via Claude Code

---

## USAGE

1. Get ADD approved in claude.ai first
2. Copy relevant prompt below
3. Paste into Claude Code terminal
4. Claude Code implements full system
5. Use `/compact` at 70% context

---

## WINDWALKER FRAMEWORK CONTEXT (auto-included)

Framework: Windwalker V2.13.1, 11 plugins, UE5.6
Rules: Performance <0.02ms, networking always, deps flow DOWN, comms flow UP
Patterns: Helpers for logic, interfaces for capability, components for behavior
Location: `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins\`
Repos: WWSimulatorFramework (plugins), CPPDrugLordTycoonClone (game project)

---

## GENERIC SYSTEM PROMPT

```
Implement [SYSTEM_NAME] for Windwalker Framework V2.13.1 following ADD approved in claude.ai.

RULES:
- Performance: <0.02ms overhead, use spatial hashing/caching
- Networking: ALWAYS add Server RPCs, OnRep functions, COND_OwnerOnly
- Dependencies: L2→L0.5 only (no lateral L2→L2)
- Communication: UP via delegates (EventBus or direct)
- Data: Pure structs + IsValid() only. Logic in Helpers.
- Interfaces: ImplementsInterface() + Execute_, mandatory getter
- Tags: Cache as UPROPERTY, Plugin.Category.Sub format (Input.* has no prefix)
- Includes: Own→SharedDefaults→MSB→Engine→.generated.h LAST

FILES TO CREATE: [list from ADD]
OUTPUT: Summary of files created + any architectural decisions made
```

---

## SPECIFIC SYSTEM PROMPTS

### New Interface

```
Create interface [INTERFACE_NAME] in SharedDefaults for Windwalker V2.13.1.

Location: Plugins/Windwalker_Productions_SharedDefaults/Source/Public/Interfaces/[PluginName]/
Rules:
- UINTERFACE + I[Name] class pair
- SHAREDDEFAULTS_API export
- Mandatory getter: Get[Name]AsActorComponent() or Get[Name]AsActor()
- All functions < 0.02ms
- No Server_, Internal_, OnRep_ in interface (those stay in implementation)
- BlueprintNativeEvent, BlueprintCallable for all functions

After creation:
- Update Interface Registry in architecture doc
- Add include path to reference
```

### New Component

```
Create component [COMPONENT_NAME] in [PLUGIN_NAME] for Windwalker V2.13.1.

Location: Plugins/[PluginName]/Source/Public/Components/
Rules:
- Implement relevant interface(s)
- ALWAYS add networking: Server RPCs, OnRep functions, COND_OwnerOnly
- Cache subsystem refs in BeginPlay (Rule #41)
- Register with SaveableRegistry if stateful (Rule #32, #37)
- Performance < 0.02ms per function
- Use interface + Execute_ for cross-plugin calls (never Cast<>)

Include order: Own→SharedDefaults→MSB→Engine→.generated.h LAST
```

### New Helper Class

```
Create helper [HELPER_NAME] in ModularSystemsBase for Windwalker V2.13.1.

Location: Plugins/ModularSystemsBase/Source/Public/Utilities/Helpers/[Category]/
Rules:
- Static functions only (no state)
- Pure logic, no side effects
- All functions < 0.02ms
- Use const& for inputs, avoid copies
- Document atomic contracts per function
```

### Bug Fix

```
Fix bug in [FILE_NAME] for Windwalker V2.13.1.

ERROR LOG:
[paste error]

Rules: 
- Use str_replace for surgical edits only
- Don't rewrite entire functions
- Explain root cause (C++ concept) after fix
- Verify include order: Own→SharedDefaults→MSB→Engine→.generated.h LAST
```

### Architectural Violation Fix

```
Fix architectural violation: [DESCRIBE ISSUE]

Current: [what's wrong - e.g. L2→L2 dependency]
Target: [correct pattern - e.g. L2→L0.5 via interface]

Rules:
- Use str_replace for surgical edits
- Follow dependency flow (Golden Rules #5-8)
- Communication UP via delegates only
- No lateral L2→L2 dependencies
```

---

## POST-IMPLEMENTATION OUTPUT

After Claude Code finishes, it should output:

```markdown
## Implementation Summary

FILES MODIFIED: [list]
FILES CREATED: [list]

WHAT CHANGED: [brief description]

WHY (C++ Concept): [TObjectPtr, TMap::Find(), delegates, etc]

COMMON PITFALLS AVOIDED: [UE4 vs UE5 pointer semantics, etc]

NEXT STEPS: [compile, test, integrate]
```

Upload this summary to claude.ai for validation (or to WW_LEARNING_MODE for deep explanation).

---

**Location:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WW_CLAUDE_CODE_PROMPTS.md`
