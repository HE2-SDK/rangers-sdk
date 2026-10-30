#pragma once

namespace app::evt {
    class EventEnvironmentSkip : public EventEnvironment {
    public:
        hh::fnd::Handle<hh::game::GameObject> eventSkipGuide;

        virtual int64_t GetID() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void EE_UnkFunc13() override;
        virtual void EE_UnkFunc16() override;

        EventEnvironmentSkip(csl::fnd::IAllocator* allocator);
    };
}
