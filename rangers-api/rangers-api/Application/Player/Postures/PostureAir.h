#pragma once

namespace app::player {
    class PostureAir : public PlayerPosture {
    public:
        struct Description {
            float bounceAccelForce;
            float maxBounceDecelForce;
            float bounceDecelForce;
            float dword30;
            float dword34;
            int dword38;
            int dword3C;
            bool flag0;
            bool flag1;
            bool flag2;

            Description();
        };

        int dword20;
        float bounceAccelForce;
        float maxBounceDecelForce;
        float bounceDecelForce;
        float dword30;
        float dword34;
        int dword38;
        int dword3C;
        csl::math::Vector4 oword40;
        char flags;
        GOCPlayerKinematicParams::Unk5 qword60;

        virtual unsigned int GetNameHash() const override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Enter() override;
        virtual void Update(float deltaTime, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UnkFunc6() override;

        void Setup(const Description& description);

        PostureAir(csl::fnd::IAllocator* allocator);
    };
}
