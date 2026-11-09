#pragma once

namespace hh::needle {
    class RenderingDeviceContext;

    class PostEffectShader : public NeedleRefcountObject {
    public:
        ShaderObject* shaderObject;
        ParameterValueObject* sourceParameters; // s_Source
        ParameterValueObject* parameters2;
        ParameterValueObject* parameters3;
        PrimitiveTopology topology;

        PostEffectShader();
        
        void Setup(RenderingDevice* renderingDevice, VertexShader* vertexShader, PixelShader* pixelShader, InstanceParameterContainerData* parameters1, InstanceParameterContainerData* parameters2, InstanceParameterContainerData* parameters3);
        void Render(RenderingDeviceContext* renderingDeviceContext, InstanceParameterContainerData* param3, InstanceParameterContainerData* param2, bool depthEnabled, InstanceParameterContainerData* sourceParams);
    };
}
