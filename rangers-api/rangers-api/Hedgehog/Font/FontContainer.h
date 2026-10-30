#pragma once

namespace hh::font {
    class FontContainer;

    class FontContainerListener {
    public:
        virtual ~FontContainerListener() = default;
        virtual void OnRegisteredFont(FontContainer* container, IFont* font, const char* name) {}
        virtual void FCL_UnkFunc2() {}
        virtual void FCL_UnkFunc3() {}
    };

    class FontContainerItem : public hh::fnd::ReferencedObject {
    public:
        csl::ut::VariableString name;
        fnd::Reference<IFont> font;
    };

    class FontContainerResourceListener : public fnd::ReferencedObject, public fnd::ResourceManager::ResourceListener {
    public:
        FontContainer* container;
        csl::ut::MoveArray<ResScalableFontSet*> scalableFonts;
        csl::ut::MoveArray<ResOpticalKerning*> opticalKernings;

        virtual void ResourceLoadedCallback(fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;

        void Callback(fnd::ManagedResource* resource, bool removed);
    };

    class FontContainer : public hh::fnd::ReferencedObject {
    public:
        hh::fnd::Reference<BitmapFont> font;
        int64_t qword20;
        hh::fnd::Reference<FontContainerResourceListener> resourceListener;
        csl::ut::StringMap<IFont*> registeredFontsByName;
        csl::ut::MoveArray<FontContainerItem*> registeredFonts;
        csl::ut::MoveArray<FontContainerListener*> listeners;

        void RegisterFont(const char* name, IFont* font);

        FontContainer(csl::fnd::IAllocator* allocator);
    };
}
