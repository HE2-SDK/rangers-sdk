#pragma once

namespace app::player {
    class BlackboardStatus : public BlackboardContent {
    public:
        enum class StateFlag : unsigned int
        {
            BOOST = 0x00,
            AIR_BOOST = 0x04,
            GRIND_JUMP = 0x06,
            GRIND = 0x07,
            JUMP = 0x08,
            DOUBLE_JUMP = 0x09,
            BOUNCE_JUMP = 0x0A,
            FALL = 0x0B,
            STOMP = 0x0C,
            DIVING = 0x0D,
            DIVING_BOOST = 0x0E,
            CYLOOP = 0x11,
            CYLOOP_END = 0x12,
            DRIFT = 0x13,
            HOMING = 0x17,
            PARRY = 0x18,
            WALL_CLIMB = 0x19,
            IDLE = 0x1A,
            WALL_CLIMB_IDLE = 0x1C,
            BOARDING = 0x1E,
            SPRING_JUMP = 0x21,
            SPIN_DASH = 0x22,
        };

        enum class CombatFlag : unsigned int
        {
            JUMP = 0x0,
            UNK_01 = 0x01,
            UNK_02 = 0x02,
            BOOST = 0x03,
            UNK_04 = 0x04,
            SIDE_STEP = 0x05,
            UNK_06 = 0x06,
            UNK_0C = 0x0C,
            PARRY = 0x0F,
            PERFECT_PARRY = 0x10,
            UNK_13 = 0x13,
            UNK_17 = 0x17,
            UNK_18 = 0x18,
            AIR_TRICK = 0x1A,
            UNK_1C = 0x1C,
            UNK_1D = 0x1D,
            UNK_1E = 0x1E,
            CAMERA_MOVEMENT = 0x1F,
            MOVEMENT = 0x20,
            GRAND_SLAM = 0x22,
            UNK_26 = 0x26,
            QUICK_CYLOOP = 0x28,
            PHANTOM_RUSH = 0x2A,
            CYCLONE_KICK = 0x2B,
            RECOVERY_SMASH = 0x2C,
            SONIC_BOOM = 0x2E,
            WILD_RUSH = 0x2F,
            LOOP_KICK = 0x30,
            SPIN_SLASH = 0x31,
            STOMP_ATTACK = 0x32,
            HOMING_SHOT = 0x34,
            CROSS_SLASH = 0x35,
            AUTO_COMBO = 0x39,
            UNK_3B = 0x3B,
            UNK_3C = 0x3C,
            UNK_3D = 0x3D,
            UNK_3E = 0x3E,
            SPIN_DASH = 0x3F,
            DECELERATION_RATE_MAXED_OUT = 0x40, // or potentially at zero
        };

        enum class WorldFlag : unsigned int
        {
            KILLED = 0x01,
            DAMAGED_OR_REPELLED = 0x02,
            OUT_OF_CONTROL = 0x07,
            AUTO_RUN = 0x0A,
            UNK_1B = 0x1B,
            CYBER_SPACE = 0x1E,
            WALL_JUMP_LAND = 0x22,
            POWER_BOOST = 0x28,
            UNK_29 = 0x29,
            AIR_TRICK = 0x2A,
            UNK_35 = 0x35,
            HEIGHT_MAP_COLLISION = 0x37,
            NO_CLIP = 0x38,
            BATTLE = 0x3A,
            NITRO_BOOST = 0x43,
            MAX_SPEED_CHALLENGE = 0x44,
        };

        enum class Dimension : unsigned int {

        };

        enum class FormState : unsigned int {
            NORMAL,
            SUPER,
            UNK0
        };

        struct Description {
            char playerId;
            CharacterIdU8 characterId;
        };

        static constexpr const char* name = "BlackboardStatus";
        uint8_t byte20;
        CharacterIdU8 characterId;
        FormState formState;
        csl::ut::Bitset<CombatFlag, uint64_t> combatFlags[2];
        csl::ut::Bitset<StateFlag, uint64_t> stateFlags;
        csl::ut::Bitset<WorldFlag, uint64_t> worldFlags[2];
        float outOfControlTime;
        float inControlTime;
        uint64_t qword58;
        uint32_t dword60;
        uint32_t dword64;
        ut::PriorityList<bool, hh::fnd::Handle<hh::fnd::Messenger>> qword68;
        csl::ut::InplaceMoveArray<uint32_t, 4> qword90;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordC0;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordF0;
        uint32_t dword120[2];
        Dimension lastDimension;
        ut::PriorityList<Dimension, hh::fnd::Handle<hh::fnd::Messenger>> dimension;
        csl::math::Vector4 oword160;
        uint32_t dword170; //handle
        uint32_t qword174;
        uint32_t qword178;
        uint8_t dword17C;
        uint8_t dword17D;
        uint16_t dword17E;
        app::save::OptionGamePlayData::Value difficulty;
        uint32_t qword184;
        uint32_t qword188;

        virtual unsigned int GetNameHash() const override;

        void Setup(Description& desc);
        Dimension GetDimension() const;
        bool HasQword90() const;
        int GetDword60() const;
        int GetDword64() const;
        int GetDword120(unsigned int idx) const;
        int* GetDword174() const;
        bool GetCombatFlag(CombatFlag combatFlag);
        bool GetInvDimension() const;
        bool HasQwordF0() const;
        bool HasQwordC0() const;
        void ResetCombatFlag(CombatFlag combatFlag);
        void ResetWorldFlag(WorldFlag worldFlag);
        void SetStateFlag(StateFlag stateFlag, bool enabled);
        void SetFormState(FormState state);
        void SetCombatFlag(CombatFlag combatFlag, bool enabled);
        void SetWorldFlag(WorldFlag worldFlag, bool enabled);
        bool GetStateFlag(StateFlag stateFlag);
        bool GetWorldFlag(WorldFlag worldFlag);
        void Set17DFlag(unsigned char flag, bool enabled);
        void UnkFunc1421(unsigned int nameHash);
        FormState GetFormState() const;
        CharacterIdU8 GetCharacterId() const;

        DEFAULT_CREATE_FUNC(BlackboardStatus);
    };
}
