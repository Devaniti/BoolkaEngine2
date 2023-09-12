#!/usr/bin/pwsh

Push-Location $PSScriptRoot
cmake -S ../source -B ../build/$($PSVersionTable.Platform)
Pop-Location
