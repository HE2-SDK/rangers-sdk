#pragma once

namespace app::player {
    class VisualSonic : public VisualHuman {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void SetupFacialAnimation() override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;

        PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSonic);
    };

    class VisualSonicSpin : public VisualSpin, public ComponentHolderListener {
    public:
        uint64_t unk201;
        uint8_t unk202;

        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void SetupEffects() override;
        virtual void OnStart() override;
        virtual void OnEnd() override;
        virtual bool GetUnk() const override;
        virtual void SetUnk(bool enabled) override;
        virtual void CHL_UnkFunc1(ComponentCollection* collection) override;

        PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSonicSpin);
    };

    class VisualSuperSonic : public VisualHuman, public ComponentHolderListener {
    public:
        uint8_t unk201;
        float unk202;
        float unk203;
        float unk204;
        float unk205;

        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;
        virtual void UnbindEffects() override;
        virtual void CHL_UnkFunc1(ComponentCollection* collection) override;

        PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSuperSonic);
    };
}
