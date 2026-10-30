#pragma once

namespace app::game {
    class GOCDensity : public hh::game::GOComponent {
    public:
        struct Description {
            float dword80;
            csl::math::Transform oword90;
            int dwordC0;
        };

        Description description;
        hh::game::GOCTransform* gocTransform;
        int64_t qwordD0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCDensity);
    };
}
