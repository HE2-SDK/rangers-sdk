#pragma once

namespace app::game {
    class GameModeResourceManager
        : public hh::game::GameService
    {
    public:
        class ModuleList : public csl::ut::MoveArray<hh::fnd::Reference<GameModeResourceModule>> {
        public:
            void AddModule(hh::fnd::Reference<GameModeResourceModule>& module);
            void RemoveModule(hh::fnd::Reference<GameModeResourceModule>& module);
        };

        struct LevelLoaderEntry {
            uint32_t moduleNameHash;
            uint32_t gameModeNameHash;
            hh::fnd::Reference<hh::game::LevelLoader> levelLoader;
        };
        ModuleList modules;
        csl::ut::MoveArray<LevelLoaderEntry> levelLoaders; // first of pair is name hash
        hh::ut::TinyFsm<GameModeResourceManager> fsm;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        hh::game::LevelLoader* CreateLevelLoader(GameModeResourceModule* module);
        void AddModule(GameModeResourceModule* module);
        void RemoveModule(GameModeResourceModule* module);
        void CreateLevelLoaders(int namehash);

        GAMESERVICE_CLASS_DECLARATION(GameModeResourceManager)
    };
}
