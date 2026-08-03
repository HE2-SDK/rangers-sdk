#pragma once

namespace app::game{
    class GOCBossAnimatorTriggerHelper : public hh::game::GOComponent {
    public:
        struct Description {
            BossBaseContext* bossContext;
        };

        hh::fnd::Reference<BossBaseContext> bossContext;
        hh::fnd::Reference<anim::AnimatorTriggerListener<GOCBossAnimatorTriggerHelper>> animatorTriggerListener;
        csl::ut::InplaceMoveArray<int64_t, 1> qword90;
        csl::ut::InplaceMoveArray<int64_t, 4> qwordB8;
        short wordF8;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void GBATHUnkFunc(int64_t a2);

        void Setup(const Description& desc);
        void SetGOCAnimator(hh::anim::GOCAnimator* gocAnimator);
        void AddTriggerListener(const char* name);

        GOCOMPONENT_CLASS_DECLARATION(GOCBossAnimatorTriggerHelper)
    };
}
