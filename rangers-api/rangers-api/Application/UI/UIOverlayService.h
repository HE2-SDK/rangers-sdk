#pragma once

namespace app::ui {
    class UIOverlayService : public hh::game::GameService, public hh::game::GameUpdateListener, public app::fnd::AppResourceManagerListener {
    public:
        class OverlayJob : public hh::fnd::BaseObject {
        public:
            unsigned int id;
            hh::fnd::Reference<RequestOverlayBegin> request;
            hh::fnd::Handle<hh::game::GameObject> requestObject;

            inline OverlayJob(csl::fnd::IAllocator* allocator) : hh::fnd::BaseObject{ allocator } {}
        };

        struct OverlayJobStatus {
            bool unk0;
            unsigned int unkStatus;
            char unk1;
            int unk2;
            int selectionIdx;
        };

        csl::fnd::Mutex mutex1;
        csl::fnd::Mutex mutex2;
        uint8_t unk100;
        csl::ut::StringMap<hh::fnd::Handle<hh::fnd::Messenger>> unk101;
        uint64_t lastQueuedJobId;
        hh::fnd::Handle<hh::game::GameObject> unk103;
        hh::fnd::Handle<hh::game::GameObject> relatedToAppResourceManager; // usually UIIndicator?
        uint64_t unk104;
        uint32_t unk105;
        uint32_t unk106[2];
        uint16_t unk107;
        csl::ut::MoveArray<OverlayJob*> queuedOverlayJobs;
        csl::ut::MoveArray<OverlayJob*> aliveOverlayJobs;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreGameUpdateCallback(hh::game::GameManager* gameManager, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void PostGameUpdateCallback(hh::game::GameManager* gameManager, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void ARML_UnkFunc0(int unkParam1) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;

        int QueueBeginRequest(RequestOverlayBegin* request); // returns id of the job
        OverlayJob* GetJobById(unsigned int id) const;
        void GetJobStatus(unsigned int id, OverlayJobStatus& status);

        GAMESERVICE_CLASS_DECLARATION(UIOverlayService);
    };
}
