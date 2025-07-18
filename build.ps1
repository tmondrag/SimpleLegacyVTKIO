# powershell.exe -File build.ps1
Set-PSDebug -Trace 2
$sourcepath = '.'
$buildpath = 'build'
# configure step
cmake -S $sourcepath -B $buildpath	
# build step 
cmake --build $buildpath -j16
Set-PSDebug -Trace 0