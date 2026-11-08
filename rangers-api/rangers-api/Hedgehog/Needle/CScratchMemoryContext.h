#pragma once

namespace hh::needle {
    class CScratchMemoryContext {
    public:
        enum class Flag : uint32_t {
            UNKPARAM,
            IS_CHILD,
        };

        void* memory;
        size_t usedSize;
        size_t allocatedSize;
        CScratchMemoryContext* parent;
        void* data; // skipping header
        uint32_t unk4;
        uint32_t flags;

        static size_t largestAllocation;

        CScratchMemoryContext(bool empty);
        CScratchMemoryContext(CScratchMemoryContext& other, bool unkParam);
        ~CScratchMemoryContext();
        void PreAllocInside(size_t size);

        template<typename T> inline T* PreAlloc(size_t count, bool zero) {
            size_t size = count * sizeof(T);

            if (size > largestAllocation)
                largestAllocation = size;

            size_t alignment = __STDCPP_DEFAULT_NEW_ALIGNMENT__;
            size_t alignedSize = (size + alignment - 1) & ~(alignment - 1);

            if (allocatedSize < usedSize + alignedSize)
                PreAllocInside(alignedSize);

            usedSize += alignedSize;

            T* ptr = (T*)((size_t)memory + usedSize);

            if (ptr != nullptr && zero)
                memset(ptr, 0, count);

            return ptr;
        }

#ifdef EXPORTING_TYPES
        template<> short* PreAlloc<short>(size_t count, bool zero);
#endif

        // Return value is nr of pages allocated.
        static unsigned int AllocPoolMemoryPage(unsigned int pageCount);
        static unsigned int AllocLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreeLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int GetMaxAllocatablePageSize();
    };
}
