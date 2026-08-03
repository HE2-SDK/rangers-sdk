#pragma once

namespace hh::needle {
    class PostEffectShader : public NeedleRefcountObject {
    public:
        ShaderObject* shaderObject;
        ParameterValueObject* sourceParameters; // s_Source
        ParameterValueObject* parameters2;
        ParameterValueObject* parameters3;
        PrimitiveTopology topology;

        PostEffectShader();
        virtual ~PostEffectShader();
        
        void Setup(RenderingDevice* renderingDevice, VertexShader* vertexShader, PixelShader* pixelShader, InstanceParameterContainerData* parameters1, InstanceParameterContainerData* parameters2, InstanceParameterContainerData* parameters3);
    };
}
