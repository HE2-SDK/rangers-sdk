#pragma once

namespace hh::ut {
    namespace internal {
        class StateImpl : public fnd::ReferencedObject {
        public:
            int id;
            const char* name;
            void* context;

            inline StateImpl(csl::fnd::IAllocator* allocator) : ReferencedObject{ allocator, true } {}

            virtual bool DoInit() = 0;
            virtual void DoEnter(int previousStateId) = 0;
            virtual void DoLeave(int nextStateId) = 0;
            virtual bool DoStep(float deltaTime) = 0;
            virtual bool DoUpdate(fnd::UpdatingPhase phase, float deltaTime) = 0;
            virtual bool DoUpdateAsync(fnd::UpdatingPhase phase, float deltaTime) = 0;
            virtual bool DoProcessMessage(const hh::fnd::Message& message) = 0;
        };
    }

    template<typename T>
    class StateBase : public internal::StateImpl {
    public:
        inline StateBase(csl::fnd::IAllocator* allocator) : StateImpl{ allocator } {}

        virtual bool DoInit() override { return Init(*(T*)context); }
        virtual void DoEnter(int previousStateId) override { Enter(*(T*)context, previousStateId); }
        virtual void DoLeave(int nextStateId) override { Leave(*(T*)context, nextStateId); }
        virtual bool DoStep(float deltaTime) override { return Step(*(T*)context, deltaTime); }
        virtual bool DoUpdate(fnd::UpdatingPhase phase, float deltaTime) override { return Update(*(T*)context, phase, deltaTime); }
        virtual bool DoUpdateAsync(fnd::UpdatingPhase phase, float deltaTime) override { return UpdateAsync(*(T*)context, phase, deltaTime); }
        virtual bool DoProcessMessage(const hh::fnd::Message& message) override { return ProcessMessage(*(T*)context, message); }

        virtual bool Init(T& context) { return false; }
        virtual void Enter(T& context, int previousState) {}
        virtual void Leave(T& context, int nextState) {}
        virtual bool ProcessMessage(T& context, const hh::fnd::Message& message) { return false; }
        virtual bool Step(T& context, float deltaTime) { return false; }
        virtual bool Update(T& context, fnd::UpdatingPhase phase, float deltaTime) { return false; }
        virtual bool UpdateAsync(T& context, fnd::UpdatingPhase phase, float deltaTime) { return false; }
    };
}
