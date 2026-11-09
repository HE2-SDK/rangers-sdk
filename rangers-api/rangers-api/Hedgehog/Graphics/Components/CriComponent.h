#pragma once

namespace hh::gfx {
    class CriComponent : public RenderingComponent {
        hh::cri::CriSystem* criSystem;

    public:
        CriComponent(csl::fnd::IAllocator* allocator);
        virtual void Initialize() override {}
        virtual void Deinitialize() override {}
        virtual void UnkFunc3() override {}
        virtual int GetNameHash() override;
        virtual const char* GetName() override;
    };
}
