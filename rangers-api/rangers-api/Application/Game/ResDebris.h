#pragma once

namespace app::game {
    class ResDebris : public csl::ut::NonCopyable {
    public:
        virtual ~ResDebris() = 0;
    };

    class ResFixPositionDebris : public ResDebris {
    public:
        csl::ut::MoveArray<int64_t> qword8;
        csl::ut::MoveArray<int64_t> qword28;
        csl::ut::MoveArray<int64_t> qword48;
        csl::ut::MoveArray<int64_t> qword68;
        char byte88;

        ResFixPositionDebris(csl::fnd::IAllocator* allocator);
    };
}
