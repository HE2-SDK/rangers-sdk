#pragma once

namespace app {
    class EnemyMotoraInfo : public hh::game::ObjInfo {
    public:
        csl::ut::MoveArray<hh::gfx::ResModel*> modelResources;
        game::ResFixPositionDebris qword58;
        hh::anim::ResSkeleton* skeletonResource;
        hh::animeff::ResParticleLocation* effdbResource;
        hh::fnd::Reference<hh::anim::AsmResourceManager> asmResource;

        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_INLINE(EnemyMotoraInfo);
    };

    class EnemyMotoraContext : public app_cmn::fsm::GOCHsmContext {
    public:
        csl::ut::MoveArray<csl::ut::MoveArray<hh::gfx::GOCVisualModel*>> qword20;
        csl::math::Vector3 startPosition;
        csl::math::Vector3 destinationPosition;
        csl::math::Vector3 playerPosition;
        csl::math::Vector3 directionToPlayer;
        float tireRotationSpeed;

        void SetVisualsVisible(bool visible);
        void SetCollidersEnabled(bool visible);
        csl::math::Vector3 GetDestinationDirection() const;
        void SetTireRotationSpeed(float speed);
        void SwitchDestinationAndPosition();

        EnemyMotoraContext(csl::fnd::IAllocator* allocator);
    };

    class EnemyMotora : public hh::game::GameObject {
    public:
        hh::fnd::Reference<EnemyMotoraContext> context;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(EnemyMotora);
    };  

    class EnemyMotoraState {
    public:
        DECLARE_STATE_DESCS(12);

        class Invisible : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;

            DECLARE_STATE(Invisible);
        };

        class Fall : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Fall);
        };

        class Idle : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            game::GOCEyesight* gocEyesight;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Idle);
        };

        class Move : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            enum class State : unsigned int {
                SWITCHING_DESTINATION,
                GOING_TO_DESTINATION
            };

            State state;
            EnemyMotoraSpawner* spawnerData;
            game::GOCEyesight* gocEyesight;
            hh::snd::SoundHandle moveSound;
            float destinationDistance;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Move);
        };

        class Find : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            hh::anim::GOCAnimator* gocAnimator;
            bool hasReachedTheTarget;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override {}
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Find);
        };

        class Chargeup : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            EnemyMotoraSpawner* spawnerData;
            Timer chargeUpTimer;
            hh::snd::SoundHandle chargeSound;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Chargeup);
        };

        class Rush : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            enum class State : unsigned int {
                START_DASH,
                DASHING
            };

            State state;
            EnemyMotoraSpawner* spawnerData;
            hh::anim::GOCAnimator* gocAnimator;
            game::GOCEyesight* gocEyesight;
            hh::snd::SoundHandle dashSound;
            Timer timerTillLoseSight;
            float distanceToPlayer;
            float distanceToRecognizeObstacle;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual bool DoProcessMessage(const hh::fnd::Message& message) override;

            DECLARE_STATE(Rush);
        };

        class Brake : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            hh::anim::GOCAnimator* gocAnimator;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override {}
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Brake);
        };

        class Crash : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            float height;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override;
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Crash);
        };

        class Land : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            hh::anim::GOCAnimator* gocAnimator;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override {}
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Land);
        };

        class Lost : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            hh::anim::GOCAnimator* gocAnimator;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override {}
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Lost);
        };

        class Die : public app_cmn::fsm::GOCStateBase<EnemyMotoraContext> {
        public:
            float effectTimer;

            virtual void DoEnter(int previousStateId) override;
            virtual void DoLeave(int nextStateId) override {}
            virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override;

            DECLARE_STATE(Die);
        };
    };
}
