#pragma once

namespace hh::game {
    class LevelManager;

    class LevelManagerListener {
    public:
        virtual ~LevelManagerListener() = default;

        virtual void LML_UnkFunc1() {}
        virtual void LML_UnkFunc2() {}
        virtual void LML_UnkFunc3() {}
        virtual void OnMasterLevelLoaded(LevelManager* levelManager, MasterLevel* masterLevel) {}
        virtual void LML_UnkFunc5() {}
    };

    class LevelManager
        : public hh::game::GameService
        , public hh::game::MasterLevelListener
        , public hh::fnd::ResourceManager::ResourceListener
        , public hh::fw::FrameworkFrameListener
    {
    public:
        struct Description {
            csl::fnd::IAllocator* levelAllocator;
            const char* levelsFilepath;
            char unk0;

            Description();
        };

        csl::fnd::IAllocator* levelAllocator;
        hh::fnd::ResourceLoader* resLoader;
        csl::ut::MoveArray<hh::game::MasterLevel*> masterLevels;
        csl::ut::InplaceMoveArray<LevelManagerListener*, 1> listeners;
        bool unk104;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void MLL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) override;
        virtual void MLL_UnkFunc2() override;
        virtual void MLL_UnkFunc3() override;
        virtual void ResourceLoadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void FFL_UnkFunc1() override;

        Level* GetLevelByName(const char* name) const;
        void LoadLevel(const char* name);
        void LoadLevel(const char* name, const Level::LoadInfo& loadInfo);
        void UnloadLevel(const char* name);
        void Setup(Description& desc);
        void FireMasterLevelLoadedCallback(MasterLevel* masterLevel);
        void SetLevelResourceAllocator(const char* levelName, csl::fnd::IAllocator* allocator);

        GAMESERVICE_CLASS_DECLARATION(LevelManager);
    };
}
