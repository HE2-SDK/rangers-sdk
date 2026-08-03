#pragma once

namespace app::dv {
    class AppDvSceneObjectBase : public hh::dv::DvSceneObjectBase {
    public:
        hh::fnd::ManagedResource* uvAnimRes0;
        hh::fnd::ManagedResource* unkRes0;
        hh::fnd::ManagedResource* uvAnimRes1;
        hh::fnd::ManagedResource* unkRes1;
        csl::ut::MoveArray<void*> unkArray0;
        void* unk3;
        short unk4;

        virtual void SetModelResource(hh::gfx::ResModel* resource) override;
        virtual void SetTexSrtTime(hh::gfx::ResAnimTexSrt* uvAnim, float time, bool loop) override;
        virtual void* VisualModelRelated7(void* a2) override;

        AppDvSceneObjectBase(csl::fnd::IAllocator* allocator, hh::dv::DvStandardCharacter* character);
    };
}
