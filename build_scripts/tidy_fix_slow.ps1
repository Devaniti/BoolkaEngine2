Push-Location $PSScriptRoot
Remove-Item -LiteralPath "../tidy" -Force -Recurse -ErrorAction SilentlyContinue
cmake -G "Ninja" -DCMAKE_CXX_CLANG_TIDY="clang-tidy;--config-file=${PSScriptRoot}/../source/.clang-tidy;--fix-errors" -S ../source -B ../tidy
cmake --build ../tidy -j 1
Remove-Item -LiteralPath "../tidy" -Force -Recurse
Pop-Location
