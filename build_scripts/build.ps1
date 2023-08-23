Push-Location $PSScriptRoot
& "./configure.ps1"
cmake --build ../build
Pop-Location
