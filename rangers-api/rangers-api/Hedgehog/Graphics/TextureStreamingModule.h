#pragma once

namespace hh::gfx{
    class ResTextureStreamingPackage;

    class TextureStreamingModule : public fw::AppModule, public fnd::ResourceManager::ResourceListener{
    public:
        void* unk0;
        SLIST_HEADER unk1;
        SLIST_HEADER unk2;
        int unk3;
        csl::fnd::Mutex ntspMutex;
        csl::ut::StringMap<ResTextureStreamingPackage*> textureStreamingPackages;
        csl::ut::String mainFolderName;
        csl::ut::VariableString fileSystemName;
        fnd::FileSystemImpl* fileSystem;
        int32_t dwordD0; //set to the return value of RenderingDevice::Shutdown
        int32_t dwordD4; //used in RenderingDevice::GetNativeDevice
        int32_t dwordD8;
        int8_t byteDC;

        virtual void AddCallback(hh::fw::Application* app) override;
        virtual void RemoveCallback() override;

        ResTextureStreamingPackage* GetPackage(const char* name);
        ResTextureStreamingPackage* LoadPackage(const char* name);
        void AddResource(const char* name, ResTextureStreamingPackage* resource);

        TextureStreamingModule(csl::fnd::IAllocator* allocator);

        APPMODULE_CLASS_DECLARATION(TextureStreamingModule);
    };
}
