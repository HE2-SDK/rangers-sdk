#pragma once

namespace app::gfx {
    class FxParamWeatherExtension : public FxParamExtension, public hh::game::GameManagerListener, public evt::EventPlayerListener {
    public:
        evt::EventPlayer* eventPlayer;
        camera::CameraService* cameraService;
        heur::rfl::WeatherFxParameter weatherParam0;
        heur::rfl::WeatherFxParameter weatherParam1;
        hh::needle::FxAtmosphereParameter atmosphereParam0;
        game::WeatherService* weatherService;
        game::TimeService* timeService;
        short unk0;
        char unk1;

        FxParamWeatherExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void UnkFunc1() override;
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) override;
        virtual void BeforeSetParameter(hh::fnd::SUpdateInfo* updateInfo, hh::needle::NeedleFxParameter* needleFxParameter) override;

        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
    };
}
