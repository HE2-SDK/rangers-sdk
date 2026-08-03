#pragma once

namespace hh::ui::surfride {
    struct SSurfRideVertex {
        needle::float_vector4 position;
        unsigned char r,g,b,a;
        needle::float_vector2 uv0;
        needle::float_vector2 uv1;
    };
    struct SurfRideNeedleRenderParameter {
        needle::Texture* unkTexture;
        char gap4E38[424];
        needle::InstanceParameterContainerData* ipcd;
        char gap4FE8[600];

        SurfRideNeedleRenderParameter();
    };
    struct SurfRideNeedlePrimitiveQueue {
        SSurfRideVertex vertices[0x200];
        unsigned short indices[0x300];
        char byte4E08;
        int dword4E0C;
        int dword4E10;
    };
    struct SSurfridStatusCache {};

    struct CSurfRideDrawDispatcher {
        needle::intrusive_ptr<needle::RenderingDeviceContext> renderingContext;
        SurfRideNeedlePrimitiveQueue needlePrimitiveQueue;
        int dword4E14;
        SurfRide::EBlendMode blendMode;
        int dword4E1C;
        int64_t qword4E20;
        needle::ShaderObject* shaderObject;
        SurfRideNeedleRenderParameter needleRenderParameter;
        int currentShaderType;
        int currentShaderVariation;
        int dword5248;
        int dword524C;
        float cameraViewMatrix[16]; // should be csl::math::Matrix44, but then the alignment doesn't work out
        float cameraProjectionMatrix[16]; // should be csl::math::Matrix44, but then the alignment doesn't work out
        SurfRide::SrScreenResolution finalScreenResolution;
        SurfRide::SrScreenResolution customScreenResolution;
        bool useCustomScreenResolution;
    };

    class CAppDrawInterface : public SurfRide::DrawInterface {
    public:
        hh::needle::CScratchMemoryContext hh__needle__cscratchmemorycontext8;
        CSurfRideDrawDispatcher* dispatcher;
        needle::RenderTargetsSetting rtSetting;
        char gap90[0x70];

        void SetCustomScreenResolution(SurfRide::SrScreenResolution& screenRes);
        void ClearCustomScreenResolution();
        void BeginRender(UIManagerListener::UIRenderInfo& renderInfo);
        void EndRender();
        virtual void BeginRenderScene(void* layerCompositor, SurfRide::Scene* scene) override;
        virtual void EndRenderScene(void* layerCompositor, SurfRide::Scene* scene) override;
        virtual void BeginRenderLayer(void* layerCompositor, SurfRide::Layer* layer) override; // layerCompositor - hh::ui::surfride::SurfRideLayerComposition
        virtual void EndRenderLayer(void* layerCompositor, SurfRide::Layer* layer) override; // layerCompositor - hh::ui::surfride::SurfRideLayerComposition
        virtual void DrawCells2D(void* renderInfo, SurfRide::Cast* parentCast, SurfRide::SRS_CELL3D* cells, unsigned int cellCount, SurfRide::TextureList** textureLists, SurfRide::EBlendMode blendMode) override;
        virtual void DrawCells3D(void* renderInfo, SurfRide::Cast* parentCast, SurfRide::SRS_CELL3D* cells, unsigned int cellCount, SurfRide::TextureList** textureLists, SurfRide::EBlendMode blendMode) override;
        CAppDrawInterface();
    };
}
