#pragma once

namespace app::ui {
    class MsgUIChangePlayerCharacter : public fnd::AppMessage<MsgUIChangePlayerCharacter> {
    public:
        player::CharacterIdU8 characterId;
        
        MsgUIChangePlayerCharacter(player::CharacterIdU8 characterId) : fnd::AppMessage<MsgUIChangePlayerCharacter>{ hh::fnd::MessageID::UI_CHANGE_PLAYER_CHARACTER }, characterId{ characterId } {}
    };

    class MsgUISetGameCockpitVisibility : public fnd::AppMessage<MsgUISetGameCockpitVisibility> {
    public:
        size_t uiMask;
        bool visible;

        MsgUISetGameCockpitVisibility(size_t uiMask, bool visible) : fnd::AppMessage<MsgUISetGameCockpitVisibility>{ hh::fnd::MessageID::UI_SET_GAME_COCKPIT_VISIBILITY }, uiMask{ uiMask }, visible{ visible } {}
    };

    class MsgUINotifyUpdatePosition : public fnd::AppMessage<MsgUINotifyUpdatePosition> {
    public:
        char unk0{ 2 };

        MsgUINotifyUpdatePosition() : fnd::AppMessage<MsgUINotifyUpdatePosition>{ hh::fnd::MessageID::UI_NOTIFY_UPDATE_POSITION } {}
    };

    class MsgUICharacterActionGuide : public fnd::AppMessage<MsgUICharacterActionGuide> {
    public:
        char button{ 0 };
        int64_t unk0{ 0 };
        int unk1{ 0 };
        csl::math::Vector4 unk2{};
        char unk3{ 0 };
        csl::math::Vector4 unk4{};
        char unk5{ 0 };
        int unk6{ 0 };
        int unk7{ 0 };
        
        MsgUICharacterActionGuide() : fnd::AppMessage<MsgUICharacterActionGuide>{ hh::fnd::MessageID::UI_CHARACTER_ACTION_GUIDE } {}
    };

    class MsgUIEndGameCockpitDestination : public fnd::AppMessage<MsgUIEndGameCockpitDestination> {
    public:
        int unk{ 0 };
        
        MsgUIEndGameCockpitDestination() : fnd::AppMessage<MsgUIEndGameCockpitDestination>{ hh::fnd::MessageID::UI_END_GAME_COCKPIT_DESTINATION } {}
    };

    class MsgUIBossLifeGaugeAppear : public fnd::AppMessage<MsgUIBossLifeGaugeAppear> {
    public:
        enum class BOSS_TYPE : unsigned char {
            NONE,
            GIANT,
            DRAGON,
            KNIGHT,
            RIFLE,
            THE_END,
            THE_END2
        };

        BOSS_TYPE bossType{ BOSS_TYPE::NONE };
        
        MsgUIBossLifeGaugeAppear() : fnd::AppMessage<MsgUIBossLifeGaugeAppear>{ hh::fnd::MessageID::UI_BOSS_LIFE_GAUGE_APPEAR } {}
    };

    class MsgUIBossLifeGaugeVisibility : public fnd::AppMessage<MsgUIBossLifeGaugeVisibility> {
    public:
        bool isVisible{ true };
        
        MsgUIBossLifeGaugeVisibility() : fnd::AppMessage<MsgUIBossLifeGaugeVisibility>{ hh::fnd::MessageID::UI_BOSS_LIFE_GAUGE_VISIBILITY } {}
    };

    class MsgUIBossLifeGaugeDisappear : public fnd::AppMessage<MsgUIBossLifeGaugeDisappear> {
    public:
        MsgUIBossLifeGaugeDisappear() : fnd::AppMessage<MsgUIBossLifeGaugeDisappear>{ hh::fnd::MessageID::UI_BOSS_LIFE_GAUGE_DISAPPEAR } {}
    };
}
