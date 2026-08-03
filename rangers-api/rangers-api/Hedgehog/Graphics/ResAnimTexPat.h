#pragma once

namespace hh::gfx {
    class ResAnimTexPat : public fnd::ManagedResource {
    public:
        csl::ut::MoveArray<hh::needle::Texture*> textures;
        needle::intrusive_ptr<needle::PtAnimationResource> resource;
        needle::intrusive_ptr<needle::TextureStreamingTexturePatternGuard> streamingGuard;
        csl::ut::MoveArray<hh::gfnd::ResTexture*> resTextures;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimTexPat)
    };
}
