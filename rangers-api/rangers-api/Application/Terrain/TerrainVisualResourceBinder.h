#pragma once

namespace app::trr {
    class TerrainVisualResourceBinder : public hh::fnd::ReferencedObject {
    public:
        class ModelData : public hh::fnd::ReferencedObject {
        public:
            enum class Flags : unsigned char {
                IS_MODEL,
                IS_TERRAIN_MODEL,
                MOTION = 4,
                GRASS
            };

            const char* name;
            hh::gfx::ResTerrainModel* model;
            csl::ut::Bitset<Flags> flags;
        };

        csl::ut::InplaceMoveArray<hh::fnd::ManagedResource*, 4> resources;
        csl::ut::StringMap<hh::fnd::ManagedResource*> resourcesByName;
        csl::ut::MoveArray<hh::fnd::Reference<ModelData>> models;
        csl::ut::MoveArray<csl::ut::String> loadedPacs;

        void InitializeModelsEx(const char* pacName);
        void InitializeModels(const char* pacName);

        DEFAULT_CREATE_FUNC(TerrainVisualResourceBinder);
    };
}
