#pragma once

#define NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT  0x304F535631315844ui64 // '0OSV11XD'
#define NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT   0x304F535031315844ui64 // '0OSP11XD'
#define NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT 0x304f534331315844ui64 // '0OSC11XD'

namespace hh::needle::ImplDX11 {
    struct SShaderOptionsDeclaration {
        CNameIDObject** optionNames;
        uint16_t numOptions;
        uint16_t unk;
        uint16_t optionsBits;
    };

    struct SShaderContextSetup;
    struct Shader2InitializeInfo {
        CScratchMemoryContext* memCtx;
        void* data;
        SShaderContextSetup* shaderContextSetup;
        DeviceObjectDX11* deviceObject;
        unsigned int unk2;
    };

    class SShaderContext2 {
        char filename[256];
        void** parameterDeclarations;
        uint64_t unk0a;
        uint32_t* cachedShaderOffsetToParameterDeclarationMap;
        ShaderPtr* cachedShaders;
        SShaderOptionsDeclaration optionsDeclaration;
        uint16_t* optionHashToCachedShaderOffsetMap;
        uint32_t unk1;
        uint16_t unk2;
        uint16_t unk3;
        uint16_t unk4;

        static void MeasureMemory(MemoryLayoutContext* memLayoutCtx, const Shader2InitializeInfo& initializeInfo);
        bool Initialize(MemoryLayoutContext* memLayoutCtx, const Shader2InitializeInfo& initializeInfo);
    };

    struct ShaderDefinition {
        void* data;
        const char* name;
        unsigned int unk1;
    };

    struct ShaderOptionDefinition {
        CNameIDObject* name;
        unsigned int index;
        unsigned int unk1;
    };

    template<typename Refl>
    struct SReflInfo {
        CNameIDObject* name;
        Refl reflection;
    };

    struct ShaderParameterReflectionSetupInfo {
        SResourceBinaryImageHelper binaryImageHelper;
    };

    template<typename T> unsigned short ParseHeaderContext(SReflInfo<T>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);

    template<> unsigned short ParseHeaderContext<TParameterSlotRegisterReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterSlotRegisterReflection<ParameterValueInt, 16, ShaderReflectionType::INT_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueInt, 16, ShaderReflectionType::INT_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterSlotRegisterReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterSlotRegisterReflection<ParameterValueTexture, 0, ShaderReflectionType::TEXTURE_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueTexture, 0, ShaderReflectionType::TEXTURE_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterSlotRegisterReflection<ParameterValueSampler, 0, ShaderReflectionType::SAMPLER_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueSampler, 0, ShaderReflectionType::SAMPLER_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<ParameterConstantBufferReflection>(SReflInfo<ParameterConstantBufferReflection>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterConstantReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterConstantReflection<ParameterValueInt, 16, ShaderReflectionType::INT_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueInt, 16, ShaderReflectionType::INT_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<TParameterConstantReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContext<ParameterUnorderedAccessViewReflection>(SReflInfo<ParameterUnorderedAccessViewReflection>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);

    template<typename T> unsigned short ParseHeaderContextCode(SReflInfo<T>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);

    template<> unsigned short ParseHeaderContextCode<TParameterSlotRegisterReflection<ParameterValueTexture, 0, ShaderReflectionType::TEXTURE_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueTexture, 0, ShaderReflectionType::TEXTURE_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContextCode<TParameterSlotRegisterReflection<ParameterValueSampler, 0, ShaderReflectionType::SAMPLER_SLOT_REGISTER>>(SReflInfo<TParameterSlotRegisterReflection<ParameterValueSampler, 0, ShaderReflectionType::SAMPLER_SLOT_REGISTER>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContextCode<ParameterConstantBufferReflection>(SReflInfo<ParameterConstantBufferReflection>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContextCode<TParameterConstantReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContextCode<TParameterConstantReflection<ParameterValueInt, 16, ShaderReflectionType::INT_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueInt, 16, ShaderReflectionType::INT_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);
    template<> unsigned short ParseHeaderContextCode<TParameterConstantReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_CONSTANT>>(SReflInfo<TParameterConstantReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_CONSTANT>>* reflInfo, ShaderParameterReflectionSetupInfo& setupInfo);

    class ShaderParameterReflection {
    public:
        CNameIDObject** boolSlotRegisterNames;
        CNameIDObject** intSlotRegisterNames;
        CNameIDObject** floatSlotRegisterNames;
        CNameIDObject** textureSlotRegisterNames;
        CNameIDObject** samplerSlotRegisterNames;
        CNameIDObject** constantBufferNames;
        CNameIDObject** boolConstantNames;
        CNameIDObject** intConstantNames;
        CNameIDObject** floatConstantNames;
        CNameIDObject** unorderedAccessViewNames;
        CNameIDObject** unk1Names;
        TParameterSlotRegisterReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_SLOT_REGISTER>* boolSlotRegisterReflections;
        TParameterSlotRegisterReflection<ParameterValueInt, 16, ShaderReflectionType::INT_SLOT_REGISTER>* intSlotRegisterReflections;
        TParameterSlotRegisterReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_SLOT_REGISTER>* floatSlotRegisterReflections;
        TParameterSlotRegisterReflection<ParameterValueTexture, 0, ShaderReflectionType::TEXTURE_SLOT_REGISTER>* textureSlotRegisterReflections;
        TParameterSlotRegisterReflection<ParameterValueSampler, 0, ShaderReflectionType::SAMPLER_SLOT_REGISTER>* samplerSlotRegisterReflections;
        ParameterConstantBufferReflection* constantBufferReflections;
        TParameterConstantReflection<ParameterValueBool, 4, ShaderReflectionType::BOOL_CONSTANT>* boolConstantReflections;
        TParameterConstantReflection<ParameterValueInt, 16, ShaderReflectionType::INT_CONSTANT>* intConstantReflections;
        TParameterConstantReflection<ParameterValueFloat, 16, ShaderReflectionType::FLOAT_CONSTANT>* floatConstantReflections;
        ParameterUnorderedAccessViewReflection* unorderedAccessViewReflections;
        void* unk1Reflections;
        unsigned short boolSlotRegisterCount;
        unsigned short intSlotRegisterCount;
        unsigned short floatSlotRegisterCount;
        unsigned short textureSlotRegisterCount;
        unsigned short samplerSlotRegisterCount;
        unsigned short constantBufferCount;
        unsigned short boolConstantCount;
        unsigned short intConstantCount;
        unsigned short floatConstantCount;
        unsigned short unorderedAccessViewCount;
        unsigned short unk1Count;

        static size_t BeginShaderParameter(void* data, ShaderParameterReflectionSetupInfo& setupInfo, ShaderParameterReflection** reflection);
        void Finalize();
    };

    struct SCbFlag {
        struct Unk1 {
            unsigned short unk1boolSlotRegisterCount;
            unsigned short unk1intSlotRegisterCount;
            unsigned short unk1textureSlotRegisterCount;
            unsigned short unk1floatConstantCount;
            unsigned short unk1constantBufferCount;
            unsigned short unk1intConstantCount;
            unsigned short unk1boolConstantCount;
            unsigned short unk1samplerSlotRegisterCount;
            unsigned short unk1floatSlotRegisterCount;
        };
        
        unsigned int constantFlags;
        unsigned int constantBufferFlags;
        Unk1 unkCounts[32];
        unsigned short textureSlotRegisterCount;
        unsigned short samplerSlotRegisterCount;
        unsigned short constantBufferCount;
        unsigned short floatConstantCount;
        unsigned short floatSlotRegisterCount;
        unsigned short intConstantCount;
        unsigned short boolConstantCount;
        unsigned short unorderedAccessViewCount;
        uint32_t padLast;
    };

    struct SCBParamLayoutParam {
        struct Unk1 {
            CNameIDObject* name;
            uint16_t word8;
            uint16_t wordA;
            uint8_t byteC;
            uint8_t byteD;
            uint8_t byteE;
        };

        struct Unk2 {
            Unk1* textureParams;
            Unk1* samplerParams;
            Unk1* constantBufferParams;
            Unk1* floatParams;
            Unk1* unk1Params;
            Unk1* intParams;
            Unk1* boolParams;
            Unk1* unorderedAccessViewParams;
            void* unk1;
        };

        Unk2 mainParams;
        Unk2 params[32];
        Unk2 mainParams2;
        Unk2 params2[32];

        NeedleUniqueBlob* Fixup(CScratchMemoryContext* memCtx, const SCbFlag& flag);
    };

    struct SShaderContextSetup {
        enum class ShaderType : unsigned int {
            VERTEX,
            PIXEL,
            COMPUTE,
        };

        ShaderType type;
        char gap4[12];
        unsigned short word10;
        char gap12[6];
        uint64_t qword18;
        unsigned short word20;
        char gap22[2];
        unsigned short word24;
        char gap26[2];
        unsigned int *punsigned_int28;
        NeedleUniqueBlob** layoutParams;
        void* qword38;
        ShaderPtr* shaders;
        short* qword48;
        short* qword50;
        short* qword58;
        short* qword60;
        short* qword68;
        short* qword70;
        void** shaderDatas;
        size_t* shaderSizes;
        unsigned short word88;
        unsigned short word8A;
        unsigned short word8C;
        void* unkPtr;
        
        void Setup(const Shader2InitializeInfo& shaderInitializeInfo);
        void Setup(SShaderContext2& shaderContext, void* data);
    };

    typedef NeedleResourceContainer<VertexShader, SShaderContext2, NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> VertexShader;
    typedef NeedleResourceContainer<PixelShader, SShaderContext2, NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> PixelShader;
    typedef NeedleResourceContainer<ComputeShader, SShaderContext2, NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> ComputeShader;
}
