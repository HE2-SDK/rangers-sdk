#pragma once

namespace hh::needle {
    class IBLGGXSamplingTexture : public NeedleRefcountObject {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            ShaderUtil shaderUtil;
            csl::math::Matrix44 matrix;
            intrusive_ptr<hh::needle::Texture> texture;
            csl::ut::MoveArray<csl::ut::MoveArray<intrusive_ptr<hh::needle::UnorderedAccessView>>> uavs;
        };

        intrusive_ptr<Impl> implementation;

        IBLGGXSamplingTexture();
        void Initialize();
        void CreateTexture(SupportFXAll* supportFX, unsigned int size, SurfaceFormat format, int cubeCount);
        intrusive_ptr<Texture> GetTexture() const;
    };
}