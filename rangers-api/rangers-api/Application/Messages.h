#pragma once

namespace app {
    class MsgDamage : public fnd::AppMessage<MsgDamage> {
    public:
        enum class ParryFlags : unsigned int {
            ENABLED,
            SLOW,
            UNK0,
            UNK1,
            JUST,
            SPECIAL_CAMERA_ANIM,
            COUNTER_SMASH,
            UNK2
        };

        uint32_t dword20;
        size_t damageFlags; // |= 0x02 - killing, & 0x04 - cyloop, & 0x08 quick cyloop, |= 0x40 - blow off, |= 0x200 - quake?, |= 0x10000000 - only parry
        hh::fnd::Handle<hh::physics::GOCCollider> hitCollider;
        csl::math::Vector3 csl__math__vector440;
        csl::math::Vector3 cyloopPosition;
        csl::math::Vector3 attackVelocity;
        float dword70;
        hh::fnd::Handle<hh::physics::GOCCollider> attackerCollider;
        csl::math::Vector3 csl__math__vector480;
        csl::math::Vector3 csl__math__vector490;
        csl::math::Vector3 csl__math__vector4A0;
        uint32_t damageHP;
        uint32_t dwordB4;
        uint64_t qwordB8;
        float qwordC0;
        csl::ut::Bitset<ParryFlags> parryFlags;
        short practiceUIType; // ObjDamageTestAttack::Kind
        csl::math::Vector3 csl__math__vector4D0;
        csl::math::Vector3 csl__math__vector4E0;
        csl::math::Vector3 csl__math__vector4F0;
        csl::math::Quaternion csl__math__vector4100;
        uint32_t dword110;

        MsgDamage(unsigned int dword20Param, size_t qword28Param);
        void HandleEnter(hh::physics::MsgTriggerEnter& msg);
    };

    class MsgGetCyloopPoint : public fnd::AppMessage<MsgGetCyloopPoint> {
    public:
        hh::fnd::Handle<hh::game::GOComponent> unk1{};
        csl::math::Vector3 position{ 0.0f, 0.0f, 0.0f };
        csl::math::Vector3 normal{ 0.0f, 0.0f, 0.0f };
        float radius{};
        uint32_t unk2{};
        uint32_t unk3{};
        uint8_t unk4{};

        MsgGetCyloopPoint() : fnd::AppMessage<MsgGetCyloopPoint>{ hh::fnd::MessageID::GET_CYLOOP_POINT } {}
    };

    class MsgLossRing : public fnd::AppMessage<MsgLossRing> {
    public:
        enum class Type : unsigned int {
            NORMAL,
            TRACKER_TENTACLE,
            TRACKER_BLACKHOLE,
        };

        int amount{};
        bool all{};
        Type type{};
        int ringsLostAmount{};
        bool ringsLost{};

        MsgLossRing() : fnd::AppMessage<MsgLossRing>{ hh::fnd::MessageID::LOSS_RING } {}
    };

    class MsgNotifyStartMeteorShowerEvent : public fnd::AppMessage<MsgNotifyStartMeteorShowerEvent> {
    public:
        MsgNotifyStartMeteorShowerEvent() : fnd::AppMessage<MsgNotifyStartMeteorShowerEvent>{ hh::fnd::MessageID::NOTIFY_START_METEOR_SHOWER_EVENT } {}
    };

    class MsgNotifyEndMeteorShowerEvent : public fnd::AppMessage<MsgNotifyEndMeteorShowerEvent> {
    public:
        MsgNotifyEndMeteorShowerEvent() : fnd::AppMessage<MsgNotifyEndMeteorShowerEvent>{ hh::fnd::MessageID::NOTIFY_END_METEOR_SHOWER_EVENT } {}
    };

    class MsgNotifyEndMeteorShowerWeather : public fnd::AppMessage<MsgNotifyEndMeteorShowerWeather> {
    public:
        MsgNotifyEndMeteorShowerWeather() : fnd::AppMessage<MsgNotifyEndMeteorShowerWeather>{ hh::fnd::MessageID::END_METEOR_SHOWER_WEATHER } {}
    };

    class MsgTakeObject : public fnd::AppMessage<MsgTakeObject> {
    public:
        enum class Type : unsigned char {
            RING,
            SUPER_RING,
            RED_RING,
            EXP,
            PORTAL_BIT,
            POWER_SEED,
            GUARD_SEED,
            UNK2,
            MEMORY_TOKEN,
            ITEMBOX_PARTS,
            EMERALD_KEY,
            MUSIC_MEMORY,
            UNK5,
            NITRO_BOTTLE,
            STOP_WATCH,
            SILVER_MOON_RING,
            NUMBER_RING
        };

        Type objectType{ Type::RING };
        char flags{ 0 };
        int amount{ 0 };
        bool showEffect{ true };
        int islandIndex{ 0 };
        char expIndex{ 0 };

        MsgTakeObject() : fnd::AppMessage<MsgTakeObject>{ hh::fnd::MessageID::TAKE_OBJECT } {}
    };

    class MsgGetTargetPosition : public fnd::AppMessage<MsgGetTargetPosition> {
    public:
        enum class Position : unsigned char {
            ROOT,
            NECK,
            HEAD,
            SPINE
        };

        bool changed;
        csl::math::Vector3 targetPosition;
        Position position;

        MsgGetTargetPosition() : fnd::AppMessage<MsgGetTargetPosition>{ hh::fnd::MessageID::GET_TARGET_POSITION } {}
    };

    class MsgSpringImpulse : public fnd::AppMessage<MsgSpringImpulse> {
    public:
        csl::math::Vector4 unk0;
        csl::math::Vector3 velocity; //or direction
        csl::math::Vector4 unk1;
        float outOfControlTime;
        float keepVelocityTime;
        int unk2;
        int unk3;

        MsgSpringImpulse() : fnd::AppMessage<MsgSpringImpulse>{ hh::fnd::MessageID::SPRING_IMPULSE } {}
    };

    class MsgAddActionChainScore : public fnd::AppMessage<MsgAddActionChainScore> {
    public:
        int score;
        int ownerHandle;
        int64_t unk0;

        MsgAddActionChainScore() : fnd::AppMessage<MsgAddActionChainScore>{ hh::fnd::MessageID::ADD_ACTION_CHAIN_SCORE } {}
    };

    class MsgFishingReturnToIsland : public fnd::AppMessage<MsgFishingReturnToIsland> {
    public:
        MsgFishingReturnToIsland() : fnd::AppMessage<MsgFishingReturnToIsland>{ hh::fnd::MessageID::FISHING_RETURN_TO_ISLAND } {}
    };

    class MsgFishingChangeCameraMode : public fnd::AppMessage<MsgFishingChangeCameraMode> {
    public:
        int mode;

        MsgFishingChangeCameraMode() : fnd::AppMessage<MsgFishingChangeCameraMode>{ hh::fnd::MessageID::FISHING_CHANGE_CAMERA_MODE } {}
    };

    class MsgRaiseRings : public fnd::AppMessage<MsgRaiseRings> {
    public:
        int ringAmount;

        MsgRaiseRings() : fnd::AppMessage<MsgRaiseRings>{ hh::fnd::MessageID::RAISE_RINGS } {}
    };

    class MsgEndBossEvent : public fnd::AppMessage<MsgEndBossEvent> {
    public:
        MsgEndBossEvent() : fnd::AppMessage<MsgEndBossEvent>{ hh::fnd::MessageID::END_BOSS_EVENT } {}
    };

    class MsgBeginBlockage : public fnd::AppMessage<MsgBeginBlockage> {
    public:
        hh::fnd::Handle<EnemyManager> enemyManager;

        MsgBeginBlockage() : fnd::AppMessage<MsgBeginBlockage>{ hh::fnd::MessageID::BEGIN_BLOCKAGE } {}
    };

    class MsgEndBlockage : public fnd::AppMessage<MsgEndBlockage> {
    public:
        hh::fnd::Handle<EnemyManager> enemyManager;

        MsgEndBlockage() : fnd::AppMessage<MsgEndBlockage>{ hh::fnd::MessageID::END_BLOCKAGE } {}
    };
    
    class MsgBeginBossEvent : public fnd::AppMessage<MsgBeginBossEvent> {
    public:
        MsgBeginBossEvent() : fnd::AppMessage<MsgBeginBossEvent>{ hh::fnd::MessageID::BEGIN_BOSS_EVENT } {}
    };

    // Recipients - Player

    class MsgBeginBossBattle : public fnd::AppMessage<MsgBeginBossBattle> {
    public:
        char unk0{ 1 };
        hh::fnd::Reference<hh::fnd::HFrame> moveableRangeHFrame{ nullptr };
        csl::math::Vector4 unk1{ 0, 300, 0, 3.1415927f };
        float unk2{ 10 };
        float unk3{ 10 };
        int64_t unk4{ 0 };
        int64_t unk5{ 0 };
        int64_t unk6{ 0 };
        int unk7{ 0 };
        char unk8{ 0 };
        char unk9{ 1 };
        csl::math::Vector4 unk10{ 0, 0, 0, 0 };
        int unk12{ 0 }; // When 1, the player gets pulled to the boss
        bool shouldNoclip{ false };

        MsgBeginBossBattle() : fnd::AppMessage<MsgBeginBossBattle>{ hh::fnd::MessageID::BEGIN_BOSS_BATTLE } {}
    };

    class MsgCharacterBeginLookAt : public fnd::AppMessage<MsgCharacterBeginLookAt> {
    public:
        csl::math::Vector3 targetPosition{ 0, 0, 0 };
        float easeInTime{ -1 };

        MsgCharacterBeginLookAt() : fnd::AppMessage<MsgCharacterBeginLookAt>{ hh::fnd::MessageID::CHARACTER_BEGIN_LOOK_AT } {}
    };

    class MsgCharacterEndLookAt : public fnd::AppMessage<MsgCharacterEndLookAt> {
    public:
        float easeOutTime{ -1 };

        MsgCharacterEndLookAt() : fnd::AppMessage<MsgCharacterEndLookAt>{ hh::fnd::MessageID::CHARACTER_END_LOOK_AT } {}
    };
}
