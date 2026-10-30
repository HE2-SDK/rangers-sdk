#pragma once

namespace SurfRide {
    static csl::fnd::IAllocator* allocator;
    csl::fnd::IAllocator* GetAllocator();
    void SetAllocator(csl::fnd::IAllocator* allocator);
    void* SrAllocate(size_t size);
    void SrFree(void* ptr);
}
