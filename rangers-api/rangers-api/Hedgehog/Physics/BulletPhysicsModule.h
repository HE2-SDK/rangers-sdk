#pragma once

namespace hh::physics {
    class BulletPhysicsModule : public fw::AppModule {
    public:
        uint64_t unk1;
        uint64_t unk2;
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;

        static BulletPhysicsModule* instance;
        static BulletPhysicsModule* Create(csl::fnd::IAllocator*);
        virtual void AddCallback(hh::fw::Application* app) override;
        virtual void RemoveCallback() override;
    };
}
