#pragma once

namespace app::game {
    enum class DebuffingType : unsigned char {
        UNK0,
        UNK1,
        UNK2,
        UNK3,
        UNK4,
        UNK5,
    };

    class HealthListener {
    public:
        virtual void PreDealDamage(MsgDamage& message, int damageIn, int& damageOut) {}
        virtual void DamageDealt(MsgDamage& message, int damage, bool stunned, bool staggered) {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void DebuffingStarted(DebuffingType type, float unkParam) {}
        virtual void DebuffingActive(DebuffingType type, float damage) {}
        virtual void DebuffingEnded(DebuffingType type) {}
    };

    class GOCHealth : public hh::game::GOComponent {
    public:
        enum class DamageEffectType {
            STUN,
            STAGGER,
        };

        enum class Flag : unsigned char {
            DEAD,
            UNK1,
            UNK2,
            UNK3,
            ENABLE_STUN_EFFECT,
            ENABLE_STAGGER_EFFECT,
        };

        enum class DeathAction : unsigned char {
            SHUTDOWN,
            KILL,
            RESPAWN,
        };
        

        struct SetupInfo {
            int currentHealth{};
            int maxHealth{};
            float stunThreshold{};
            float stunCheckInterval{};
            float stunDamageDecay{ 1.0f };
            float staggerThreshold{};
            float staggerCheckInterval{ 1.0f };
            float staggerDamageDecay{};
            DeathAction deathAction{};
            float respawnTime{};
            bool performDeathAction{};
            bool byte29{};
            bool byte30{ true };
            csl::math::Vector3 debuffingDirection{ 0.0f, 0.0f, 0.0f };
        };

        struct DamageEffectManager {
            float damageDealt;
            float damageThreshold;
            csl::ut::MoveArray<void*> unk8;
            float damageDecay;
            float checkInterval;
            float timeUntilNextCheck;

            DamageEffectManager();
        };
        
        struct Unk2 {
            csl::math::Vector3 csl__math__vector3160;
            float dword170;
            uint64_t qword178;
            uint16_t word180;
            uint8_t byte182;
        };

        struct Unk3 {
            uint8_t byte150;
            Unk2 byte160;
        };

        struct Unk4 {
            uint8_t byte190;
            uint64_t qword198;
            float multipliers[5];
            float float1B4;
        };

        struct Unk5 {
            uint8_t byte1B8;
            uint32_t dword1BC;
            uint8_t byte1C0;
        };

        struct DebuffingInfo {
            DebuffingType debuffingType;
            float debuffingDamage;
            float qword1D8;
            float timeUntilDebuffingEnds;
            float timeUntilNextDebuffingTick;
            float debuffingTickInterval;
            csl::math::Vector3 debuffingDirection;
        };

        int currentHealth;
        int maxHealth;
        DamageEffectManager damageEffectManagers[2]; // 0 = stun, 1 = stagger
        float damageMultiplier;
        DeathAction deathAction;
        float respawnTime;
        csl::ut::MoveArray<HealthListener*> listeners;
        csl::ut::MoveArray<void*> unk128;
        csl::ut::Bitset<Flag> flags;
        Unk3 unk150;
        Unk4 unk190;
        Unk5 unk1B8;
        DebuffingInfo debuffingInfo;
        bool byte200;
        float dword204;

        GOCHealth(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        void AddListener(HealthListener* listener);
        void RemoveListener(HealthListener* listener);

        DebuffingType GetDebuffingType() const;
        float GetDebuffingDamage() const;
        float GetHealthRatio() const;
        int GetMaxHealth() const;
        void AddHealth(int health);
        void SetGlobalDamageMultiplier(float multiplier);
        void SetDamageMultipliers(float m1, float m2, float m3, float stunMultiplier, float staggerMultiplier);
        void SetHealth(int health);
        void SetStunEffectEnabled(bool enabled);
        void SetStaggerEffectEnabled(bool enabled);
        void SetDamageEffectDamage(DamageEffectType effect, float damage);
        void ResetDamageEffect(DamageEffectType effect);

        void SetUnk3(Unk3& unk3);

        GOCOMPONENT_CLASS_DECLARATION(GOCHealth);
    };
}
