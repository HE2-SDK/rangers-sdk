#pragma once

namespace app::game{
    class GameModeBoot : public GameMode {
    public:
        hh::fnd::ResourceLoader* resLoader;
        int unk0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Initialize() override;
        virtual void Deinitialize(bool a2) override;

        GameModeBoot(csl::fnd::IAllocator* allocator);
    };
}