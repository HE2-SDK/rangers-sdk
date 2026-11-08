#pragma once

namespace app::evt {
    class EventEnvironmentTime : public EventEnvironment {
    public:
        int flags;

        virtual int64_t GetID() const override;
        virtual void EE_UnkFunc4() override;
        virtual void EE_UnkFunc6() override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void EE_UnkFunc10() override;
        virtual void EE_UnkFunc11() override;

        EventEnvironmentTime(csl::fnd::IAllocator* allocator);
    };
}
