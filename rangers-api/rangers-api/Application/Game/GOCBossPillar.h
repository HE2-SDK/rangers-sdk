#pragma once

namespace app {
    class BossBaseContext;
}

namespace app::game {    
    class GOCBossPillar : public hh::game::GOComponent {
    public:
        struct Description {
            BossBaseContext* ctx;
            int32_t unk0;
            unsigned int visualModelNameHash;
            char parentBoneName[64];
        };

        Description description;
        int64_t qwordD0;
        hh::snd::SoundHandle pillarSound;
        int dwordDC;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> pillars;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword100;
        float dword120;
        short flags;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void Setup(const Description& desc);
        
        void SetPillarsEnabled(bool enabled);
        void Destroy();

        GOCOMPONENT_CLASS_DECLARATION(GOCBossPillar)
    };
}
