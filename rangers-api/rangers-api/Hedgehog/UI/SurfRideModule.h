#pragma once

namespace hh::ui {
    namespace surfride {
        class SurfRideShaderManager : public fnd::ReferencedObject {
        public:
            needle::intrusive_ptr<needle::VertexShader> vertexShaders[2];
            needle::intrusive_ptr<needle::PixelShader> pixelShaders[15];
            needle::intrusive_ptr<needle::ShaderObject> shaderObjects[15];
            needle::VertexLayout* vertexLayout;

            SurfRideShaderManager(csl::fnd::IAllocator* allocator);
            void Initialize(needle::RenderingDevice* renderingDevice);
            static void Initialize(csl::fnd::IAllocator* allocator, needle::RenderingDevice* renderingDevice);
            static fnd::Reference<SurfRideShaderManager> instance;
            static SurfRideShaderManager* GetInstance();
        };
    }

    class SurfRideModule : public fw::AppModule {
    public:
        csl::fnd::IAllocator* surfrideAllocator;

        virtual void AddCallback(fw::Application* app) override;
        virtual void RemoveCallback() override;

        APPMODULE_CLASS_DECLARATION(SurfRideModule);
    };
}
