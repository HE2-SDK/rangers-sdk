#pragma once

namespace hh::dbg {
    class IniFile {
    public:
        struct Parameter {
            const char* name;
            union Value {
                const char* value;
                csl::ut::StringMap<Parameter*> parameters;
            };
        };

        csl::fnd::IAllocator* allocator;
        csl::ut::StringMap<Parameter*> parameters;

        IniFile(csl::fnd::IAllocator* allocator);

        unsigned int GetValueAsInt(const char* category, const char* name, unsigned int fallback);
        bool GetValueAsBool(const char* category, const char* name, bool fallback);
        const char* GetValueAsString(const char* category, const char* name, const char* fallback);
    };

    class IniFileHolder : public fnd::BaseObject, public csl::fnd::Singleton<IniFileHolder> {
    public:
        IniFile iniFile;
    };

    unsigned int GetIniValueAsInt(const char* category, const char* name, unsigned int fallback);
    bool GetIniValueAsBool(const char* category, const char* name, bool fallback);
    const char* GetIniValueAsString(const char* category, const char* name, const char* fallback);
}
