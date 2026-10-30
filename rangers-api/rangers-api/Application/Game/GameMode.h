#pragma once

namespace app::game {
    class GameService;
    class GameModeExtension;
    class GameMode : public hh::fnd::Messenger {
    public:
        hh::game::GameManager* gameManager;
        hh::fnd::SUpdateInfo updateInfo;
        uint64_t fsm[9]; // tinyfsm
        csl::ut::MoveArray<GameService*> gameServices;
        csl::ut::MoveArray<GameModeExtension*> extensions;
        hh::game::LevelLoader* levelLoader;
        uint32_t currentStateHash;
        char flags; //0x02 - off

        void SetState(unsigned int stateId);
        void DestroyExtensions();
        void DestroyServices();
		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool fUnk3(hh::fnd::Message& message) override;
        virtual bool UnkFunc4() { return true; }
        virtual void Initialize() {}
        virtual void Deinitialize(bool a2) {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual void UnkFunc9() {}
        virtual void UnkFunc10() {}
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) {}
        virtual int Shutdown();
        virtual void UnkFunc13() {}

        hh::game::GameService* GetService(hh::game::GameServiceClass* gameServiceClass) const;
        template<typename T>
        T* GetService() const {
            return (T*)GetService((hh::game::GameServiceClass*)T::GetClass());
        }
        void AddServices(const hh::game::GameServiceClass** gameServiceClass);
        void RegisterService(hh::game::GameService* gameService);

        GameModeExtension* GetExtension(unsigned int name) const;
        template<typename T>
        inline T* GetExtension() const {
            return (T*)GetExtension(csl::ut::HashString(T::name));
        }
        void AddExtension(GameModeExtension* extension);

        void SendMessageImm(hh::fnd::Message& message);

        GameMode(csl::fnd::IAllocator* allocator);
    };
}
