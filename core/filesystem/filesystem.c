#include "filesystem.h"

EFI_STATUS OpenFileSystem(EFI_HANDLE ImageHandle, EFI_SIMPLE_FILE_SYSTEM_PROTOCOL **FileSystem) {
    return ST->BootServices->HandleProtocol(ImageHandle, &gEfiSimpleFileSystemProtocolGuid, (void **)FileSystem);
}

EFI_STATUS OpenRoot(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem, EFI_FILE_PROTOCOL **Root) {
    return FileSystem->OpenVolume(FileSystem, Root);
}

EFI_STATUS OpenFile(EFI_FILE_PROTOCOL *Root, EFI_FILE_PROTOCOL **File, uint16_t *FileName) {
    return Root->Open(Root, File, FileName, EFI_FILE_MODE_READ, 0);
}

EFI_STATUS ReadFile(EFI_FILE_PROTOCOL *File, void *Buffer, uint64_t *Size) {
    return File->Read(File, Size, Buffer);
}

EFI_STATUS LoadFile(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem, uint16_t *FileName, EFI_PHYSICAL_ADDRESS *FileBuffer, uint64_t *FileSize) {
    EFI_FILE_PROTOCOL *Root, *File;
    EFI_STATUS Status;
    uint64_t BufferSize;
    
    Status = OpenRoot(FileSystem, &Root);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    Status = OpenFile(Root, &File, FileName);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    Status = File->GetInfo(File, &gEfiFileInfoGuid, &BufferSize, NULL);
    if (Status != EFI_BUFFER_TOO_SMALL) {
        return Status;
    }

    EFI_FILE_INFO *FileInfo;
    Status = ST->BootServices->AllocatePool(EfiLoaderData, BufferSize, (void **)&FileInfo);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    Status = File->GetInfo(File, &gEfiFileInfoGuid, &BufferSize, FileInfo);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    *FileSize = FileInfo->FileSize;
    Status = ST->BootServices->AllocatePages(AllocateAnyPages, EfiLoaderData, (*FileSize + 0xFFF) / 0x1000, FileBuffer);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    Status = ReadFile(File, (void *)*FileBuffer, FileSize);
    return Status;
}
