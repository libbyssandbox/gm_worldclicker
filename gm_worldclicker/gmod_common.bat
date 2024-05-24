@echo off

rmdir /s /q garrysmod_common
git clone --recursive https://github.com/danielga/garrysmod_common --branch x86-64-support-sourcesdk garrysmod_common

exit
