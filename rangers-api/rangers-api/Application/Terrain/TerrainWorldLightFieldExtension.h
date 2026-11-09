#pragma once

namespace app::trr {
    class TerrainWorldLightFieldExtension : public TerrainWorldExtension {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize() override;
    };
}
