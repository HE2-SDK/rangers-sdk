#pragma once

namespace hh::gfx {
    class ResAnimMaterial : public fnd::ManagedResource {
    public:
        needle::intrusive_ptr<needle::MaterialAnimationResource> resource;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimMaterial)
    };
}
