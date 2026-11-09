#pragma once

namespace hh::needle {
    class PickColorShaderObject : public NeedleRefcountObject {
    public:
        intrusive_ptr<ShaderObject> computeShader;
        intrusive_ptr<Texture> qword18;
        intrusive_ptr<UnorderedAccessView> qword20;
        intrusive_ptr<Texture> qword28;
        intrusive_ptr<ParameterValueObject> qword30;

        PickColorShaderObject();

        void Initialize(RenderingDevice* renderingDevice, SupportFX* supportFx);
    };
}
