#pragma once
#include <ucsl/resources/vertex-animation-texture/v1-rangers.h>

namespace hh::gfx {
    enum class VertexAnimationTextureType {};

    using ucsl::resources::vertex_animation_texture::v1_rangers::VertexAnimationTextureRangeData;
    using ucsl::resources::vertex_animation_texture::v1_rangers::VertexAnimationTextureData;

    class ResVertexAnimationTexture : fnd::ManagedResource {
    public:
        VertexAnimationTextureData* vatData;
        hh::fnd::Reference<gfnd::ResTexture> texture;
        hh::fnd::Reference<gfnd::ResTexture> normalsTexture;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Resolve(fnd::ResourceResolver& resolver) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResVertexAnimationTexture);

        VertexAnimationTextureRangeData GetPositionRange() const;
        VertexAnimationTextureType GetType() const;
        gfnd::ResTexture* GetTexture(bool norm) const;
        float GetFPS() const;
        float GetFrameCount() const;
        float GetDuration() const;
    };
}
