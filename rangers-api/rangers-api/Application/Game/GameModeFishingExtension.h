#pragma once

namespace app::game{
    class GameModeFishingExtension : public GameModeExtension{
    public:
        static constexpr const char* name = "GameModeFishingExtension";
        
        hh::fnd::Handle<FadeObject> fadeObj;
        float unkCounter;
        float unk2; //related to fadeobject
        char unk3;
        bool paused;

        virtual unsigned int GetNameHash() override;
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        void Update(float deltaTime);

        DEFAULT_CREATE_FUNC(GameModeFishingExtension);
    };
}
