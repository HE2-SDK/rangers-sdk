#pragma once

namespace hh::dv{
    struct PageInfo {
        int ticksEnabled;
        int curPageStart0;
        int curPageStart1;
        int curPageEnd;
        int unk1;
        int unk2;
        int unk3;
        int unk4;
        int unk5;
        int unk6;
        int unk7;
        int unk8;
        int unk9;
        int unk10;
        int unk11;
        int unk12;
        int unk13;
        int frameTakenToLoad;
        int unk15;
        int unk16;
        int unk17;
        int flags;
        int unk19;
        int unk20;
    };

    class DvSceneTimeline : public fnd::ReferencedObject {
    public:
        struct DisableFrame {
        public:
            float start;
            float end;
        };

        int preCurrentFrame;
        int postCurrentFrame;
        int frameStart;
        int frameEnd;
        int currentCut;
        int currentPage;
        bool looping;
        csl::ut::MoveArray<float> cuts;
        csl::ut::MoveArray<DisableFrame> disableFrames;
        csl::ut::MoveArray<DvPage*> pages;
        int cameraFrameProgressionCount;
        float* cameraFrameProgression;
        float* cameraFrameProgressionSpeed;
        PageInfo pageInfo;

        void Clear();
        void SetFrameStartEnd(float start, float end);
        float GetSpeedByFrame(int currentFrame) const;
        void InitializeCuts(int64_t cutCount, float* cuts);
        void InitializeDisableFrames(int64_t disableFrameCount, DisableFrame* disableFrames);
        void InitializePages(void* pages, int64_t pageCount, hh::dv::DvSceneControl* dvsc);
        DvPage* GetPage(unsigned int pageId) const;
        DvPage* GetPage(char* pageName) const;

        DvSceneTimeline(csl::fnd::IAllocator* allocator);
    };
}
