#pragma once

namespace app::player {
    class EffectEyeUV : public PlayerEffect, public hh::anim::AnimationStateMachineListener {
    public:
        struct SetupInfo {
            const char* prefix{};
            void* qword8{};
            void* qword10{};
            const char* leftEyeSuffix{};
            const char* rightEyeSuffix{};
            unsigned int leftEyeComponent{};
            unsigned int rightEyeComponent{};
        };

        uint64_t qword48;
        Component* qword50;
        hh::fnd::Reference<hh::gfx::ResAnimTexSrt> leftEyeResource;
        hh::fnd::Reference<hh::gfx::ResAnimTexSrt> rightEyeResource;
        void* qword68;
        void* qword70;
        const char* leftEyeSuffix;
        const char* rightEyeSuffix;
        int dword88;
        uint8_t byte8C;

        CREATE_FUNC(EffectEyeUV, hh::game::GameObject* playerObject, PlayerVisual* playerVisual, const SetupInfo& setupInfo);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
    };
}