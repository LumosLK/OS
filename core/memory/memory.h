#ifndef MEMORY_H
#define MEMORY_H

#include "efi.h"

typedef struct {
    EFI_PHYSICAL_ADDRESS BaseAddress;
    uint64_t Size;
    uint32_t Type;
} MemoryDescriptor;

EFI_STATUS GetMemoryMap(EFI_MEMORY_DESCRIPTOR **MemoryMap, uint64_t *MemoryMapSize, uint64_t *MapKey, uint64_t *DescriptorSize, uint32_t *DescriptorVersion);
EFI_STATUS AllocatePages(EFI_PHYSICAL_ADDRESS *Address, uint64_t Pages);
EFI_STATUS FreePages(EFI_PHYSICAL_ADDRESS Address, uint64_t Pages);

EFI_STATUS ReserveKernelMemory(EFI_PHYSICAL_ADDRESS BaseAddress, uint64_t Size);

#endif // MEMORY_H
