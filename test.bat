@echo off

rem test.bat
rem alias batch file (because typing "ruby test.rb" is too long and dull...)

rem specify current directory
pushd %0\..

ruby test.rb %1 %2