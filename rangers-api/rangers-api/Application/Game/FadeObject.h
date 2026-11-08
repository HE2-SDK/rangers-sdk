#pragma once

namespace app::game{
    class FadeObject : public hh::game::GameObject {
    public:
        struct Description {
            char renderPriority;
            const char* name;
            char layer;
        };

        hh::ui::LayerController* layerController;
        float currentFadeTime;
        float endFadeTime;
        char renderPriority;
        float curDeltaFadeTime; // 0.0 -> 1.0

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void Setup(Description& desc);
        void Fade(float endTime);
        void FadeOut(float endTime);
        void Fade(float endTime, char startAlpha);
        bool IsFading();
        bool IsFadeOver();

        GAMEOBJECT_CLASS_DECLARATION(FadeObject)
    };
}
