#pragma once

#define NEEDLE_RESOURCE_TEXTURE 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    struct TextureCreationInfo {
        enum class Usage {
            DEFAULT,
            IMMUTABLE,
            DYNAMIC,
            STAGING,
            IMMUTABLE2,
            DYNAMIC2,
        };

        enum class BindFlag {
            SHADER_RESOURCE,
            RENDER_TARGET,
            DEPTH_STENCIL,
            VERTEX_BUFFER,
            INDEX_BUFFER,
            CONSTANT_BUFFER,
            STREAM_OUTPUT,
            UNORDERED_ACCESS,
        };

        enum class MiscFlag {
            GENERATE_MIPS,
            SHARED,
            TEXTURECUBE,
            UNK3,
            UNK4,
            BUFFER_STRUCTURED,
            UNK6,
            UNK7,
            UNK8,
            UNK9,
            DRAWINDIRECT_ARGS,
            BUFFER_ALLOW_RAW_VIEWS,
            UNK12,
            UNK13,
            CPU_ACCESS_READ,
            CPU_ACCESS_WRITE,
        };

        struct SubresourceData {
            void* sysMem;
            uint32_t memPitch;
        };

        SurfaceType type{}; // goes into surfaceformat unk1
        SurfaceFormat format{};
        unsigned int width{};
        unsigned int height{};
        unsigned int depth{};
        unsigned int mipLevels{};
        unsigned int arraySize{};
        csl::ut::Bitset<BindFlag> bindFlags{};
        csl::ut::Bitset<MiscFlag> miscFlags{};
        uint32_t unk2b{}; // surfaceformat unk5 is true if this is not zero
        Usage usage{};
        int sampleDescIndex{};
        SubresourceData* subresourceDatas{}; // count = arraySize * mipLevels
        void* fileData{}; // Either a DDS or TGA file. Leave as nullptr for custom texture buffer.
        size_t fileSize{};
        uint64_t unk3a{};
        uint64_t unk3b{};
        uint64_t unk3{};
        void* unk4{}; // streaming related i think
        uint64_t unk5{};
    };

    struct TextureViewCreationInfo {
        SurfaceFormat textureFormat{}; //if 0 -> use DXGI_FORMAT format
        uint8_t unk1{};
        uint8_t unk2{};
        uint8_t unk2a{};
        SurfaceDimension dimension{};
        unsigned int arraySize{};
        unsigned int mipLevels{};
        unsigned int firstArraySlice{};
        uint32_t unk6{};
        bool unk7{};
        uint32_t unk7b{};
        uint64_t unk8{};
        DXGI_FORMAT format{};
    };

    class Texture : public SurfaceBase {
    public:
        uint8_t unk101;
        void* view; // Copied ID3D11TextureView @ 0x155C55D2F
        void* viewSynchronizerVfTable; // streaming, see 0x155E91940

        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXTURE;
    };
}
