#pragma once

namespace app::evt{
    class EventEnvironmentInvisibleObjects : public EventEnvironment{
    public:
        struct Object{
            hh::fnd::Handle<hh::game::GameObject> gameObject;
            csl::ut::Bitset<hh::gfx::GOCVisual::Flag> visualFlags;
            bool visibilitySet;
        };

        csl::ut::MoveArray<Object> invisObjects;
        bool unkFlags0; //related to grind service
        bool unkFlags1;
        bool unkFlags2;
        bool unkFlags3; //related to stageindex 5
        bool isPlaying; //unsure

        virtual int64_t GetID() const override;
        virtual void EE_UnkFunc6() override;
        virtual void AddCallback() override;
        virtual void EE_UnkFunc10() override;
        virtual void EE_UnkFunc11() override;
        virtual void EE_UnkFunc13() override;
        virtual void EE_UnkFunc15() override;

        void AddObject(hh::fnd::Handle<hh::game::GameObject>& object);

        EventEnvironmentInvisibleObjects(csl::fnd::IAllocator* allocator);
    };
}
