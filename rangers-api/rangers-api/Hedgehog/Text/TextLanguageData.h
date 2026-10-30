#pragma once

namespace hh::text {
    using ucsl::resources::converse_project::v4::Font;
    using ucsl::resources::converse_project::v4::Layout;

    class TextLanguageData : public fnd::ReferencedObject {
    public:
        csl::ut::VariableString localeId;
        int index;
        csl::ut::StringMap<Font*> fonts;
        csl::ut::StringMap<Layout*> layouts;
        hh::fnd::Reference<ConverseDataCollection> converseDataCollection;
        csl::fnd::Mutex mutex;

        TextLanguageData(csl::fnd::IAllocator* pAllocator, const char* localeId, int index);
        const ConverseData& GetTranslation(const char* tag);
    };
}
