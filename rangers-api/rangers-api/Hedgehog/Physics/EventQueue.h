#pragma once

namespace hh::physics {
    class GOCCollider;

    class EventQueue : public fnd::ReferencedObject {
    public:
        enum class EntryType : unsigned char {
            ENTER = 1,
            LEAVE,
            STAY
        };

        struct QueueEntryDesc {
            EntryType type;
            GOCCollider* subject;
            GOCCollider* actor;
        };

        struct QueueEntry {
            EntryType type;
            hh::fnd::Reference<GOCCollider> subject;
            hh::fnd::Reference<GOCCollider> actor;
            int64_t unk0;
            int64_t unk1;
        };

        csl::ut::MoveArray<QueueEntry> queue;

        void AddToQueue(const QueueEntryDesc& desc);

        EventQueue(csl::fnd::IAllocator* allocator);
    };
}
