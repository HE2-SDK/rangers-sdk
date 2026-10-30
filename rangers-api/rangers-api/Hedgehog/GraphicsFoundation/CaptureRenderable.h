#pragma once

namespace hh::gfnd{
    class CaptureRenderable : public Renderable, public gfx::RenderManager::Listener {
    public:
        needle::intrusive_ptr<needle::Texture> renderTexture;
        needle::intrusive_ptr<needle::RenderTarget> renderTarget;
        bool render;
        char byte69;
        char byte6A;
        int64_t qword70;
        int64_t qword78;
        bool shouldUseScreenResolution;
        float renderScale;

        CaptureRenderable(csl::fnd::IAllocator* allocator, bool shouldUseScreenResolution, float renderScale);

        virtual void Render(const RenderableParameter* renderableParameter) override;
        virtual void GFXRML_UnkFunc0() override;
    };
}
