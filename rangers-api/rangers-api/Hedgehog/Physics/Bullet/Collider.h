#pragma once

namespace hh::physics::bullet {
    class Collider : public WorldObject {
    public:
        virtual void SetTransform(fnd::WorldPosition& transform, char stateUpdateType, void* data) {};
        virtual void SetObjectLayer(char objectLayer, void* unk, void* data) {};
    };

    class CollisionObjectListener {
    public:
        virtual ~CollisionObjectListener() = 0;
        virtual void COL_UnkFunc0() = 0;
        virtual int64_t COL_UnkFunc1(int64_t a2) = 0;
    };
}
