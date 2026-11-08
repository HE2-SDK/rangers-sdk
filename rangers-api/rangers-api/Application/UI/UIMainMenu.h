#pragma once

namespace app::ui {
    class UIScrollBarMouseControllerForRangers {
    public:
        struct Description {
            hh::ui::GOCUICollider* gocUiCollider;
            hh::ui::GOCSprite* gocSprite;
            hh::ui::UIListViewElement* uiListViewElement;
            const char* unkCastName0;
            const char* unkCastName1;
            float dword28;
            int priority;
            int dword30;
        };

        hh::fnd::Handle<hh::ui::GOCUICollider> gocUICollider;
        hh::ui::UIListViewElement* uiListViewElement;
        csl::ut::MoveArray<hh::ui::UICollider*> uiColliders;
        uint16_t word38;
        uint8_t byte3A;
        uint8_t gap3B;
        uint32_t dword3C;
        float float40;
        uint16_t word44;
        int dword48;
        int dword4C;
        uint8_t byte50;

        DEFAULT_CREATE_FUNC(UIScrollBarMouseControllerForRangers);
        virtual ~UIScrollBarMouseControllerForRangers() = default;

        void Setup(const Description& description);
        void SetActive(bool active);
        void Update(float deltaTime);
    };

    class UIVolumeGaugeMouseControllerForRangers {
    public:
        int64_t qword8;
        int64_t qword10;
        csl::ut::MoveArray<int64_t> qword18;
        short word38;
        char byte3A;
        int dword3C;
        float dword40;
        short word44;

        DEFAULT_CREATE_FUNC(UIVolumeGaugeMouseControllerForRangers);
        virtual ~UIVolumeGaugeMouseControllerForRangers() = default;
        void Update(float deltaTime);
    };

    class UIMainMenuContext : public app_cmn::fsm::GOCHsmContext, hh::hid::ActiveDeviceManagerListener {
    public:
        class State {
        public:
            csl::ut::MoveArray<csl::ut::Pair<size_t, size_t>> values;
            
            void SetValue(size_t id, unsigned int value);
            unsigned int GetValue(size_t id) const;
        };

        uint8_t byte28;
        State state;
        app::ut::TransitionValue<csl::math::Vector3> unk50;
        app::ut::TransitionValue<float> unkB0;
        char byteF8;
        char byteF9;
        uint32_t dwordFC;
        uint64_t qword100;
        uint64_t qword108;
        csl::ut::MoveArray<csl::ut::FixedString<64>> tooltipNames;
        uint64_t qword130;
        uint64_t qword138;
        uint64_t qword140;
        uint64_t qword148;
        uint64_t qword150;
        uint64_t qword158;
        csl::ut::MoveArray<void*> unk160;
        csl::ut::MoveArray<void*> unk180;
        csl::ut::MoveArray<void*> unk1A0;
        csl::ut::MoveArray<void*> unk1C0;
        csl::ut::MoveArray<void*> unk1E0;
        UIScrollBarMouseControllerForRangers unk200;
        UIScrollBarMouseControllerForRangers unk258;
        UIScrollBarMouseControllerForRangers unk2B0;
        UIScrollBarMouseControllerForRangers unk308;
        UIScrollBarMouseControllerForRangers unk360;
        uint64_t qword3B8;
        uint64_t qword3C0;
        uint64_t qword3C8;
        uint64_t qword3D0;
        uint64_t qword3D8;
        csl::ut::MoveArray<void*> unk3E0[3];
        uint64_t qword440;
        uint64_t qword448;
        uint64_t qword450;
        hh::gfnd::Renderable *renderable458;
        uint8_t byte460;

        DEFAULT_CREATE_FUNC(UIMainMenuContext);
        virtual void OnDeviceChange() override;

        UIScrollBarMouseControllerForRangers* GetScrollBar(unsigned int pageIndex) const;
    };

    class UIMainMenu
        : public hh::game::GameObject
        , public hh::ui::UIListener
        , public hh::fw::MouseEventHandler
        , public game::ApplicationDisplayOptionExtension::Listener {
    public:
        GAMEOBJECT_CLASS_DECLARATION(UIMainMenu);

        uint32_t unk201;
        int16_t unk202;
        hh::fnd::Reference<UIMainMenuContext> context;
        hh::fnd::Reference<hh::game::GOComponent> uiWireframe; //GOCUIWireframe
        uint8_t unk205;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UIL_UnkFunc1() override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk3() override;
        virtual bool MEH_Unk4() override;
        virtual void ADOEL_UnkFunc1(void* unkParam1, uint32_t unkParam2) override;
    };

    class UIMainMenuState {
    public:
        class Sound : public app_cmn::fsm::GOCStateBase<UIMainMenuContext> {
        public:
            char byte30[2];
            char byte32[7];
            int dword3C;
            hh::ut::TinyFsm<Sound> tinyFsm40;
            char byte88;
            int dword8C;
            char byte90;
            int dword94;
            char byte98;
            hh::ui::GOCSprite* gocSprite;
            hh::ui::GOCUICollider* gocUICollider;
            csl::fnd::IAllocator* qwordB0;
            short wordB8;
            UIVolumeGaugeMouseControllerForRangers uiVolumeGaugeMouseControllerC0;

            virtual bool StateStep(UIMainMenuContext& context, float deltaTime) override;
            virtual void StateEnter(UIMainMenuContext& context, int previousStateId) override;
            virtual void StateLeave(UIMainMenuContext& context, int nextStateId) override;

            DEFAULT_CREATE_FUNC(Sound);
        };
    };
}
