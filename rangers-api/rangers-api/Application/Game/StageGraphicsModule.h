#pragma once

namespace app::game {
    class StageGraphicsModule : public GameModeResourceModule {
    public:
        hh::fnd::Reference<gfx::SceneParameters> sceneParams;
        int64_t unk0;
        int64_t unk1;
        int64_t unk2;
        int64_t unk3;
        char unk4;

        virtual unsigned int GetNameHash() override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Load() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;

        StageGraphicsModule(csl::fnd::IAllocator* allocator);
    };
}
