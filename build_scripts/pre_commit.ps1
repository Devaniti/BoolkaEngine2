Push-Location $PSScriptRoot
& "./format.ps1"
& "./tidy_fix_slow.ps1"
Pop-Location
