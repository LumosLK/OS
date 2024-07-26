@echo off
set ROOT_DIR=Lumos

rem Create main directories
mkdir %ROOT_DIR%
mkdir %ROOT_DIR%\boot
mkdir %ROOT_DIR%\boot\efi
mkdir %ROOT_DIR%\boot\kernel

mkdir %ROOT_DIR%\core
mkdir %ROOT_DIR%\core\scheduler
mkdir %ROOT_DIR%\core\memory
mkdir %ROOT_DIR%\core\filesystem
mkdir %ROOT_DIR%\core\process
mkdir %ROOT_DIR%\core\ipc
mkdir %ROOT_DIR%\core\security
mkdir %ROOT_DIR%\core\localization

mkdir %ROOT_DIR%\drivers
mkdir %ROOT_DIR%\drivers\storage
mkdir %ROOT_DIR%\drivers\network
mkdir %ROOT_DIR%\drivers\display
mkdir %ROOT_DIR%\drivers\input
mkdir %ROOT_DIR%\drivers\audio

mkdir %ROOT_DIR%\libs
mkdir %ROOT_DIR%\libs\libc
mkdir %ROOT_DIR%\libs\gui
mkdir %ROOT_DIR%\libs\network
mkdir %ROOT_DIR%\libs\storage

mkdir %ROOT_DIR%\applications
mkdir %ROOT_DIR%\applications\system
mkdir %ROOT_DIR%\applications\system\file_manager
mkdir %ROOT_DIR%\applications\system\terminal
mkdir %ROOT_DIR%\applications\system\settings
mkdir %ROOT_DIR%\applications\user
mkdir %ROOT_DIR%\applications\user\text_editor
mkdir %ROOT_DIR%\applications\user\browser
mkdir %ROOT_DIR%\applications\third_party

mkdir %ROOT_DIR%\docs
mkdir %ROOT_DIR%\docs\user_manual
mkdir %ROOT_DIR%\docs\developer_guide
mkdir %ROOT_DIR%\docs\api_docs
mkdir %ROOT_DIR%\docs\faq

mkdir %ROOT_DIR%\scripts
mkdir %ROOT_DIR%\scripts\build
mkdir %ROOT_DIR%\scripts\test
mkdir %ROOT_DIR%\scripts\deploy

mkdir %ROOT_DIR%\tests
mkdir %ROOT_DIR%\tests\unit
mkdir %ROOT_DIR%\tests\integration
mkdir %ROOT_DIR%\tests\performance
mkdir %ROOT_DIR%\tests\security

mkdir %ROOT_DIR%\tools
mkdir %ROOT_DIR%\tools\profiler
mkdir %ROOT_DIR%\tools\debugger
mkdir %ROOT_DIR%\tools\installer

echo Folder structure created successfully.
pause
