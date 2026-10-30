#pragma once

namespace app::game {
    class ApplicationFpsExtension : public ApplicationExtension, public hh::game::GameManagerListener {
    public:
        char fps; // unsure
        char byte21;
        int dword24;
        int dword28;
        short word2C;

        virtual uint64_t GetNameHash() override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;

        ApplicationFpsExtension(csl::fnd::IAllocator* allocator);
    };
}
