#pragma once

namespace hh::physics {
    class PhysicsWorldBullet : public PhysicsWorld, public game::GameManagerListener {
    public:
        struct Unk0 {
            char unk0[0x54];
        };

        struct Unk1 {
            struct UnkObject {
                int64_t idHash;
                char type; // see WorldObject second vfunc
                btCollisionObject* object;
                int64_t unk0;
            };

            PhysicsWorldBullet* physicsWorld;
            csl::ut::MoveArray<UnkObject> qword8;
            csl::ut::MoveArray<UnkObject> qword28;
            int unkCount;
            int dword4c;
        };

        uint32_t unk201[32];
        uint64_t unk202;
        uint64_t unk203;
        uint64_t unk204;
        uint64_t unk205;
        uint64_t unk206;
        uint64_t unk207;
        bullet::OverlapFilterCallback overlapFilterCallback;
        btGhostPairCallback ghostPairCallback;
        csl::ut::MoveArray<int64_t> qword288;
        int64_t qword2A8;
        int64_t qword2B0;
        int dword2B8;
        csl::ut::MoveArray<int64_t> qword2C0;
        int64_t qword2E0;
        int64_t qword2E8;
        int dword2F0;
        csl::ut::MoveArray<int64_t> qword2F8;
        int64_t qword318;
        int64_t qword320;
        int dword328;
        rsdx::SJobJoint* qword330;
        Unk0 u338;
        int64_t qword390;
        int dword398;
        csl::ut::StringMap<int64_t> u3A0;
        Unk0 u3C0;
        char gap414[940];
        csl::ut::StringMap<int64_t> u7C0;
        Unk1 gap7E0;
        csl::ut::MoveArray<fnd::Reference<GOCCollider>> unkColliders830; // disabled colliders..?
        csl::ut::MoveArray<int64_t> qword850;

        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6() override;
        virtual bool PerformRayCastClosest(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, PhysicsQueryResult& result, uint64_t unkParam) override;
        virtual bool PerformRayCastAllHits(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, csl::ut::MoveArray<PhysicsQueryResult>& result, uint64_t unkParam) override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
        virtual void PostShutdownObjectCallback(game::GameManager* gameManager) override;

        GAMESERVICE_CLASS_DECLARATION(PhysicsWorldBullet)
    };

    const hh::game::GameServiceClass* PhysicsWorld::GetClass() {
        return PhysicsWorldBullet::GetClass();
    }
}
