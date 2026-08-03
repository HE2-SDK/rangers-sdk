#pragma once

namespace app {
    class MsgDamage;
}

namespace app::player {
    class MsgAddNotifyPreDeadListener : public fnd::AppMessage<MsgAddNotifyPreDeadListener> {
    public:
        MsgAddNotifyPreDeadListener() : fnd::AppMessage<MsgAddNotifyPreDeadListener>{ hh::fnd::MessageID::ADD_NOTIFY_PRE_DEAD_LISTENER } {}
    };

    class MsgGetHomingTargetInfo : public fnd::AppMessage<MsgGetHomingTargetInfo> {
    public:
        HomingTargetInfo homingTargetInfo{};

        MsgGetHomingTargetInfo() : fnd::AppMessage<MsgGetHomingTargetInfo>{ hh::fnd::MessageID::GET_HOMING_TARGET_INFO } {}
    };

    class MsgDead : public fnd::AppMessage<MsgDead> {
    public:
        uint32_t unk1{};
        float unk2{ -1.0f };
        short unk3{ -1 };

        MsgDead() : fnd::AppMessage<MsgDead>{ hh::fnd::MessageID::DEAD } {}
    };

    class MsgTakeNitroBoost : public fnd::AppMessage<MsgTakeNitroBoost> {
    public:
        bool canAirBoost{};

        MsgTakeNitroBoost() : fnd::AppMessage<MsgTakeNitroBoost>{ hh::fnd::MessageID::TAKE_NITRO_BOOST } {}
    };

    class MsgHoldOn : public fnd::AppMessage<MsgHoldOn> {
    public:
        float unk{ 0 }; // probably time for how long the player should hold on
        char unk1{ 1 };
        int unk2{ 128 };

        MsgHoldOn() : fnd::AppMessage<MsgHoldOn>{ hh::fnd::MessageID::HOLD_ON } {}
    };

    class MsgHoldRelease : public fnd::AppMessage<MsgHoldRelease> {
    public:
        int unk0{ 0 };
        hh::fnd::WorldPosition releasePosition{}; // guessed
        char unk1{ 0 };

        MsgHoldRelease() : fnd::AppMessage<MsgHoldRelease>{ hh::fnd::MessageID::HOLD_RELEASE} {}
    };
    
    class MsgHoldEnd : public fnd::AppMessage<MsgHoldEnd> {
    public:
        MsgHoldEnd() : fnd::AppMessage<MsgHoldEnd>{ hh::fnd::MessageID::HOLD_END} {}
    }; 

    class MsgWarpToPoint : public fnd::AppMessage<MsgWarpToPoint> {
    public:
        hh::fnd::WorldPosition warpTarget{};
        int64_t unk0{ 0 };
        char unk1{ 0 };

        MsgWarpToPoint() : fnd::AppMessage<MsgWarpToPoint>{ hh::fnd::MessageID::WARP_TO_POINT} {}
    };

    class MsgBeginExternalControl : public fnd::AppMessage<MsgBeginExternalControl> {
    public:
        hh::fnd::WorldPosition unk0{};
        int unk1{ 0 };
        char unk2{ 0 };
        char unk3{ 0 };

        MsgBeginExternalControl() : fnd::AppMessage<MsgBeginExternalControl>{ hh::fnd::MessageID::BEGIN_EXTERNAL_CONTROL} {}
    };

    class MsgEndExternalControl : public fnd::AppMessage<MsgEndExternalControl> {
    public:
        short unk0{ 0 };

        MsgEndExternalControl() : fnd::AppMessage<MsgEndExternalControl>{ hh::fnd::MessageID::END_EXTERNAL_CONTROL} {}
    };

    class MsgChangeDamageState : public fnd::AppMessage<MsgChangeDamageState> {
    public:
        csl::math::Vector3 attackVelocity{ 0, 0, 0 };
        MsgDamage* damageMsg{ nullptr };
        int unk1{ 0 };

        MsgChangeDamageState(csl::math::Vector3& attackVelocity);
        MsgChangeDamageState() : fnd::AppMessage<MsgChangeDamageState>{ hh::fnd::MessageID::CHANGE_DAMAGE_STATE} {}
    };
}