#pragma once
#include <ucsl/resources/terrain-material/v1.h>

namespace hh::gfx {
    UCSL_NEWTYPE_SIMPLE(TerrainMaterialData, ucsl::resources::terrain_material::v1::TerrainMaterialData);

    class ResTerrainMaterial : public fnd::ManagedResource {
    public:
        TerrainMaterialData* terrainMaterialData;
        void* unk101;
        csl::ut::MoveArray<void*> unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTerrainMaterial)
    };
}
