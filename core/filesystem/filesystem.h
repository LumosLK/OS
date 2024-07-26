#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "efi.h"

EFI_STATUS OpenFileSystem(EFI_HANDLE ImageHandle, EFI_SIMPLE_FILE_SYSTEM_PROTOCOL **FileSystem);
EFI_STATUS LoadFile(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem, uint16_t *FileName, EFI_PHYSICAL_ADDRESS *FileBuffer, uint64_t *FileSize);
EFI_STATUS ReadFile(EFI_FILE_PROTOCOL *File, void *Buffer, uint64_t *Size);
EFI_STATUS OpenRoot(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem, EFI_FILE_PROTOCOL **Root);
EFI_STATUS OpenFile(EFI_FILE_PROTOCOL *Root, EFI_FILE_PROTOCOL **File, uint16_t *FileName);

#endif // FILESYSTEM_H
