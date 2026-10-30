#pragma once

namespace app::save{
    class SavePermission : public hh::fnd::BaseObject {
    public:
        hh::game::GameManager* gameManager;
        char unk0;

        SavePermission(csl::fnd::IAllocator* allocator, hh::game::GameManager* gameManager, char unk0, bool denySave);
        static SavePermission* Create(hh::game::GameObject* gameObject);
    };
}
