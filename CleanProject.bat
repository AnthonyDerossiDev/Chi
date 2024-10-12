@echo off
cd %~dp0
rmdir /s /q ".idea", ".vs", "Binaries", "DerivedDataCache", "Intermediate", "Saved/Autosaves", "Saved/Collections", "Saved/Crashes", "Saved/Logs", "Saved/UnrealBuildTool", "Saved\Config\CrashReportClient"
del /q /f .vsconfig, RoadToAshes.sln
echo All files are deleted successfully.
pause
