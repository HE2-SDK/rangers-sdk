#pragma once

namespace app::player {
    class PlayerStateActionBase : public PlayerStateBase {

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
