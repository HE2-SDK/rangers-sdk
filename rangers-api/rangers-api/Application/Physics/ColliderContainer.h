#pragma once

namespace app::physics{
    class ColliderContainer : public hh::fnd::ReferencedObject {
    public:
        struct Element{
            hh::fnd::Handle<hh::physics::GOCCollider> handle;
            int flags;
            int unk0;
        };

        csl::ut::MoveArray<Element> colliders;

        void GetCollidersByFlag(int flag, csl::ut::MoveArray<hh::physics::GOCCollider*>& out);
        void SetCollidersEnabled(bool enabled);
        void AddCollider(hh::physics::GOCCollider* collider, int flags);

        ColliderContainer(csl::fnd::IAllocator* allocator);
    };
};
