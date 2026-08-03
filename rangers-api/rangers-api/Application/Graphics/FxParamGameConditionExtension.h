#pragma once

namespace app::gfx{
    class FxParamGameConditionExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        short unk0;

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override {}
        virtual void Destroy() override {}

        FxParamGameConditionExtension(csl::fnd::IAllocator* allocator);
    };
}
