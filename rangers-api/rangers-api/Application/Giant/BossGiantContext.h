#pragma once

namespace app{
    class BossGiantContext : public BossBaseContext, public game::GOCFootListener {
    public:
        int32_t giantFlags;
        int32_t qword3E4;
        game::GOCBossActionSelect* bossActionSelect;
        game::GOCBossPillar* bossPillar;
        game::GOCHealth* gocHealth;
        int32_t currentState;
        int16_t word404;
        int64_t qword408;
        int64_t qword410;
        hh::fnd::Reference<hh::fnd::HFrame> ringSpawnHFrame;
        int32_t damageEffectStage;
        int64_t dword428;
        csl::ut::InplaceMoveArray<hh::physics::GOCMeshCollider*, 2> meshColliders;
        float dword468;
        hh::fnd::Handle<hh::fnd::Messenger> dword46C;
        int32_t dword470;
        int32_t dword474;
        int32_t dword478;

        virtual uint64_t PPL_UnkFunc0() override;
        virtual int8_t TPHL_UnkFunc0() override { return 0; }
        virtual void PreDealDamage(MsgDamage& message, int damageIn, int& damageOut) override;
        virtual void DamageDealt(MsgDamage& message, int damage, bool stunned, bool staggered) override;
        virtual void GFL_UnkFunc0(int64_t a2, int a3) override;

        virtual void Update(hh::fnd::UpdatingPhase phase, hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void SetGameObject(hh::game::GameManager* gameManager, hh::game::GameObject* gameObject) override;
        virtual void SetVisibility(bool visible, char a3) override;
        virtual int64_t GetIdleStateID() override;
        virtual bool SetCurrentState(int stateIdx) override;
        virtual bool ExecuteState(int stateIdx) override;
        virtual int64_t SetCurrentPhase(int currentPhase) override;
        virtual int64_t EndFight(char a2, bool shouldClearIsland) override;
        virtual void KillBoss() override;
        virtual bool KillPlayer() override;
        virtual const char* GetBossStateName(int stateIdx) override;

        heur::rfl::BossGiantConfig* GetConfig() const;
        heur::rfl::BossGiantPhaseParam* GetPhaseParam(unsigned int phase) const;
        heur::rfl::BossGiantPhaseParam* GetCurrentPhaseParam() const;
        bool UpdateDamageEffectStage();
        void UpdateDamageEffect();
        void UpdateRingSpawnHFrame();
        void ExecuteState1(unsigned char unk0);
        void SpawnRings(unsigned int ringAmount);
        bool ShouldCounterInCyloop() const;

        BossGiantContext(csl::fnd::IAllocator* allocator);
    };
}
