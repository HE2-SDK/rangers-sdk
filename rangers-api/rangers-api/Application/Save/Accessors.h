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
        bool GetFlag2And4() const;
    };

    class ExtraCharacterAc : public SaveDataAccessor<ExtraCharacterData> {
    public:
        float GetBossRushQuickCyloopGauge() const;
        int GetBossRushNumRings() const;
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
        bool GetFlag2() const;
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

    };

    class OptionGamePlayAc : public SaveDataAccessor<OptionGamePlayData> {
    public:
        uint8_t GetDLCSonicCostume() const;
        bool GetConfigFlag3() const;
        bool GetConfig2Flag0() const;
        bool GetConfig2Flag3() const;
        bool GetConfig2Flag4() const;
        bool GetConfig2Flag20() const;
        float GetMaxSpeedRate() const;
        float GetInitialSpeedRate() const;
        float GetBoostInitialSpeedRate() const;
        float GetMinTurnSpeedRate() const;
        float GetBoostMinTurnSpeedRate() const;
        float GetAcceleRate() const;
        float GetRotateForceRate() const;
        float GetBumpJumpGravityRate() const;
        float GetBaseAirDragScaleRate() const;
        OptionGamePlayData::Value GetDifficulty() const;
        unsigned char GetNeutralDecelerationRate() const;
    };

    class OptionGraphicsAc : public SaveDataAccessor<OptionGraphicsData> {
    public:

    };

    class OptionAc : public SaveDataAccessor<OptionData> {
    public:
        OptionAudioAc GetOptionAudioAc();
        OptionCameraAc GetOptionCameraAc();
        OptionControlsAc GetOptionControlsAc();
        OptionGamePlayAc GetOptionGamePlayAc();
        OptionGraphicsAc GetOptionGraphicsAc();
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
