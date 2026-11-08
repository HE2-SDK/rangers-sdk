#pragma once

namespace app::player {
	class VisualSonicSpin : public VisualSpin, public ComponentHolderListener {
	public:
		Component* currentComponent;
		char flags;
	
		virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void SetupEffects() override;
        virtual void OnStart() override;
        virtual void OnEnd() override;
		virtual bool IsSuper() const override;
		virtual void SetIsSuper(bool enabled) override;
		virtual void CHL_UnkFunc1(ComponentCollection* compCollection) override;
		
		PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSonicSpin);
	};
	
    class VisualSonic : public VisualHuman {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void SetupFacialAnimation() override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;

        PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSonic);
    };

    class VisualSuperSonic : public VisualHuman, public ComponentHolderListener {
    public:
        uint8_t unk201;
		float auraBodyColor[4];

        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;
        virtual void UnbindEffects() override;
        virtual void CHL_UnkFunc1(ComponentCollection* collection) override;

        PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(VisualSuperSonic);
    };
}
