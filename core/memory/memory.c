#include "memory.h"

EFI_STATUS GetMemoryMap(EFI_MEMORY_DESCRIPTOR **MemoryMap, uint64_t *MemoryMapSize, uint64_t *MapKey, uint64_t *DescriptorSize, uint32_t *DescriptorVersion) {
    EFI_STATUS Status;
    uint64_t BufferSize = 0;
    *MemoryMap = NULL;

    Status = ST->BootServices->GetMemoryMap(&BufferSize, *MemoryMap, MapKey, DescriptorSize, DescriptorVersion);
    if (Status != EFI_BUFFER_TOO_SMALL) {
        return Status;
    }

    Status = ST->BootServices->AllocatePool(EfiLoaderData, BufferSize, (void **)MemoryMap);
    if (Status != EFI_SUCCESS) {
        return Status;
    }

    Status = ST->BootServices->GetMemoryMap(&BufferSize, *MemoryMap, MapKey, DescriptorSize, DescriptorVersion);
    return Status;
}

EFI_STATUS AllocatePages(EFI_PHYSICAL_ADDRESS *Address, uint64_t Pages) {
    EFI_STATUS Status = ST->BootServices->AllocatePages(AllocateAnyPages, EfiLoaderData, Pages, Address);
    return Status;
}

EFI_STATUS FreePages(EFI_PHYSICAL_ADDRESS Address, uint64_t Pages) {
    EFI_STATUS Status = ST->BootServices->FreePages(Address, Pages);
    return Status;
}

EFI_STATUS ReserveKernelMemory(EFI_PHYSICAL_ADDRESS BaseAddress, uint64_t Size) {
    EFI_STATUS Status = ST->BootServices->AllocatePages(AllocateAddress, EfiLoaderData, (Size + 0xFFF) / 0x1000, &BaseAddress);
    return Status;
}
