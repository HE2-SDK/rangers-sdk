#pragma once

namespace hh::needle {
    class IResourceBindCallback {
    public:
        virtual void* QueryResource(size_t id, CNameIDObject* name) = 0;
        virtual void RegisterResource(size_t id, fnd::ManagedResource* resource) = 0;
        virtual ~IResourceBindCallback() = 0;
    };
}
