#pragma once

namespace hh::gfx {
    class ResBindCallback : public needle::IResourceBindCallback {
    public:
        fnd::ResourceResolver* resolver;

        inline ResBindCallback(fnd::ResourceResolver* resolver) : resolver{ resolver } {} 

        virtual void* QueryResource(size_t id, needle::CNameIDObject* name) = 0;
        virtual void RegisterResource(size_t id, fnd::ManagedResource* resource) {}
    };

    template<typename T>
    class ResDefaultBindCallback : public ResBindCallback {
    public:
        fnd::Reference<T> resource;
        int64_t qword18;

        inline ResDefaultBindCallback(fnd::ResourceResolver* resolver) : ResBindCallback{ resolver } {}

        virtual void* QueryResource(size_t id, needle::CNameIDObject* name) override;
        virtual void RegisterResource(size_t id, fnd::ManagedResource* resource) override;
    };

    class ResMaterialBindCallback : public ResDefaultBindCallback<ResMaterial> {};
}
