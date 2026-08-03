#pragma once

namespace app::level {
    class ResMasterLevel;
}

namespace hh::game {
    class MasterLevelListener {
    public:
        virtual ~MasterLevelListener() = default;
        virtual void MLL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) {}
        virtual void MLL_UnkFunc2() {}
        virtual void MLL_UnkFunc3() {}
    };

    class MasterLevel : public fnd::ReferencedObject, public LevelListener {
    public:
        struct Description{
            app::level::ResMasterLevel* resource;
        };

        fnd::Reference<app::level::ResMasterLevel> resource;
        csl::ut::MoveArray<Level*> levels;
        csl::ut::StringMap<Level*> levelsByName;
        csl::ut::InplaceMoveArray<MasterLevelListener*, 1> listeners;
        csl::ut::MoveArray<Level*> unloadingLevels; // guessed from Level::Unload

        DEFAULT_CREATE_FUNC(MasterLevel);
        virtual void LL_UnkFunc1(Level* level) override;
        virtual void LL_UnkFunc2(Level* level) override;
        virtual void LL_UnkFunc3(Level* level) override;

        struct Unk1 {
            bool unk1;
        };

        void Setup(Description& desc);
        void AddListener(MasterLevelListener* listener);
        void RemoveListener(MasterLevelListener* listener);
        Level* GetLevel(const char* name) const;
        void LoadLevel(const char* name);
        Unk1 LoadLevel(const char* name, const Level::LoadInfo& loadInfo);
        Unk1 UnloadLevel(const char* name);
        void SetLevelResourceAllocator(const char* levelName, csl::fnd::IAllocator* allocator);

        inline void AddLevel(Level* level) {
            levels.push_back(level);
            levelsByName.Insert(level->name.c_str(), level);
        }
    };
}
