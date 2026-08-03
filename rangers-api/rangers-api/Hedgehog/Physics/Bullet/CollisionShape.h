#pragma once

namespace hh::physics {
    struct ColliShape;
}

namespace hh::physics::bullet {
    class CollisionShape : public fnd::ReferencedObject {
    public:
        csl::ut::InplaceMoveArray<btCollisionShape*, 1> physicsObjects;
        csl::ut::MoveArray<int64_t> qword40;
        char flags;
        csl::math::Vector3 scale;

        CollisionShape(csl::fnd::IAllocator* allocator, btCollisionShape* physicsObject, bool unk);
    };

    struct ColliderInfo {
		typedef CollisionShape* CreateFunction(ColliShape* shape, int64_t unk);
		typedef void InitFunction(ColliShape* shape, int64_t unk, csl::math::Vector3& scale);

        CreateFunction* ctor;
        void* ctor1;
        InitFunction* init;
    };

    static ColliderInfo* colliderInfo;
}
