#pragma once

namespace hh::needle {
    class RenderingDevice;


    namespace mirageresourceimage {

        struct MirageNode {
            union Name {
                uint64_t id;
                char name[8];
            };
            enum class Flag : uint32_t {
                IS_LEAF = 29,
                IS_LAST_CHILD = 30,
                IS_ROOT = 31,
            };
            csl::ut::Bitset<Flag> flags;
            Name name;
        };

        struct MirageHeader {
            uint32_t fileSize;
            uint32_t magic;
            uint32_t offsetTableOffset;
            uint32_t offsetCount;
        };

        bool ResolvePointer(void* ptr);
        bool UnResolvePointer(void* ptr);

        void* GetMaterialTextureNameType();
        static void* materialTextureNameType;
    }

    struct SResourceBinaryImageHelper {
    public:
        void* data;
        size_t offset;
        size_t fileSize;

        void SetupPlainBinary(void* data, size_t size);
        bool GetUint(unsigned int& value);
        bool GetString(const char*& value);
        bool GetBuffer(const void*& value, size_t& size);
        bool GetBlockSize(size_t& value);
        bool GetBlockLoopPos(size_t& pos);
        bool CheckLoop(size_t pos);
    };

    bool ResolveMirageResourceBinary(void* binaryData);
    bool UnResolveMirageResourceBinary(void* binaryData);
}
