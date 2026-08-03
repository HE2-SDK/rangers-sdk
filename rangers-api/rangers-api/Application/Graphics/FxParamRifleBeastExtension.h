#pragma once

namespace app::gfx {
    class FxParamRifleBeastExtension : public FxParamExtension {
    public:
        csl::ut::InplaceMoveArray<uint64_t, 4> jobs; // values are owner ids

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override {};
        virtual void Destroy() override;

        void AddJob(uint64_t ownerId, float interpolationTime);
        void RemoveJob(uint64_t ownerId, float interpolationTime);

        FxParamRifleBeastExtension(csl::fnd::IAllocator* allocator);
    };
}
