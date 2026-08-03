#pragma once

namespace app::gfx {
    class FxParamBulletTimeExtension : public FxParamExtension {
    public:
        int64_t unk0;
        int unk1;
        short unk2;

        FxParamBulletTimeExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override {};
        virtual void Destroy() override {};
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) override;
    };
}
