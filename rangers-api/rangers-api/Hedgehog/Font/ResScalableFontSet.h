#pragma once
#include <ucsl/resources/scfnt/v1000.h>

namespace hh::font {
    using ucsl::resources::scfnt::v1000::ScfntData;

    class ResScalableFontSet : public fnd::ManagedResource {
    public:
        ScfntData* scfntData;
        char* ttfData;
        csl::ut::InplaceMoveArray<ResOpticalKerning*, 8> opticalKernings;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        void AddKerning(ResOpticalKerning* kerning);

        MANAGED_RESOURCE_CLASS_DECLARATION(ResScalableFontSet)
    };
}
