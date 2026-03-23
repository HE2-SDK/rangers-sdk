#pragma once

namespace Cyan::System {
    template<typename T, size_t size>
    class LinkPool {
        struct Entry {
            T data;
            Entry* unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        uint64_t qword0;
        uint64_t qword8;
        uint64_t qword10;
        LinkPool<T, size>* char18;
        volatile signed __int32 volatile_signed___int3220;
        uint64_t qword28;
        uint64_t qword30;
        uint64_t qword38;
        void* qword40;
        uint32_t dword48;
        Entry entries[size];

        LinkPool();
    };
}
