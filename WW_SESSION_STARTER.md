# WINDWALKER SESSION STARTER

**Purpose:** Detect leftover tasks, plan session, minimize decision fatigue

**Last Session:** Feb 12, 2026 (Session 10) - MarqueeSelectionWidget_Base System (V2.13.6; 5 new files, 9 modified; UMarqueeSelectionWidget_Base abstract base in MSB; BoxSelectionWidget re-parented; ~150 lines extracted from InventoryGridWidget; 4 UI.Selection.Mode tags; 6 InventoryWidgetManager stubs completed; strategy pattern + FGameplayTag modes; V1 UI-space only)

---

## INSTRUCTIONS

**Paste this into claude.ai at session start. Upload framework files first.**

---

## SESSION INITIALIZATION

I'm continuing Windwalker Framework work. I've uploaded:
- WINDWALKER_FRAMEWORK_ARCHITECTURE_V2_13_REVISED.md
- WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md

**Read both, then:**

1. **Check for leftover task** - Search past 2 chats for incomplete work
2. **If leftover exists** - Resume that task (tell me what it is + current state)
3. **If no leftover** - Consult TODO file, recommend next task based on:
   - Priority (P0 > P1 > P2 > P3 > P4)
   - Dependencies (blocked tasks skip)
   - My stated energy level (if I mention it)

**Output format:**

```
LEFTOVER DETECTED: [task name]
STATUS: [what's done, what remains]
NEXT STEP: [exact action to take]

Or:

NO LEFTOVER
RECOMMENDED: [task from TODO]
REASON: [why this task now]
ESTIMATED TIME: [X hours]
```

**Then ask:** "Approve to proceed, or select different task?"

---

## MY ENERGY LEVEL (optional - tell you if relevant)

[Leave blank unless fatigued/limited time]

---

## RULES EMBEDDED

- Golden Rule #34: Search past chats before assuming
- Golden Rule #36: ADD before implementation
- Golden Rule #46: HUD widgets MUST use UManagedWidget_Master
- Golden Rule #47: Widgets belong in owning plugin's UI/ folder (not MSB/AWF)
- Workflow V2: ADD → Approve → Claude Code implements
- No lateral L2→L2 dependencies
- Performance <0.02ms always
- Networking always included

---

**Location:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WW_SESSION_STARTER.md`
