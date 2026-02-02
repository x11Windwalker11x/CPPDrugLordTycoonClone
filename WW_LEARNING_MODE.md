# LEARNING MODE PROTOCOL

**Purpose:** Deep-dive C++ explanations from Claude Code summaries

---

## WHEN TO USE

**Off-days / low energy / post-shift recovery**
- Not writing code today
- Want to understand what Claude Code built yesterday
- Passive knowledge gain

---

## INSTRUCTIONS

**1. Get Claude Code Summary First**

In Claude Code terminal, after implementation:
```
Output implementation summary including:
- Files modified/created
- What changed (brief)
- Why (C++ concept - TObjectPtr, TMap, delegates, etc)
- Common pitfalls avoided
- Code snippets of key patterns used
```

**2. Paste Summary + This Prompt into claude.ai**

---

## LEARNING MODE ACTIVATED

I'm in learning mode. I've uploaded Claude Code's implementation summary from yesterday's session.

**Explain in depth:**

1. **Architectural Decisions**
   - WHY this pattern over alternatives
   - Trade-offs made
   - How it fits Windwalker rules

2. **C++ Type Decisions**
   - Why TSet vs TArray
   - Why TObjectPtr vs raw pointer
   - Why TMap<Key, TObjectPtr<Value>> specifically

3. **Function Methodology**
   - Why lambda vs function pointer
   - Syntax breakdown (capture lists, mutable, etc)
   - When to use each pattern

4. **Programming Concepts**
   - Polymorphism in this context
   - RAII if used
   - Move semantics if relevant
   - Template metaprogramming if used

5. **Syntax Deep-Dive**
   - What `UFUNCTION(Server, Reliable, WithValidation)` means
   - How `UPROPERTY(ReplicatedUsing=OnRep_X)` works
   - Execute_ pattern for interfaces
   - Delegate binding syntax

6. **Junior Dev Pitfalls**
   - Common mistakes for this pattern
   - What breaks easily
   - How to debug when it fails

7. **Senior Dev Insights** (teach as if 140 IQ)
   - Performance implications
   - Memory layout considerations
   - Cache coherency if relevant
   - Why Unreal does it this way vs standard C++

**Format:** Natural prose, not lists. Teach like a mentor explaining over coffee.

---

## EXAMPLE SUMMARY TO UPLOAD

```markdown
## Implementation Summary - Widget Pooling System

FILES CREATED:
- MSB/WidgetPoolSubsystem.h/.cpp
- SharedDefaults/Data/WidgetPoolConfig.h
- AWF/WidgetPoolingFeature.h/.cpp

WHAT CHANGED:
Added widget pooling for high-frequency UI. Damage numbers now recycle from pool instead of spawn/destroy per hit.

WHY (C++ Concept):
- TMap<FGameplayTag, TArray<TObjectPtr<UUserWidget>>> = typed pools per widget class
- Spatial sorting via FVector::DistSquared for nearest-first recycle
- Priority eviction = oldest widget kicked when pool full

COMMON PITFALLS AVOIDED:
- UE4 vs UE5: TObjectPtr handles GC, raw pointers don't
- TArray::Add vs Emplace: Emplace avoids copy for TObjectPtr
- FindOrAdd() vs Find() + Add(): FindOrAdd() atomic, prevents race conditions

CODE SNIPPET:
```cpp
TObjectPtr<UUserWidget>* WidgetPtr = WidgetPool.Find(WidgetTag);
if (WidgetPtr && WidgetPtr->IsValid())
{
    return WidgetPtr->Get(); // TObjectPtr->Get() = raw pointer for use
}
```
```

---

**After I explain, ask:** "What else from this summary needs clarification?"

---

## ALTERNATIVE TRIGGERS

| You Type | Mode | Duration |
|----------|------|----------|
| (paste this file) | Full Learning Mode | 20-30 min |
| "Deep dive: [topic]" | Single topic deep | 15-20 min |
| "Pattern drill" | Quick quiz | 2 min |
| "Review mode" | Active recall | 5-10 min |

---

## PATTERN REFERENCE: GAMEPLAY TAG CENTRALIZATION (Golden Rule #48)

### What It Is
All GameplayTags in Windwalker Framework require dual registration:
1. **Engine Registration:** `Config/DefaultGameplayTags.ini`
2. **Code Access:** `WW_TagLibrary.h/.cpp` in SharedDefaults

### Why Dual Registration?

| Location | Consumer | Purpose |
|----------|----------|---------|
| DefaultGameplayTags.ini | Designers/Blueprint | Editor tag picker discovery |
| WW_TagLibrary | C++ code | Type-safe, compile-time validation, static caching |

### The 5-Step Protocol

```cpp
// STEP 1: Register in DefaultGameplayTags.ini
+GameplayTags=(Tag="Simulator.MiniGame.Type.Lockpick",DevComment="Lockpick mini-game")

// STEP 2: Define in WW_TagLibrary.cpp (WW_Internal namespace)
namespace WW_Internal {
    UE_DEFINE_GAMEPLAY_TAG(Simulator_MiniGame_Type_Lockpick, "Simulator.MiniGame.Type.Lockpick");
}

// STEP 3: Declare accessor in WW_TagLibrary.h
static const FGameplayTag& Simulator_MiniGame_Type_Lockpick();

// STEP 4: Implement accessor in WW_TagLibrary.cpp
const FGameplayTag& FWWTagLibrary::Simulator_MiniGame_Type_Lockpick()
{
    static const FGameplayTag& Tag = WW_Internal::Simulator_MiniGame_Type_Lockpick;
    return Tag;
}

// STEP 5: Use via accessor
FWWTagLibrary::Simulator_MiniGame_Type_Lockpick()
```

### Why Static Caching?
```cpp
// The UE_DEFINE_GAMEPLAY_TAG macro creates a native tag at startup
// The accessor returns a reference to this static tag
// First call: returns cached reference (no lookup)
// All subsequent calls: same cached reference
// Result: O(1) access, no string hashing, no map lookup
```

### Common Mistakes

```cpp
// ❌ WRONG - Runtime string lookup every call
FGameplayTag MyTag = FGameplayTag::RequestGameplayTag(FName("Simulator.MiniGame.Type.Lockpick"));

// ✅ CORRECT - Static cached reference
FGameplayTag MyTag = FWWTagLibrary::Simulator_MiniGame_Type_Lockpick();
```

### Plugin Tag Prefixes

| Plugin | Prefix | Example |
|--------|--------|---------|
| SharedDefaults | Movement.*, Character.* | Movement.Stance.Standing |
| ModularPlayerController | Camera.* | Camera.Mode.TPS |
| ModularInventorySystem | Inventory.* | Inventory.Slot.MainHand |
| SimulatorFramework | Simulator.* | Simulator.Device.State.Off |
| AdvancedWidgetFramework | UI.* | UI.Widget.Category.HUD |
| Input (global) | Input.* | Input.Numpad.0 |

---

**Location:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WW_LEARNING_MODE.md`
