#pragma once

namespace hh::needle {
    class ShaderTextureUtil {
    public:
        ShaderUtil shaderUtil;
        TextureUtil textureUtil;
        intrusive_ptr<UnorderedAccessView> qword30;

        ShaderTextureUtil();
    };

    class SkyProbe : public NeedleRefcountObject {
    public:
        int dword10;
        intrusive_ptr<Texture> iblGGXTexture;
        ShaderTextureUtil shaderTextureUtil;
        intrusive_ptr<IBLGGXSamplingTexture> qword588;
        intrusive_ptr<ShaderObject> qword60;
        intrusive_ptr<ParameterValueObject> qword68;
        intrusive_ptr<UnorderedAccessView> qword70;
        intrusive_ptr<Texture> qword78;
        intrusive_ptr<UnorderedAccessView> qword80;
        intrusive_ptr<Texture> qword88;
        intrusive_ptr<Texture> qword90[3];
        int64_t qwordA8;
        int64_t qwordB0;
        char byteB8[0x80];
        int dword138;

        SkyProbe();

        void Initialize(SupportFX* supportFx, intrusive_ptr<Texture>& iblGGXTexture);
    };
}
