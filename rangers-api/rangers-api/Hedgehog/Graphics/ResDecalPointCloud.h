#pragma once

namespace hh::gfx{
    class ResDecalPointCloud : public hh::fnd::ManagedResource {
    public:
        void* data;
        void* unk0;
        csl::ut::MoveArray<int64_t> unk1;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResDecalPointCloud)
    };
}
