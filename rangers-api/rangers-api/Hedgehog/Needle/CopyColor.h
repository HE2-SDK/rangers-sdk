#pragma once

namespace hh::needle{
    class CopyColor : public NeedleRefcountObject{
    public:
        PostEffectShader postEffectShader;

        void Initialize(SupportFX* supportFx);
        void Initialize(RenderingDevice* device);
        CopyColor();
    };
}
