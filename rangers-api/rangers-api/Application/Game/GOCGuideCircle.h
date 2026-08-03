#pragma once

namespace app::game{
    class GOCGuideCircle : public hh::game::GOComponent {
    public:
        enum class Color : unsigned char {
            BLUE,
            PINK,
            RED,
            YELLOW
        };

        struct Description {
            bool showUpFar;
            csl::math::Vector3 circleOffset;
            Color color;
        };

        bool showUpFar;
        Color color;
        csl::math::Vector3 circleOffset;
        hh::eff::EffectHandle circleLoopEffect;
        hh::eff::EffectHandle circleInOutEffect;
        short flags;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);
        void SetColor(Color color);

        GOCOMPONENT_CLASS_DECLARATION(GOCGuideCircle);
    };
}
