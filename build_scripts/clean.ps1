#!/usr/bin/pwsh

Push-Location $PSScriptRoot
Remove-Item -LiteralPath "../build/$($PSVersionTable.Platform)" -Force -Recurse
Pop-Location