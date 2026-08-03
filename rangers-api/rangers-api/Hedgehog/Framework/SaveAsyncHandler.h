#pragma once

namespace hh::fw{
    class SaveAsyncHandler : public fnd::ReferencedObject {
    public:
        int64_t qword18;
        volatile int volatile___int3220;
        int dword24;
        int64_t qword28;

        SaveAsyncHandler(csl::fnd::IAllocator* allocator);
    };
}
