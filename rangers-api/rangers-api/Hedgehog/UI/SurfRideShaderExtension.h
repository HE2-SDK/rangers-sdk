#pragma once

namespace hh::ui::surfride {
    class SurfRideShaderExtension : public SurfRide::CastExtension {
    public:
        needle::intrusive_ptr<needle::ShaderObject> shaderObjects[2];
        needle::float_vector4 shaderParams;

        SurfRideShaderExtension();

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void AddCallback(SurfRide::Cast* cast) override {}
        virtual void RemoveCallback(SurfRide::Cast* cast) override {}

        void Setup(const char* vertexShaderName, const char* pixelShaderName, needle::float_vector4* shaderParams);
    };
}
