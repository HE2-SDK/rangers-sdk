#pragma once

namespace hh::text {
    using ucsl::resources::converse_project::v4::ProjectSettings;
    using ucsl::resources::converse_project::v4::LanguageSettings;

    class TextAppModule
        : public fw::AppModule
        , public fnd::ResourceManager::ResourceListener
        , public fnd::ReloaderListener
        , public font::FontContainerListener
    {
        static TextAppModule* instance;
    public:
        csl::ut::VariableString defaultLocaleId;
        uint32_t unk102;
        ProjectSettings* projSettings;
        LanguageSettings* langSettings;
        uint64_t unk105; // hh::font::FontContainer*?
        csl::ut::MoveArray<void*> unk106;
        hh::fnd::Reference<TextLanguageDataCollection> textLanguageDataCollection;
        hh::fnd::Reference<TagReplaceableCollection> tagReplaceableCollection;

        virtual void ResourceLoadedCallback(fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;
        virtual void OnRegisteredFont(font::FontContainer* container, font::IFont* font, const char* name) override;

        static const ConverseData* Translate(const char* tag, int localeIdx);
        const ConverseData* GetTranslation(const char* tag, int localeIdx);
        static const ConverseData* GGetTranslation(const char* tag);
        const ConverseData* GetTranslation(const char* tag);
        virtual void AddCallback(hh::fw::Application* app) override;
        virtual void RemoveCallback() override;

        APPMODULE_CLASS_DECLARATION(TextAppModule)

        inline static TextAppModule* GetInstance() {
            return RESOLVE_STATIC_VARIABLE(instance);
        }
    };
}
