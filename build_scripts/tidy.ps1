#!/usr/bin/pwsh

Push-Location $PSScriptRoot
cmake -G "Ninja" -DCMAKE_CXX_CLANG_TIDY="clang-tidy" -DCMAKE_CXX_CLANG_TIDY_EXPORT_FIXES_DIR="$PSScriptRoot/../build/$($PSVersionTable.Platform)_tidy/fixes" -S ../source -B ../build/$($PSVersionTable.Platform)_tidy
cmake --build ../build/$($PSVersionTable.Platform)_tidy
clang-apply-replacements ../build/$($PSVersionTable.Platform)_tidy/fixes
Pop-Location
