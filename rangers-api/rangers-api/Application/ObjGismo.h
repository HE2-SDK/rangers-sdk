#pragma once

namespace app{
    class ObjGismo : public hh::game::GameObject {
    public:
        char unk0;
        heur::rfl::GismoConfigDesignData* configDesign;
        heur::rfl::GismoConfigPlanData* configPlan;
        hh::fnd::Reference<GismoResource> resources;
        int64_t unk1;
        int64_t unk2;
        int64_t unk3;
        short unk4;
        int unk5;
        short unk6;
        int unk7;
        char unk8;
        csl::math::Vector4 unk9;
        int64_t unk10;
        int64_t unk11;
        int unk12;
        short unk13;
        hh::eff::EffectHandle effects[6];
        int unk14;
        short unk15;
        hh::snd::SoundHandle sounds[6];
        int unk16;
        int64_t unk17;
        short unk18;
        csl::math::Vector4 unk19;
        csl::math::Vector4 unk20;
        char unk21;
        int unk22;
        hh::fnd::Reference<hh::game::GOCTransform> gocTransform;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> gocVisualModel;
        hh::fnd::Reference<app::gfx::GOCVisualGeometryInstance> gocVisual;
        hh::fnd::Reference<hh::anim::GOCAnimationSingle> gocAnimation;
        hh::fnd::Reference<hh::eff::GOCEffect> gocEffect;
        hh::fnd::Reference<hh::snd::GOCSound> gocSound;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjGismo)
    };
}
