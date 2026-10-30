#pragma once

namespace app::game {
    class ApplicationDisplayOptionExtension : public ApplicationExtension, public hh::game::GameManagerListener {
    public:
        static constexpr const char* name = "ApplicationDisplayOptionExtension";

        struct Listener {
            virtual void ADOEL_UnkFunc1(void* unkParam1, uint32_t unkParam2) {}
        };

        int64_t resolutionX_Y;
        int dword28;
        csl::ut::MoveArray<int64_t> qword30;

        ApplicationDisplayOptionExtension(csl::fnd::IAllocator* allocator);

        virtual uint64_t GetNameHash() override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;

        void SetWindowResolution(int64_t widthHeight, bool updateWindow);

		virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;
    };
}
