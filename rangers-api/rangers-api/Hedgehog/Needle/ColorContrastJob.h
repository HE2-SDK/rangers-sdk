#pragma once

namespace hh::needle{
    class ColorContrastJob : public PostEffectRenderJob{
    public:
        char byteF0;
        float dwordF4;
        float dwordF8;
        float dwordFC;
        float dword100;
        float dword104;
        char byte108;
        char gap109[11];
        float m128114[4];
        float m128124[4];
        int32_t qword134;
        int32_t qword138;
        int32_t dword13C;
        PostEffectShader* shader;

        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual void Setup(const RenderJobContext& context) override;

        ColorContrastJob();
    };
}
