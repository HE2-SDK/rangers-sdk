#pragma once

namespace hh::text {
    class TagReplaceable : public fnd::ReferencedObject {
        csl::ut::VariableString unk1;
    public:
        TagReplaceable(csl::fnd::IAllocator* pAllocator);

        virtual void* UnkFunc1() = 0;
        virtual void* UnkFunc2() = 0;
        virtual uint32_t UnkFunc3(const char* entityName, void* unkParam2) = 0;
        virtual void* UnkFunc4(void* unkParam1) = 0;
        virtual bool UnkFunc5(const char* entityName, void* unkParam2) = 0;
        virtual void* UnkFunc6(wchar_t* text, unsigned int textLength, void* unkParam3) = 0;
        virtual void* UnkFunc7(const char* tag, void* unkParam2) = 0;
    };
}
