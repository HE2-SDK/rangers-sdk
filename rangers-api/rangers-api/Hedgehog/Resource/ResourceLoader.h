#pragma once

namespace hh::fnd {
    class ResourceLoader : public ReferencedObject, public FileInfoListener, public FileBindListener {
    public:
        struct Locale {
            uint32_t localeId{ 1 };
            const char* localeName{ "" };
        };

        struct Unk3 {
            uint64_t unk1;
            bool unk2;
            csl::ut::VariableString unk3;

            Unk3(csl::fnd::IAllocator* allocator);
        };

        UnpackedResourceContainer unpackedResourceContainer;
        csl::ut::MoveArray<ManagedResource*> loadedResources;
        csl::ut::MoveArray<ManagedResource*> toBeLoadedResources; // these load when the unload func is called..?
        csl::ut::MoveArray<void*> unk4;
        Unk3 unk5;
        csl::fnd::IAllocator* resourceAllocator;
        csl::ut::VariableString unk6;
        csl::ut::MoveArray<void*> unk7;
        char unk8;
        char unk8b;

        ResourceLoader(csl::fnd::IAllocator* allocator);
        inline static ResourceLoader* Create(csl::fnd::IAllocator* allocator) {
            return new (allocator) ResourceLoader(allocator);
        }

        void LoadPackfile(const char* uri, uint32_t unk);
        void LoadPackfile(const char* uri, Locale& locale);
        inline void LoadPackfile(const char* uri) { LoadPackfile(uri, 0); }
        void LoadResource(const Uri& uri, const ResourceTypeInfo* resourceTypeInfo, int unk, uint32_t unk2, Locale& locale);
    };
}
