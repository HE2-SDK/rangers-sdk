#pragma once

namespace app::gfx {
    class FxParamChromaticAberrationExtension : public FxParamExtension {
    public:
        int64_t unk0;
        int64_t unk1;
        int64_t unk2;
        int64_t unk3;
        int64_t unk4;
        int64_t unk5;
        int64_t unk6;
        int64_t unk7;
        int64_t unk8;
        int16_t unk9;

        FxParamChromaticAberrationExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override {};
        virtual void Destroy() override;
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) override;
    };
}
