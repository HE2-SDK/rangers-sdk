#pragma once

namespace app::gfx {
    class FxParamGraphicsOptionExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        short unk0;
        int unk1;
        int unk2;
        int unk3;
        char unk4;
        char unk5;

        FxParamGraphicsOptionExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;

        virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;
    };
}
