#pragma once

namespace hh::gfx {
    struct VertexAnimationTextureControllerDesc {
        hh::gfx::ResVertexAnimationTexture* resource{};
        uint32_t dword8{};
        uint8_t byteC{};
    };

    class VertexAnimationTextureController : public fnd::ReferencedObject {
    public:
        uint8_t unk1;
        hh::gfx::ResVertexAnimationTexture* resource;
        hh::gfx::GOCVisualModel* gocVisualModel;
        needle::AnimController animController;

        VertexAnimationTextureController(csl::fnd::IAllocator* allocator);
        void Setup(const VertexAnimationTextureControllerDesc& description);
    };
}
