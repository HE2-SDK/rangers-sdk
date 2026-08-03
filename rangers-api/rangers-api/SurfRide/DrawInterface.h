#pragma once

namespace SurfRide {
    class DrawInterface {
    public:
        virtual ~DrawInterface();
        virtual void BeginRenderScene(void* layerCompositor, Scene* scene) {}
        virtual void EndRenderScene(void* layerCompositor, Scene* scene) {}
        virtual void BeginRenderLayer(void* layerCompositor, Layer* layer) {} // layerCompositor - hh::ui::surfride::SurfRideLayerComposition
        virtual void EndRenderLayer(void* layerCompositor, Layer* layer) {} // layerCompositor - hh::ui::surfride::SurfRideLayerComposition
        virtual void SRDI_UnkFunc4() {}
        virtual void SRDI_UnkFunc5() {}
        virtual void SRDI_UnkFunc6() {}
        virtual void DrawCells2D(void* renderInfo, Cast* parentCast, SRS_CELL3D* cells, unsigned int cellCount, TextureList** textureLists, EBlendMode blendMode) = 0;
        virtual void DrawCells3D(void* renderInfo, Cast* parentCast, SRS_CELL3D* cells, unsigned int cellCount, TextureList** textureLists, EBlendMode blendMode) = 0;
        DrawInterface();
    };
}
