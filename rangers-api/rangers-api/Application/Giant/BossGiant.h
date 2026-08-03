#pragma once

namespace app{
    class BossGiantInfo : public hh::game::ObjInfo {
    public:
        struct PhaseResources {
            const char* phaseName;
            csl::ut::MoveArray<hh::fnd::ManagedResource*> resources;
        };

        hh::gfx::ResModel* model;
        hh::anim::ResSkeletonPxd* skeleton;
        hh::anim::ResSkeletonPxd* skeletonCypos;
        hh::fnd::ManagedResource* skinnedMeshCol;
        hh::fnd::ManagedResource* skinnedMeshColLow;
        csl::ut::MoveArray<PhaseResources> phaseResources;
        hh::fnd::Reference<hh::anim::AsmResourceManager> animator;
        hh::animeff::ResParticleLocation* effdb;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::BossGiantConfig>> parameters;
        app::game::ResAIStateMachine* aism;
        int64_t qwordA0;

        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;
        virtual void RegistCallback(hh::game::ObjInfoContainer* container) override;

        OBJINFO_CLASS_DECLARATION(BossGiantInfo)
    };

    class BossGiant : public hh::game::GameObject, public game::ReactiveListener {
    public:
        hh::fnd::Reference<BossGiantContext> context;
        short unk0;
        char unk1;
        int unk2;
        hh::fnd::Reference<hh::physics::ResPhysicsMesh> resPhysicsMesh;
        app_cmn::rfl::GOCRflParameter* rflParam;
        hh::physics::GOCCollider* skinnedMeshCollider;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        virtual int64_t RL_UnkFunc0() override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(BossGiant)
    };

    class BattlePhaseHandBase : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
    public:
        char* countParamName;
        char* atkTypeParamName;
        int64_t qword48;
        float dword50;
        float dword54;
        float dword58;
        csl::ut::String handAnimStateName;
        csl::ut::String unkName;
        csl::math::Transform oword90;
        hh::game::GOCTransform* gocTransform;
        hh::game::GOComponent* gocHand;
        game::GOCHitStop* gocHitStop;
        hh::game::GOComponent* gocRecordNodeInfo;
        game::GOCParamBlackboard* paramBlackboard;
        csl::ut::MoveArray<int64_t> qwordE8;
        void* posture; // enemy::BossPostureBattle
        hh::fnd::Reference<BossGiantContext> context;
        hh::fnd::WorldPosition hh__fnd__worldposition120;
        short flags;

        virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
        virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
        virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
        virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

        virtual int BPHB_UnkFunc0() = 0; // used to set context's 0x408
        virtual void BPHB_UnkFunc1() = 0;
        virtual int BPHB_UnkFunc2() = 0;
        virtual unsigned int AnimationStateCount() = 0;
        virtual const char* GetAnimationStateName(unsigned int idx) = 0;
        virtual void BPHB_UnkFunc5() = 0;
        virtual void BPHB_UnkFunc6() = 0;
        virtual void BPHB_UnkFunc7() = 0;
        virtual void BPHB_UnkFunc8() {}

        virtual bool HandleStaggerDamage(app::MsgDamage& msg, float damage) override;
        virtual void HandleParry() override;
        virtual void HandlePlayerHit() override;

        BattlePhaseHandBase(csl::fnd::IAllocator* allocator);
    };

    class BattlePhaseSpecialCounterBase : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
    public:
        bool playerHit;
        bool parried;
        float dword3C;
        csl::ut::MoveArray32<int64_t> qword40;
        csl::ut::MoveArray32<int64_t> qword58;
        csl::math::Transform bossTransform;
        game::GOCHitStop* gocHitstop;
        void* posture; // enemy::BossPostureBattle
        hh::fnd::Reference<BossGiantContext> context;

        virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
        virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
        virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
        virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

        virtual const char* GetAnimationStateName() = 0;
        virtual void BPSCB_UnkFunc1() = 0;
        virtual hh::fnd::WorldPosition BPSCB_UnkFunc2(BossGiantContext* context, int64_t unk0);
        virtual bool BPSCB_UnkFunc3() { return true; }
        virtual float BPSCB_UnkFunc4() { return 0; }

        virtual void HandleParry() override;
        virtual void HandlePlayerHit() override;

        BattlePhaseSpecialCounterBase(csl::fnd::IAllocator* allocator);
    };

    class BossGiantState {
    public:
        class Idling : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(Idling);
        };

        class WalkingBase : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            hh::path::PathEvaluator path;
            bool relatedToPath;
            float animationTimer;
            bool playShake;
            bool isRightArm;
            char unk4;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingBase);
        };

        class WalkingStart : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            char unk0;
            bool isMoveRight;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingStart);
        };
        
        class WalkingIdleRight : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float turnTimer;

            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingIdleRight);
        };

        class WalkingMoveLeft : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            char unk0;
            bool isMoveRight;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingMoveLeft);
        };

        class WalkingIdleLeft : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float turnTimer;

            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingIdleLeft);
        };

        class WalkingMoveRight : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            char unk0;
            bool isMoveRight;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(WalkingMoveRight);
        };

        class WalkingEnd : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float endTimer;

            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateUpdateAsync(BossGiantContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;

            DEFAULT_CREATE_FUNC(WalkingEnd);
        };

        class BattlePhaseParentBase : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            virtual int64_t BPPB_UnkFunc0() = 0;
            virtual void BPPB_UnkFunc1() {}
        };

        class BattlePhaseParent : public BattlePhaseParentBase, public game::BossActionSelectListener, public BossEventListener {
        public:
            hh::fnd::Reference<BossGiantContext> bossContext;
            hh::fnd::Reference<hh::gfx::ModelNodeHFrame> headHFrame;
            int tutorialOverlayWindowId;
            float tutorialTimer;
            float pillarTimer;
            int32_t unk3b;
            int unk4;
            csl::math::Vector3 targetLookAtPos;
            void* posture; // enemy::BossPostureBattle
            short flags; // 0x02 - tutorial timer; 0x10 - pillar timer
            int64_t unk8;
            hh::fnd::Reference<hh::fnd::HFrame> homingAttackHFrame; //0x1402B2CF0
            float unk10;
            csl::ut::VariableString ringSupplyGroupObjectName;
            int32_t ringObjectiveDisplayJobId;
            float unk12b;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual bool StateInit(BossGiantContext& context) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual int64_t BPPB_UnkFunc0() override;
            virtual void BPPB_UnkFunc1() override;

            virtual bool HandleStunDamage(app::MsgDamage& msg, float damage) override;
            virtual bool HandleDamage(app::MsgDamage& msg, float damage) override;

            void BeginBossRingSupply(BossGiantContext* ctx);
            void SetHomingAttackCollider(BossGiantContext* bossContext, const csl::math::Vector3& position, float radius);
            void SetupAnimationParameters(BossGiantContext* ctx);
            void Initialize(BossGiantContext* ctx);
            void Deinitialize(BossGiantContext* ctx);

            DEFAULT_CREATE_FUNC(BattlePhaseParent);
        };

        class BattlePhaseReset : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            int previousState;    

            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseReset);
        };

        class BattlePhaseParried : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            char unk0;
            char unk0b;
            char unk1;
            float parryTimer;
            float unk3;
            float unk4;
            int unk5;
            int unk6;
            int parriedPart;
            int unk7b;
            int64_t unk8;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseParried);
        };

        class BattlePhaseDamage : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            hh::fnd::Reference<BossGiantContext> bossContext;
            char byte40;
            char byte41;
            int dword44; // related to how many times giganto's been hit in a sequence?
            float hitTimer; // switches back to state 8 after 5 seconds
            csl::ut::String animationStateName;
            void* posture; // enemy::BossPostureBattle

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual bool HandleStaggerDamage(app::MsgDamage& msg, float damage) override;
            virtual bool HandleDamage(app::MsgDamage& msg, float damage) override;

            void InitializeStateName(BossGiantContext* ctx);

            DEFAULT_CREATE_FUNC(BattlePhaseDamage);
        };

        class BattlePhaseKnockBack : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float collisionEnableTimer;
            float dword34;
            float dword38;
            float dword3C;
            char byte40;
            bool skinnedCollisionEnabled;
            char byte42;
            bool shouldWarpPlayer;
            csl::ut::String animationStateName;
            csl::math::Vector3 hitPosition;
            int dword70;
            csl::math::Vector4 csl__math__vector480;
            csl::math::Vector4 csl__math__vector490;
            hh::game::GOCTransform* gocTransform;
            game::GOCHitStop* gocHitstop;
            void* posture; // enemy::BossPostureBattle

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseKnockBack);
        };

        class BattlePhaseDown : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            enum class Flags : unsigned short {
                TIMER_ENABLED,
                STUNNED,
                UNK // seems to go unused
            };

            float unkTimer; // seems to go unused
            float stunTimer;
            float stunTime;
            csl::ut::String animationStateName;
            csl::math::Vector3 hitPosition;
            void* posture; // enemy::BossPostureBattle
            csl::ut::Bitset<Flags> flags;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseDown);
        };

        class BattlePhaseDownCounter : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            enum class Flags : unsigned short {
                UNK0,
                UNK1,
                PLAYER_HELD
            };

            int64_t unk0;
            int64_t unk1;
            hh::fnd::WorldPosition playerPosition;
            csl::ut::Bitset<Flags> flags;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void HandleParry() override;
            virtual void HandlePlayerHit() override;

            DEFAULT_CREATE_FUNC(BattlePhaseDownCounter);
        };

        class BattlePhaseDying : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float dword30;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseDying);
        };

        class BattlePhaseSmashDamage : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            bool isIdle;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseSmashDamage);
        };

        class BattlePhaseCyloopDamage : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            float dword38;
            float dword3C;
            float camInterpTime;
            bool canCounter;
            char byte45;
            bool externalControlActive;
            char byte47;
            char byte48;
            char byte49;
            char byte4A;
            int qword4C;
            int qword50;
            hh::fnd::Reference<BossGiantContext> bossContext;
            hh::game::GOCTransform* gocTransform;
            csl::math::Transform bossTransform;
            hh::fnd::WorldPosition playerPosition;
            csl::math::Quaternion qwordC0;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual bool HandleDamage(app::MsgDamage& msg, float damage) override;
            virtual void HandleParry() override;
            virtual void HandlePlayerHit() override;

            DEFAULT_CREATE_FUNC(BattlePhaseCyloopDamage);
        };

        class BattlePhaseCyloopDown : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            float ringSpawnTimer;
            float dword3C;
            float dword40;
            bool hasRisenUp;
            bool externalControlActive;
            bool spawnedRings;
            char byte47;
            int dword48;
            int qword4C;
            hh::game::GOCTransform* gocTransform;
            int64_t qword58;
            csl::math::Transform bossTransform;
            hh::fnd::WorldPosition playerPosition;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual bool HandleStaggerDamage(app::MsgDamage& msg, float damage) override;

            DEFAULT_CREATE_FUNC(BattlePhaseCyloopDown);
        };

        class BattlePhaseImmActionPreparation : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            float dword30;
            float dword34;
            int dword38;
            char byte3C;
            char byte3D;
            char byte3E;
            csl::math::Vector3 downVector;
            csl::math::Vector4 csl__math__vector450;
            csl::math::Vector4 csl__math__vector460;
            hh::game::GOCTransform* gocTransform;
            void* posture; // enemy::BossPostureBattle

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseImmActionPreparation);
        };

        class BattlePhaseCyloopLanding : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            int dword38;
            float dword3C;
            float landingAnimationSpeed;
            int dword44;
            char byte48;
            char byte49;
            int externalControlActive; // this should be a bool, but then the aligning wouldn't work out
            hh::game::GOCTransform* gocTransform;
            csl::math::Transform bossTransform;
            hh::fnd::WorldPosition hh__fnd__worldposition90;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual bool HandleDamage(app::MsgDamage& msg, float damage) override;

            DEFAULT_CREATE_FUNC(BattlePhaseCyloopLanding);
        };

        class BattlePhaseHowl : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            char* stateName;
            bool playerHit;
            bool parried;
            bool unkTimerActive;
            float unkTimer;
            hh::fnd::Handle<BossHowl> howlObject;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void HandleParry() override;
            virtual void HandlePlayerHit() override;

            DEFAULT_CREATE_FUNC(BattlePhaseHowl);
        };

        class BattlePhaseHandL : public BattlePhaseHandBase {
        public:
            char* animStateNames[4];
            char* handBoneName;
            char* unkName;
            int dword180;
            int dword184;
            int dword188;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;

            virtual int BPHB_UnkFunc0() override;
            virtual void BPHB_UnkFunc1() override {}
            virtual int BPHB_UnkFunc2() override;
            virtual unsigned int AnimationStateCount() override;
            virtual const char* GetAnimationStateName(unsigned int idx) override;
            virtual void BPHB_UnkFunc5() override {}
            virtual void BPHB_UnkFunc6() override;
            virtual void BPHB_UnkFunc7() override {}
            virtual void BPHB_UnkFunc8() override;

            DEFAULT_CREATE_FUNC(BattlePhaseHandL);
        };

        class BattlePhaseHandR : public BattlePhaseHandBase {
        public:
            char* animStateNames[4];
            char* handBoneName;
            char* unkName;
            int dword180;
            int dword184;
            int dword188;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;

            virtual int BPHB_UnkFunc0() override;
            virtual void BPHB_UnkFunc1() override {}
            virtual int BPHB_UnkFunc2() override;
            virtual unsigned int AnimationStateCount() override;
            virtual const char* GetAnimationStateName(unsigned int idx) override;
            virtual void BPHB_UnkFunc5() override {}
            virtual void BPHB_UnkFunc6() override;
            virtual void BPHB_UnkFunc7() override {}
            virtual void BPHB_UnkFunc8() override;

            DEFAULT_CREATE_FUNC(BattlePhaseHandR);
        };

        class BattlePhaseHandHit : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            char byte38;
            char byte39;
            bool parried;
            float animSpeed;
            float soundTimer;
            int dword44;
            bool soundTimerActive;
            csl::ut::String animStateName;
            hh::fnd::Reference<BossGiantContext> bossContext;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void HandleParry() override;

            DEFAULT_CREATE_FUNC(BattlePhaseHandHit);
        };

        class BattlePhaseLaser : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public BossEventListener {
        public:
            // Functions are completely empty, unable to reverse anything from here
            short word38;
            int dword3C;
            int dword40;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(BattlePhaseLaser);
        };

        class BattlePhaseCounterHold : public BattlePhaseSpecialCounterBase {
        public:
            char* animStateName;
            char* soundName;
            char byteD0;
            float hitTimer;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual const char* GetAnimationStateName() override;
            virtual void BPSCB_UnkFunc1() override {}

            virtual void BEL_UnkFunc6() override;

            DEFAULT_CREATE_FUNC(BattlePhaseCounterHold);
        };

        class EventBattlePhaseStart : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public evt::EventPlayerListener {
        public:
            BossGiantContext* bossContext;

            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void EPL_UnkFunc2() override;
            virtual void CutsceneEnd(const char* cutsceneName) override;
            virtual void EPL_UnkFunc5() override;
            virtual void EPL_UnkFunc6() override;

            DEFAULT_CREATE_FUNC(EventBattlePhaseStart);
        };

        class EventBattlePhaseChange : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public evt::EventPlayerListener {
        public:
            BossGiantContext* bossContext;

            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void EPL_UnkFunc2() override;
            virtual void CutsceneEnd(const char* cutsceneName) override;
            virtual void EPL_UnkFunc5() override;

            DEFAULT_CREATE_FUNC(EventBattlePhaseChange);
        };

        class EventDead : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public evt::EventPlayerListener {
        public:
            BossGiantContext* bossContext;
            short flags;

            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void EPL_UnkFunc2() override;
            virtual void CutsceneEnd(const char* cutsceneName) override;
            virtual void EPL_UnkFunc6() override;

            DEFAULT_CREATE_FUNC(EventDead);
        };

        class EventGameOver : public app_cmn::fsm::GOCStateBase<BossGiantContext>, public evt::EventPlayerListener {
        public:
            BossGiantContext* bossContext;

            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            virtual void EPL_UnkFunc2() override;
            virtual void CutsceneEnd(const char* cutsceneName) override;
            virtual void EPL_UnkFunc6() override;

            DEFAULT_CREATE_FUNC(EventGameOver);
        };

        class DebugAnimationTest : public app_cmn::fsm::GOCStateBase<BossGiantContext> {
        public:
            char byte30;
            unsigned int layerCount;
            int currentAnimation;
            float unkTimer;
            int dword40;
            hh::game::GOComponent* recordNodeInfo;

            virtual bool ProcessMessage(BossGiantContext& context, const hh::fnd::Message& message) override;
            virtual bool StateStep(BossGiantContext& context, float deltaTime) override;
            virtual void StateEnter(BossGiantContext& context, int previousStateId) override;
            virtual void StateLeave(BossGiantContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(DebugAnimationTest);
        };
   
        static const char* GetStateNameById(int64_t& stateId);
    };

    namespace game{
        class BossActionPluginGiant01 : public BossActionPlugin<BossActionPluginGiant01> {
        public:
            GOCBossActionSelect* bossActionSelect;
            int stateId;
            csl::ut::MoveArray<int64_t> unk2;
            float unk3Timer;
            float unk3bTimer;
            float unk4Timer;
            float attackWaitTimer;
            float unk5;
            int64_t unk6;
            short unk7;

            virtual int GetNameHash() const override;
            virtual void OnAdded() override;
            virtual int64_t UnkFunc0() override;
            virtual void OnRemoved() override;
            virtual void Reset() override;
            virtual bool UpdateState(hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual bool UnkFunc9(int64_t a2) override;
            virtual bool GetPossibleActions(csl::ut::MoveArray<PossibleAction>& actions) override;
            virtual bool GetPossibleActionNames(csl::ut::MoveArray<PossibleActionName>& actionNames) override;
            virtual bool GetState(int64_t& id, csl::ut::String& name) override;
            virtual bool GetPreparedAction(int64_t* stateId, float* readyTime) override;
            virtual void ExecuteState(int& stateIdx) override;
            virtual void ExecuteState1(int& state, unsigned char unk0) override;
        };

        class BossActionPluginGiant01ImmAction : public BossActionPlugin<BossActionPluginGiant01ImmAction> {
        public:
            struct ImmediateAction {
                int stateId;
                float triggerHealth;
                char unk1;
            };

            GOCBossActionSelect* bossActionSelect;
            app_cmn::fsm::GOCHsm2* gocHsm;
            int currentActionStateId;
            csl::ut::MoveArray<int64_t> qword40;
            int dword60;
            float actionReadyTimer;
            float dword68;
            float dword6C;
            int curImmediateAction;
            csl::ut::MoveArray<ImmediateAction> immediateActions;
            short word98;

            virtual int GetNameHash() const override;
            virtual int64_t UnkFunc0() override;
            virtual void OnAdded() override;
            virtual void OnRemoved() override;
            virtual void Reset() override;
            virtual bool IsInState() override;
            virtual bool UnkFunc5() override;
            virtual bool UpdateState(hh::fnd::UpdatingPhase phase, float deltaTime) override;
            virtual bool UnkFunc7() override;
            virtual bool ProcessMessage(hh::fnd::Message& msg) override;
            virtual bool UnkFunc9(int64_t a2) override;
            virtual bool GetPossibleActions(csl::ut::MoveArray<PossibleAction>& actions) override;
            virtual bool GetPossibleActionNames(csl::ut::MoveArray<PossibleActionName>& actionNames) override;
            virtual bool GetState(int64_t& id, csl::ut::String& name) override;
            virtual bool GetPreparedAction(int64_t* stateId, float* readyTime) override;
            virtual void ExecuteState(int& stateIdx) override;
            virtual void ExecuteState1(int& state, unsigned char unk0) override;
        };
    }
}
