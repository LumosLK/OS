#include "efi.h"
#include "efi_util.h"
#include "efi_proto.h"
#include "memory.h"
#include "kernel.h"
#include "filesystem.h"
#include "drivers.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    InitializeLib(ImageHandle, SystemTable);
    Print(L"Welcome to LUMOS UEFI Bootloader\r\n");

    // Initialize display
    EFI_STATUS Status = InitializeDisplay(SystemTable);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to initialize display: %r\r\n", Status);
        return Status;
    }

    // Initialize USB
    Status = InitializeUSB(SystemTable);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to initialize USB: %r\r\n", Status);
        return Status;
    }

    // Initialize storage
    Status = InitializeStorage(SystemTable);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to initialize storage: %r\r\n", Status);
        return Status;
    }

    // Get file system handle
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem;
    Status = OpenFileSystem(ImageHandle, &FileSystem);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to open file system: %r\r\n", Status);
        return Status;
    }

    // Load kernel
    EFI_PHYSICAL_ADDRESS KernelBase;
    uint64_t KernelSize;
    Status = LoadFile(FileSystem, L"kernel.elf", &KernelBase, &KernelSize);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to load kernel: %r\r\n", Status);
        return Status;
    }

    Print(L"Kernel loaded successfully. Executing kernel...\r\n");

    // Execute kernel
    Status = ExecuteKernel(KernelBase);
    if (Status != EFI_SUCCESS) {
        Print(L"Failed to execute kernel: %r\r\n", Status);
        return Status;
    }

    Print(L"Kernel executed successfully. Bootloader finished.\r\n");
    return EFI_SUCCESS;
}
