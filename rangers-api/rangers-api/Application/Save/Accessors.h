#pragma once

namespace app::save {
    class ActionChainLogAc : public SaveDataAccessor<ActionChainStruct> {
    public:

    };

    class CyberStageAc : public SaveDataAccessor<CyberStageData> {
    public:
        // Might be a specific flag accessor. It adds 2 to the index.
        bool GetFlag(unsigned char idx) const;
    };

    class CyberStageContainerAc : public SaveDataAccessor<CyberStageContainerData> {
    public:
        CyberStageAc GetCyberStageAc(unsigned int stageNo);
    };

    class ArcadeDataAc : public SaveDataAccessor<ArcadeData> {
    public:
        CyberStageContainerAc GetCyberStageContainerAc();
    };

    class ChallengeBattleRushContainerDataAc : public SaveDataAccessor<ChallengeBattleRushContainerData> {
    public:

    };

    class ChallengeBattleRushDataAc : public SaveDataAccessor<ChallengeBattleRushData> {
    public:

    };

    class ChallengeCyberStageContainerDataAc : public SaveDataAccessor<ChallengeCyberStageContainerData> {
    public:

    };

    class ChallengeCyberStageDataAc : public SaveDataAccessor<ChallengeCyberStageData> {
    public:

    };

    class ChallengeDataAc : public SaveDataAccessor<ChallengeData> {
    public:

    };

    class CharacterAc : public SaveDataAccessor<CharacterData> {
    public:
        char GetRingLevel() const;
        char GetSpeedLevel() const;
        char GetPowerLevel() const;
        char GetGuardLevel() const;
        short GetNumRings() const;
        short GetBoostGaugeLevel() const;
        bool HasChaosEmeralds() const;
		void SetRingCount(uint16_t count);
		void SetQuickCyloopGauge(float gauge);
    };

    class ExtraCharacterAc : public SaveDataAccessor<ExtraCharacterData> {
    public:
        float GetBossRushQuickCyloopGauge() const;
        int GetBossRushNumRings() const;
		void SetBossRushNumRings(unsigned int rings);
		void SetBossRushQuickCyloopGauge(unsigned int cyloopGauge);
    };

    class ExtraCharacterContainerAc : public SaveDataAccessor<ExtraCharacterContainerData> {
    public:
        ExtraCharacterAc GetExtraCharacterAccessor(unsigned int idx);
        CharacterAc GetCharacterAccessor(unsigned int idx);
    };

    class ExtraCyberStageContainerAc : public SaveDataAccessor<ExtraCyberStageContainerData> {
    public:

    };

    class ExtraFlagAc : public SaveDataAccessor<ExtraFlagData> {
    public:

    };

    class ExtraFlagContainerAc : public SaveDataAccessor<ExtraFlagContainerData> {
    public:
        ExtraFlagAc GetExtraFlagAccessor();
    };

    class ExtraIslandStageContainerAc : public SaveDataAccessor<ExtraIslandStageContainerData> {
    public:

    };

    class FlagContainerAc : public SaveDataAccessor<FlagContainerData> {
    public:

    };

    class WeatherAc : public SaveDataAccessor<WeatherData> {
    public:
        void SetData(WeatherData* data);
    };

    class GamePlayAc : public SaveDataAccessor<GamePlayData> {
    public:
        void SetTime(game::Timestamp& time);
        bool GetTime(game::Timestamp& time);
        GamePlayData::SequenceDeprecated GetSequence() const;
        bool GetCharacter(uint8_t& id) const;
        void SetCharacter(uint8_t& id);
        bool GetWorldPosition(hh::fnd::WorldPosition& position) const;
        void SetWorldPosition(hh::fnd::WorldPosition& position);
    };

    class HeaderAc : public SaveDataAccessor<HeaderData> {
    public:
        HeaderData::Sequence GetSequence() const;
    };

    class GameDataAc : public SaveDataAccessor<GameData> {
    public:
        FlagContainerAc GetFlagContainerAc();
        WeatherAc GetWeatherAccessor();
        GamePlayAc GetGamePlayAccessor();
        ExtraFlagContainerAc GetExtraFlagContainerAccessor();
        ExtraCharacterContainerAc GetExtraCharacterContainerAccessor();
        CharacterAc GetCharacterAccessor();
        HeaderAc GetHeaderAccessor();
    };

    class IslandStageAc : public SaveDataAccessor<IslandStageData> {
    public:

    };

    class IslandStageContainerAc : public SaveDataAccessor<IslandStageContainerData> {
    public:

    };

    class OptionAudioAc : public SaveDataAccessor<OptionAudioData> {
    public:
        unsigned char GetMasterVolume() const;
        unsigned char GetSfxVolume() const;
        unsigned char GetMusicVolume() const;
        unsigned char GetVoiceVolume() const;
        app::save::OptionAudioData::MusicSelect GetMusicSelectEnable() const;
        app::save::OptionAudioData::MusicSelectType GetMusicSelectType() const;
        bool GetBoostAisac() const; // == flag 0
    };

    class OptionCameraAc : public SaveDataAccessor<OptionCameraData> {
    public:

    };

    class OptionControlsAc : public SaveDataAccessor<OptionControlsData> {
    public:
        static uint32_t GetInputID(OptionControlsData::InputKey inputKey);

        OptionControlsData::InputKey GetMainMapping(unsigned int idx) const;
    };

    class OptionGamePlayAc : public SaveDataAccessor<OptionGamePlayData> {
    public:
        uint8_t GetDLCSonicCostume() const;
        uint8_t GetIslandVisual() const;
        OptionGamePlayData::LanguageType GetLanguageType() const;
    };

    class OptionGraphicsAc : public SaveDataAccessor<OptionGraphicsData> {
    public:
        unsigned short GetWidth() const;
        unsigned short GetHeight() const;
        unsigned char GetBrightness() const;
        OptionGraphicsData::GraphicQuality GetQuality() const;
        OptionGraphicsData::Shadow GetShadow() const;
        OptionGraphicsData::FrameRate GetFrameRate() const;
        OptionGraphicsData::AntiAliasing GetAntiAliasing() const;
        OptionGraphicsData::Bloom GetBloom() const;
        OptionGraphicsData::VolumetricLight GetVolumetricLight() const;
        OptionGraphicsData::RederingScale GetRenderingScale() const;
    };

    class OptionAc : public SaveDataAccessor<OptionData> {
    public:
        OptionAudioAc GetOptionAudioAc();
        OptionCameraAc GetOptionCameraAc();
        OptionControlsAc GetOptionControlsAc();
        OptionGamePlayAc GetOptionGamePlayAc();
        OptionGraphicsAc GetOptionGraphicsAc();
        HeaderData::AppVersion GetAppVersion() const;
    };

    class PlayLogAc : public SaveDataAccessor<PlayLogData> {
    public:

    };

    class WorldFlagAc : public SaveDataAccessor<WorldFlagData> {
    public:

    };

    class WorldFlagContainerAc : public SaveDataAccessor<WorldFlagContainerData> {
    public:

    };
}
