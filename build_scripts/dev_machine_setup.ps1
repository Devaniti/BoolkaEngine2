if (!([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] 'Administrator')) {
    Start-Process -FilePath PowerShell.exe -Verb Runas -ArgumentList @("-ExecutionPolicy Bypass", "-File `"$($MyInvocation.MyCommand.Path)`"")
    Exit
}

Invoke-WebRequest -Uri https://aka.ms/getwinget -OutFile Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
Add-AppxPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
Remove-Item -Path Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
winget install -e Oracle.JDK.18
winget install -e Kitware.CMake
winget install -e Ninja-build.Ninja
winget install -e LLVM.LLVM
$LLVMPath = 'C:\Program Files\LLVM\bin'
$CMakePath = 'C:\Program Files\CMake\bin'
if ($env:Path -notcontains $LLVMPath) {
    $env:Path += ";$LLVMPath"
}
if ($env:Path -notcontains $CMakePath) {
    $env:Path += ";$CMakePath"
}
[Environment]::SetEnvironmentVariable("Path", $env:Path, [System.EnvironmentVariableTarget]::Machine)
Restart-Computer
