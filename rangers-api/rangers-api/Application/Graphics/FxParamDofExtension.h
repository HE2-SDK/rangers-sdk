#pragma once

namespace app::gfx {
    class FxParamDofExtension : public FxParamExtension {
    public:
        float timer;

        FxParamDofExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override {};
        virtual void Destroy() override {};
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) override;
    };
}
