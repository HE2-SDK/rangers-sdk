#pragma once

namespace app::evt {
    class EventEnvironmentFps : public EventEnvironment {
    public:
        float prevMaxFps;
        bool prevUpdateDeltaTime;

        virtual int64_t GetID() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;

        EventEnvironmentFps(csl::fnd::IAllocator* allocator);
    };
}
