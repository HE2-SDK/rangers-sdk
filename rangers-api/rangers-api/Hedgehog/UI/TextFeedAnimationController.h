#pragma once

namespace hh::ui {
    class TextFeedAnimationController : public fnd::ReferencedObject, public font::TextTagWriterFeedListener {
    public:
        struct Description {
            SurfRide::Cast* cast;
            const char* feedSceneName;
            const char* feedCastName;
            const char* startAnimation;
            const char* unkName0;
            const char* unkName1;

            Description();
        };

        fnd::Handle<GOCSprite> hGOCSprite;
        fnd::Handle<SurfRideCastHandle> hCast;
        csl::ut::VariableString startAnimation;
        csl::ut::VariableString qword38;
        csl::ut::VariableString qword48;
        int64_t qword50;
        csl::ut::MoveArray<int64_t> qword58;

        TextFeedAnimationController(csl::fnd::IAllocator* allocator, GOCSprite* gocSprite);

        void Setup(const Description& desc);

        virtual int64_t TTWFL_UnkFunc3() override;
        virtual int64_t TTWFL_UnkFunc4() override;
        virtual void TTWFL_UnkFunc5(int64_t a2) override;
    };
}
