Push-Location $PSScriptRoot
Remove-Item -LiteralPath "../tidy" -Force -Recurse -ErrorAction SilentlyContinue
cmake -G "Ninja" -DCMAKE_CXX_CLANG_TIDY="clang-tidy" -S ../source -B ../tidy
cmake --build ../tidy
Remove-Item -LiteralPath "../tidy" -Force -Recurse
Pop-Location
