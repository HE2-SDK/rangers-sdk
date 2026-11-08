#pragma once

namespace hh::needle {
    class LightFieldParamBuildJob : public ParamBuildJob {
    public:
        SCLightField* scLightField;

        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override {}
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override;
    };
}
