#pragma once

namespace hh::game {
    class Level;

    class LevelListener {
    public:
        virtual ~LevelListener() = default;

        virtual void LL_UnkFunc1(Level* level) {}
        virtual void LL_UnkFunc2(Level* level) {}
        virtual void LL_UnkFunc3(Level* level) {}
    };

    class MasterLevel;
    class Level : public fnd::ReferencedObject {
    public:
        csl::ut::VariableString name;
        MasterLevel* masterLevel;
        fnd::Reference<ResLevel> resource;
        csl::ut::InplaceMoveArray<csl::ut::VariableString, 2> files;
        fnd::Reference<fnd::ResourceLoader> resourceLoader;
        csl::ut::MoveArray<Level*> dependencies;
        csl::ut::InplaceMoveArray<LevelListener*, 1> listeners;
        bool loaded;
        uint16_t wordCA;
        uint32_t loadStatus;
        uint8_t byteD0;
        int dwordD4;
        csl::ut::VariableString unk1;
        csl::ut::VariableString unk2;

        struct LoadInfo {
            uint8_t unk1{};
            int unk2{};
            const char* unk3{};
            const char* unk4{};
        };

        CREATE_FUNC(Level, const char* name, MasterLevel* masterLevel);
        void Setup(); // not correct, extra parameter

        void AddListener(LevelListener* listener);
        void RemoveListener(LevelListener* listener);
        void AddDependency(Level* dependency);
        void AddResource(const char* resource);
        void Load();
        void Load2();
        void Load3(const LoadInfo& loadInfo);
        void Unload();
        void SetResourceAllocator(csl::fnd::IAllocator* allocator);
    };
}
