#pragma once

namespace app::player {
    class Player;
    class StateParameter;
    class GOCPlayerHsm;
    class GOCPlayerPosture;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class BlackboardItem;
    class PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener {
        class OutOfControlTimerList : public PlayerCounterTimer {
            PlayerHsmContext* pPlayerHsmContext;
        public:
            OutOfControlTimerList(csl::fnd::IAllocator* pAllocator);
        };

        class DamagedObjects : public hh::fnd::BaseObject {
            csl::ut::MoveArray<void*> objects;
        public:
            DamagedObjects(csl::fnd::IAllocator* pAllocator);
        };

    public:
        Player* playerObject;
        BlackboardStatus* blackboardStatus;
        BlackboardItem* blackboardItem;
        GOCPlayerHsm* gocPlayerHsm;
        GOCPlayerPosture* gocPlayerPosture;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        csl::ut::MoveArray<void*> unk8;
        OutOfControlTimerList* pOutOfControlTimerList;
        DamagedObjects* pDamagedObjects;

        PlayerHsmContext(csl::fnd::IAllocator* pAllocator);
        ~PlayerHsmContext();

        void Setup(GOCPlayerHsm* gocPlayerHsm);

        app::player::Player* GetPlayerObject() const;
        float GetInControlTime() const;
        void ChangeState(int stateId, unsigned int priority);
        bool IsSuper() const;
        void PlayEffectAtNode(const char* effectName, int nodeIdx);
        CharacterIdU8 GetCharacterId() const;
        bool IsOutOfControl() const;
        bool IsAutoRun() const;
        void AddParam(StateParameter* param);
        heur::rfl::PlayerParamCommon* GetPlayerParamCommon() const;
        heur::rfl::PlayerParamCombo& GetComboParameters() const;
        heur::rfl::PlayerParamSonicBoom& GetSonicBoomParameters() const;
        void ChangeStateRestart(int stateId, unsigned int priority);
        bool TestActionMonitor(int actionMonitorIdx) const; 
        bool TestActionMonitor2(int actionMonitorIdx) const; 
        bool GetCombatFlag(BlackboardStatus::CombatFlag combatFlag) const;
        bool GetStateFlag(BlackboardStatus::StateFlag stateFlag) const;
        bool GetWorldFlag(BlackboardStatus::WorldFlag worldFlag) const;
        void SetCombatFlag(BlackboardStatus::CombatFlag combatFlag, bool enabled);
        void SetStateFlag(BlackboardStatus::StateFlag stateFlag, bool enabled);
        void SetWorldFlag(BlackboardStatus::WorldFlag worldFlag, bool enabled);
        void DisableCombatFlag(BlackboardStatus::CombatFlag combatFlag);
        void DisableStateFlag(BlackboardStatus::StateFlag stateFlag);
        void DisableWorldFlag(BlackboardStatus::WorldFlag worldFlag);
        void ChangeState(const char* stateName);
        int GetCurrentState() const;
        bool SendMessageImm(hh::fnd::Handle<hh::fnd::Messenger>& receiver, hh::fnd::Message& message);
        csl::math::Vector3 GetKinematicParamsPosition() const;
        csl::math::Quaternion GetKinematicParamsRotation() const;
        void ResetKinematicParamsVelocity();
        void CreateCameraInterpolator(unsigned int controllerId, int type);
        csl::math::Vector3 GetForwardTargetPosition() const;
        void Update(hh::fnd::UpdatingPhase phase, float deltaTime);
		void SetPause(bool paused);
		void SetFixed(bool paused);
        void ChangeBottomState(int state);
        void SetVisualLocatorStandFlat();

        static hh::snd::SoundHandle PlaySound(PlayerHsmContext* ctx, const char* soundName);
        
        virtual void OnSave(save::SaveManager* saveMgr) override;
    };
}
