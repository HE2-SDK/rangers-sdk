#pragma once

namespace app::gfx {
    class FxParamBlurExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        FxParamBlurExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;

        virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;
    };
}
