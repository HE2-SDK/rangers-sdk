#pragma once

namespace app::save {
    class SaveInterface : public hh::fw::SaveManagerInterface {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
        };

        struct Unk2 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
        };

        hh::fnd::UserId userId;
        csl::ut::MoveArray<hh::fnd::Reference<UserElement>> userElements;
        uint32_t dwordB8;
        uint32_t qwordBC;
        uint32_t qwordC0;
        uint32_t qwordC4;
        uint32_t qwordC8;
        uint8_t byteCC;
        uint32_t dwordD0[4];
        csl::ut::MoveArray<void*> unkE0;
        hh::fnd::FileSet unk100;
        uint64_t qword320;
        uint16_t word328;
        uint32_t dword32C;
        Unk2 dword330[11];

        SaveInterface(csl::fnd::IAllocator* allocator);

        void Initialize();

        UserElement* AddUserElement(const hh::fnd::UserId& userId);

        GameDataAc GetGameDataAccessor();
        ArcadeDataAc GetArcadeDataAccessor();
        OptionAc GetOptionAccessor();
        ChallengeDataAc GetChallengeDataAccessor();
        csl::ut::MoveArray<HeaderData>& GetSaveHeaderData(bool isExtra);

        hh::fw::SaveAsyncHandler SaveOptionData();
    };

    GameDataAc GetGameDataAccessor(hh::game::GameManager* gameManager);
    ArcadeDataAc GetArcadeDataAccessor(hh::game::GameManager* gameManager);
    OptionAc GetOptionAccessor(hh::game::GameManager* gameManager);
    ChallengeDataAc GetChallengeDataAccessor(hh::game::GameManager* gameManager);
    GameDataAc GetGameDataAccessor(hh::game::GameObject* gameObject);
    OptionAc GetOptionAccessor(hh::game::GameObject* gameObject);
    ChallengeDataAc GetChallengeDataAccessor(hh::game::GameObject* gameObject);
    ExtraFlagAc GetExtraFlagAccessor(hh::game::GameManager* gameManager);
    ExtraCharacterAc GetExtraCharacterAccessor(hh::game::GameManager* gameObject, unsigned int idx);
    ExtraCharacterAc GetExtraCharacterAccessor(hh::game::GameObject* gameObject, unsigned int idx);
    CharacterAc GetCharacterAccessor(hh::game::GameManager* gameManager, unsigned int idx);
    CharacterAc GetCharacterAccessor(GameDataAc* gameDataAc, unsigned int idx);
    CharacterAc GetSelectedCharacterAccessor(GameDataAc* gameDataAc, hh::game::GameManager* gameManager);
    CharacterAc GetCharacterAccessor(hh::game::GameObject* gameObject, unsigned int idx);
    bool IsBirthdayEnabled(hh::game::GameManager* gameManager);
}
