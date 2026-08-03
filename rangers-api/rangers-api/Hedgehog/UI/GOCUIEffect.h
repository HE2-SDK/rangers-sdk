#pragma once

namespace hh::ui{
    class GOCUIEffect : public game::GOComponent {
    public:
        struct Effect{
            const char* effectName;
            fnd::Handle<SurfRideHandleBase> surfrideHandle;
            int drawStage;
            fnd::WorldPosition effectPosition;
            csl::math::Vector3 effectScale;
            eff::EffectHandle effectHandle;
            char unk1a;
            bool syncAlpha;
            char unk1c;
            char unk1d;
            int unk1[3];
        };

        struct Description {
            char unk0;
        };

        char unk0;
        eff::GOCEffect* gocEffect;
        GOCSprite* gocSprite;
        int unk3;
        csl::ut::InplaceMoveArray<Effect, 1> effects;
        csl::ut::InplaceMoveArray<int64_t, 2> unk5;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCUIEffect);
    };
}
