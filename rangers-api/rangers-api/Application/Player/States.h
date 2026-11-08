#pragma once

namespace app::player {
    class PlayerStateActionBase : public PlayerStateBase {

    };
	
	class StateSleep : public PlayerStateBase {
	public:
		virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
		
		DEFAULT_CREATE_FUNC(StateSleep);
	};

    class StateStandRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
		
		DEFAULT_CREATE_FUNC(StateStandRoot);
    };

    class StateStandBase : public PlayerStateActionBase {
    public:
    };

    class StateStand : public StateStandBase {
    public:
        class Parameter : public StateParameter {
        public:
            char byte10;

            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) const override;
            virtual unsigned int GetNameHash() const override;
        };

        Timer idleAnimationTimer;
        char byteB8;
        int dwordBC;
        char byteC0;

        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
		
        DEFAULT_CREATE_FUNC(StateStand);
    };

    class StateWakeUp : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual bool InitPlayerState(PlayerHsmContext& context) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
		
        DEFAULT_CREATE_FUNC(StateWakeUp);
    };

    class StateRun : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
        public:
            csl::math::Vector3 velocity;
            bool setVelocity;

            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) const override;
            virtual unsigned int GetNameHash() const override;
        };

        char byteB0;

        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
		
        DEFAULT_CREATE_FUNC(StateRun);
    };

    class StateJumpBase : public PlayerStateActionBase {

    };

    class StateJump : public StateJumpBase {
        virtual bool ProcessMessage(void* hsm, const hh::fnd::Message& message);
        virtual void UnkFunc12(void* hsm, uint32_t unkParam2);
        virtual void UnkFunc13(void* hsm, uint32_t unkParam2);
        virtual bool Update(void* hsm, float unkParam2);
    };

    class StateFall : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
        public:
            uint32_t unk101;
            float outOfControlTime;

            inline Parameter(unsigned int unk101Param, float startOutOfControlTime) : StateParameter{ 1 }, unk101 { unk101Param }, outOfControlTime{ startOutOfControlTime } {}
            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) const override;
            virtual unsigned int GetNameHash() const override;
        };
    };

    class StateBoarding : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
        public:
            float outOfControlTime;

            inline Parameter(float startOutOfControlTime) : StateParameter{ 1 }, outOfControlTime{ startOutOfControlTime } {}
            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) const override;
            virtual unsigned int GetNameHash() const override;
        };
    };
}
