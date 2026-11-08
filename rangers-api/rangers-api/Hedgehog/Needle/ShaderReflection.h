#pragma once

namespace hh::needle {
    enum class ShaderReflectionType {
        BOOL_SLOT_REGISTER,
        INT_SLOT_REGISTER,
        FLOAT_SLOT_REGISTER,
        TEXTURE_SLOT_REGISTER,
        SAMPLER_SLOT_REGISTER,
        CONSTANT_BUFFER,
        BOOL_CONSTANT,
        INT_CONSTANT,
        FLOAT_CONSTANT,
        UNORDERED_ACCESS_VIEW,
    };

    template<typename ValueType, size_t size, ShaderReflectionType type>
    class TParameterSlotRegisterReflection {
    public:
        unsigned char flagId;
        unsigned char unk2;
        unsigned short unk3;
    };

    struct ParameterConstantBufferReflection {
        unsigned char flagId;
        unsigned char unk2;
        unsigned short unk3;
    };

    struct ParameterUnorderedAccessViewReflection {
        unsigned char flagId;
        unsigned char unk2;
        unsigned char unk3;
    };

    template<typename ValueType, size_t size, ShaderReflectionType type>
    class TParameterConstantReflection {
    public:
        unsigned char flagId;
        unsigned char unk2;
        unsigned short unk3;
        unsigned short unk4;
    };
}
