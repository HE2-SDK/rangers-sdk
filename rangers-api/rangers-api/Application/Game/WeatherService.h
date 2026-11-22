#pragma once

namespace app::game {
    class WeatherService
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public hh::game::GameManagerListener
        , public app::save::SaveManagerListener
        , public app::game::TimeServiceListener
    {
    public:
        TimeService* timeService;
        save::SaveManager* saveManager;
        bool update;
        uint32_t unk3;
        save::WeatherData::Type currentWeather;
        save::WeatherData::Type prevWeather;
        float unk5;
        app::ut::Timer timer;
        save::WeatherBlockData::Type weather;
        Timestamp currentTime;
        save::WeatherBlockData::Status status;
        Timestamp unk10;
        Timestamp unk11;
        Timestamp unk12;
        Timestamp unk13;
        Timestamp unk14;
        Timestamp unk15;
        Timestamp unk16;
        uint64_t unk17;
        uint8_t unk18;
    
		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual void OnSave(save::SaveManager* saveMgr) override;
        virtual void TimeChangeCallback(const Timestamp& previousTime, const Timestamp& currentTime) override;

        void SetWeather(save::WeatherBlockData::Type type, float length);
        bool SetWeatherEx(save::WeatherBlockData::Type type, float length);
        void ForceWeather(save::WeatherBlockData::Type type);
        void ResetWeather(float length);

        GAMESERVICE_CLASS_DECLARATION(WeatherService);
    };
}
