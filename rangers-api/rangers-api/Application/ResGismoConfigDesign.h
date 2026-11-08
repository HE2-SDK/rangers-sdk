#pragma once

namespace app{
    class ResGismoConfigDesign : public hh::fnd::ManagedResource {
    public:
        heur::rfl::GismoConfigDesignData* gismoConfigDesignData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResGismoConfigDesign)

        virtual void Load(void* data, size_t size) override;
    };
}
