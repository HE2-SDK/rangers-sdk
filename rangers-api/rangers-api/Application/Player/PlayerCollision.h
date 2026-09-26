#pragma once

namespace app::player {
    class PlayerCollision : public hh::fnd::ReferencedObject {
    public:
        struct Unk2 {
            csl::math::Vector3 pad1[5];
        };

        hh::physics::PhysicsWorldBullet* physicsWorldBullet;
        hh::physics::GOCCollisionCache* gocCollisionCache;
        float distance;
        float qword2C;
        float dword30;
        uint32_t collisionMask;
        csl::ut::InplaceMoveArray<Unk2, 64> unk40;
        csl::ut::MoveArray<void*> unk1460;
        uint8_t byte1480;

        void SetCollisionCache(hh::physics::GOCCollisionCache* gocCollisionCache);

        DEFAULT_CREATE_FUNC(PlayerCollision);
    };
}
