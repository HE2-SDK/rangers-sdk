#pragma once

namespace app{
    class ResGismoConfigPlan : public hh::fnd::ManagedResource {
    public:
        heur::rfl::GismoConfigPlanData* gismoConfigPlanData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResGismoConfigPlan)

        virtual void Load(void* data, size_t size) override;
    };
}
