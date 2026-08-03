#pragma once

namespace app{
    namespace enemy {
        class BossPostureStandard : public EnemyPosture {
        public:
            static constexpr const char* name = "BossPostureStandard";

            virtual unsigned int GetNameHash() const override;
            virtual unsigned int UnkFunc2() override { return 0; }
            virtual void Enter() override;

            BossPostureStandard(csl::fnd::IAllocator* allocator);
        };
    };

    class PerceivePartsListener{
    public:
        virtual uint64_t PPL_UnkFunc0() {}
    };

    class BossEventListener {
    public:
        virtual bool HandleStunDamage(app::MsgDamage& msg, float damage) {}
        virtual bool HandleStaggerDamage(app::MsgDamage& msg, float damage) {}
        virtual bool HandleDamage(app::MsgDamage& msg, float damage) {}
        virtual void HandleParry() {}
        virtual void BEL_UnkFunc4() {}
        virtual void HandlePlayerHit() {}
        virtual void BEL_UnkFunc6() {}
    };

    class BossBaseContext : public app_cmn::fsm::GOCHsmContext, public PerceivePartsListener, public TargetPositionHelperListener, public game::HealthListener {
    public:
        struct Camera{
            app_cmn::camera::CameraController* camera;
            unsigned int idx; // used at 0x140360F74
            int unk1;
        };

        struct BattleCollision {
            hh::fnd::Handle<hh::physics::GOCCollider> goc;
            int idx;
        };

        enum class Flags : int64_t{
            UNK0 = 0x8,
            STUNNED = 0xC,
            CAMERA_TIMER_ACTIVE0 = 0x14,
            CAMERA_TIMER_ACTIVE1 = 0x15,
            VISIBILITY0 = 0x1D,
            VISIBILITY1 = 0x1E,
            BOSS_EVENT = 0x21
        };

        app_cmn::rfl::GOCRflParameter* gocRfl;
        GOCTargetPositionHelper* gocTargetPositionHelper;
        hh::fnd::Reference<fnd::HFrameContainer> hFrameContainer;
        hh::fnd::Reference<gfx::MultiNodeContainer> multiNodeContainer;
        hh::fnd::Reference<physics::ColliderContainer> colliderContainer;
        csl::ut::MoveArray<int64_t> qword60;
        csl::ut::MoveArray<hh::fnd::Handle<hh::physics::GOCCollider>> qword80;
        csl::ut::MoveArray<BattleCollision> battleCollisions;
        csl::ut::MoveArray<int64_t> qwordC0;
        csl::ut::MoveArray<int64_t> qwordE0;
        csl::ut::MoveArray<int64_t> qword100;
        csl::ut::MoveArray<Camera> cameraStack;
        heur::rfl::BossLockOnCameraParam cameraParams;
        float bossEventTime;
        float bossEventLength;
        float cameraInterpolationTime1;
        float cameraInterpolationTime0;
        float cameraTimeRemaining;
        float cameraTimeElapsed;
        csl::math::Transform startObjectBossTransform;
        float dword200;
        csl::math::Vector3 cyloopHitPosition;
        csl::math::Vector4 csl__math__vector4220;
        csl::math::Vector4 relatedToLastHit;
        hh::fnd::WorldPosition playerWarpPosition;
        app_cmn::camera::CameraController* currentCamera;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword268; //giganto has HeroSagePoint here
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword288;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword2A8;
        csl::ut::MoveArray<int64_t> qword2C8;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> bossEventListeners;
        csl::ut::MoveArray<hh::fnd::Reference<gfx::ModelAnimationPlayer>> modelAnimationPlayers;
        csl::ut::Bitset<Flags> flags;
        int currentPhase; 
        int dword334; 
        int dword338;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword340;
        csl::ut::MoveArray<BossEventListener*> eventListeners;
        hh::fnd::WorldPosition hh__fnd__worldposition380; // used in giganto's knockback state process message
        int16_t word3A0; //prolly flags
        csl::ut::InplaceMoveArray<int64_t, 2> qword3A8;
        
        virtual uint64_t PPL_UnkFunc0() override;
        virtual int8_t TPHL_UnkFunc0() override { return 0; }
        virtual void DamageDealt(MsgDamage& message, int damage, bool stunned, bool staggered) override;

        virtual void Update(hh::fnd::UpdatingPhase phase, hh::fnd::SUpdateInfo& updateInfo);
        virtual void SetGameObject(hh::game::GameManager* gameManager, hh::game::GameObject* gameObject);
        virtual void SetVisibility(bool visible, char a3);
        virtual bool GetUnkFlag0();
        virtual void SetUnkFlag0(bool enabled);
        virtual int64_t GetIdleStateID() { return 0; }
        virtual bool SetCurrentState(int stateIdx) { return 0; } //not sure
        virtual bool ExecuteState(int stateIdx);
        virtual int64_t SetCurrentPhase(int currentPhase);
        virtual int64_t EndFight(char a2, bool shouldClearIsland); //a2 is related to clearisland msg
        virtual int64_t StartBossEvent();
        virtual int64_t EndBossEvent();
        virtual void KillBoss();
        virtual bool KillPlayer() = 0;
        virtual void HandleDamage(app::MsgDamage& msg); //unsure
        virtual const char* GetBossStateName(int stateIdx);

        void AddCameraController(app_cmn::camera::CameraController* cam, int unk);
        gfx::ModelAnimationPlayer* AddModelAnimationPlayer(hh::gfx::GOCVisualModel* gocVisualModel);
        app_cmn::fsm::GOCHsm2* GetGOCHsm2();
        app_cmn::rfl::GOCRflParameter* GetGOCRflParameter();
        void AddNode(hh::gfx::GOCVisualModel* model, const char* name);
        void ShowBossLifeGauge(bool show, bool hide);
        void InitColliderActivity();
        int ChangeCamera(int controllerId, bool overwriteCurrent, float interpolationTime, int unk0, int interpolationType);
        void ChangeCamera(app_cmn::camera::CameraController* camController, float bossEventLength, float camInterpolationTime1, float camInterpolationTime0, float camTimeRemaining);
        void ChangeToFollowCamera();
        void AddCollider(hh::physics::GOCCollider* collider, int flags);
        void GetHFramesByName(const char* name, csl::ut::MoveArray<hh::fnd::HFrame*>& out);
        hh::gfx::ModelNodeHFrame* GetModelNodeHFrame(unsigned int& visualModelNameHash, const char* nodeName);
        GOCTargetPositionHelper* GetTargetPositionHelper();
        void AddEventListener(BossEventListener* listener);
        void RemoveEventListener(BossEventListener* listener);
        void SetCameraParameters(heur::rfl::BossLockOnCameraParam* cameraParams, bool includeEasing);
        void SetCameraParameters(bool includeEasing);
        void DisableBattleCollisions();
        void GetCollidersByFlag(int flag, csl::ut::MoveArray<hh::physics::GOCCollider*>& out);
        void ResetCamera();
        void ResetVelocity();
        bool DoesCameraExist(unsigned int idx);
        void DestroyCamera(unsigned int idx);
        void SetEnableColliders(bool enabled);
        void SendMessageToPlayer(hh::fnd::Message& message);
        heur::rfl::BossPhaseParam* GetBasePhaseParam(unsigned int phase) const;

        BossBaseContext(csl::fnd::IAllocator* allocator);
    };
}