Push-Location $PSScriptRoot
cmake -G "Ninja" -DCMAKE_CXX_CLANG_TIDY="clang-tidy" -DCMAKE_CXX_CLANG_TIDY_EXPORT_FIXES_DIR="$PSScriptRoot/../tidy/fixes" -S ../source -B ../tidy
cmake --build ../tidy
clang-apply-replacements ../tidy/fixes
Pop-Location
