#pragma once

namespace hh::text {
    class TagReplacer : public TagReplaceable {
    public:
        class Entity : public fnd::ReferencedObject {
            bool unk3;
            csl::ut::VariableString name;
            csl::ut::VariableString tag;
            csl::ut::MoveArray<wchar_t> text;
        public:
            Entity(csl::fnd::IAllocator* pAllocator, const char **name);
            static Entity* Create(csl::fnd::IAllocator* pAllocator, const char **name);
        };

    private:
        csl::ut::MoveArray<Entity*> entities;
        csl::ut::StringMap<Entity*> entitiesByName;

        Entity& GetEntityByName(const char* name);
        void RegisterEntity(Entity* entity);
    public:
        TagReplacer(csl::fnd::IAllocator* pAllocator);

        void SetLocalizationVariable(const char* name, const char* value);
        // void SetLocalizationVariable(const char* name);

        virtual void* UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual uint32_t UnkFunc3(const char* entityName, void* unkParam2) override;
        virtual void* UnkFunc4(void* unkParam1) override;
        virtual bool UnkFunc5(const char* entityName, void* unkParam2) override;
        virtual void* UnkFunc6(wchar_t* text, unsigned int textLength, void* unkParam3) override;
        virtual void* UnkFunc7(const char* tag, void* unkParam2) override;
    };
}
