#pragma once

namespace app::player {
    class PostureStandard : public PlayerPosture {
    public:
        csl::math::Vector4 oword20;
        int dword30;
        int dword34;
        float dword38;
        char byte3C;

        virtual unsigned int GetNameHash() const override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Enter() override;
        virtual void Update(float deltaTime, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UnkFunc6() override;

        PostureStandard(csl::fnd::IAllocator* allocator);
    };
}
