#pragma once
#include <ucsl/resources/converse-text/v6.h>

namespace hh::text {
    using ucsl::resources::converse_text::v6::Entry;

    // Purely done for tagging in-game functions
    class Attributes : public ucsl::resources::converse_text::v6::Attributes {
    public:
        ucsl::resources::converse_text::v6::AttributeEntry* GetEntry(const char* name) const;
        bool GetAttributeValue(const char* name, const char** result);
    };

    class ConverseData : public Entry {
    public:
        Attributes* GetAttributes() const;
    };
}
