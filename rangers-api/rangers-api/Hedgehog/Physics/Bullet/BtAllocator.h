#pragma once

namespace hh::physics {
    class BtAllocator : public csl::fnd::IAllocator {
    public:
        virtual void* Alloc(size_t size, size_t alignment) override;
		virtual void Free(void* ptr) override;

        static BtAllocator instance;
        static BtAllocator* GetInstance();
    };
}
