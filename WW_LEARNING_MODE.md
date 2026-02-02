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

**Location:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WW_LEARNING_MODE.md`
