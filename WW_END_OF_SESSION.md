# END OF SESSION — FULL PROTOCOL

**Purpose:** Complete session-end documentation and version control.

---

## MANDATORY CHECKLIST (NEVER SKIP)

### Step 0: Update This File (if protocol changes)
- Only if new steps are added or existing steps are modified.

### Step 1: Update `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md`
- Add completed work entry with metrics (files created, modified, lines changed)
- Update Metrics table if counts changed (interfaces, delegates, structs, tags, plugins)
- Mark any priority tasks as complete

### Step 2: Update `WW_SESSION_STARTER.md`
- Update the **Last Session** line with: date, session number, task name, key metrics

### Step 3: Create `WW_SESSION_BRIEFING_[DATE].md`
- Use `_B`, `_C` suffix if multiple briefings on same date
- Include: task status, files modified/created, architectural decisions, blockers, next session action

### Step 4: Update `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2_13_REVISED.md`
- **IF** new structs/interfaces/plugins/rules were added:
  - Update directory trees
  - Update L0 registries (data includes, delegate includes)
  - Update tag category prefixes
  - Update version history
  - Update metrics/counts

### Step 5: Update `CLAUDE.md`
- **IF** plugin count, version, or rules changed:
  - Update Module Creation counts
  - Update version number
  - Update AWF/architecture status

### Step 6: Git Commit + Push
- Commit to BOTH repos:
  - `Plugins/` → WWSimulatorFramework (framework repo)
  - Root → CPPDrugLordTycoonClone (game repo)
- Verify `git remote -v` before pushing
- Never push plugin code to game repo or vice versa

---

## BRIEFING TEMPLATE

```markdown
# SESSION BRIEFING - [DATE]

## TASK: [Task Name]

STATUS:
- [List of completed items]
- [Remaining items if any]

FILES CREATED:
- [path] (description)

FILES MODIFIED:
- [path] (what changed)

ARCHITECTURAL DECISIONS:
- [decisions made or "None"]

BLOCKERS:
- [blockers or "None"]

NEXT SESSION FIRST ACTION:
1. [exact step]

CLAUDE CODE COMPACT:
`/compact preserve [key decisions]`
```

---

**Location:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WW_END_OF_SESSION.md`
