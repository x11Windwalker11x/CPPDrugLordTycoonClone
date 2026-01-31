Set up git aliases for two-repo workflow (WWSimulatorFramework + CPPDrugLordTycoonClone)

Run this bash command to enable all git aliases:

```bash
alias goframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins"' && alias gogame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"' && alias pushframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "framework update" && git push origin main' && alias pushgame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git add . && git commit -m "game update" && git push origin main' && alias pushall='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "framework update" && git push origin main && cd .. && git add . && git commit -m "game update" && git push origin main' && alias pullframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git pull origin main' && alias pullgame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git pull origin main' && alias pullall='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git pull origin main && cd .. && git pull origin main'
```

After running, confirm aliases are active.
