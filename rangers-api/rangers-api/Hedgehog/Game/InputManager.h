#pragma once

namespace hh::game {
    class InputComponent;
    class InputManager;
    class InternalPlayerInput : public fnd::ReferencedObject {
        uint32_t index;
        int32_t unk1;
        csl::ut::MoveArray<hid::InputMap*> inputMaps; // same length as InputManager's unk1
        csl::ut::MoveArray<InputComponent*> inputComponents;
        uint32_t maxMappingUnk1PlusOneOverAllInputMaps;
    public:
        void CreateInputMap(uint32_t index, hid::InputMapSettings* settings);
    };

    class InputManagerListener {
    public:
        virtual ~InputManagerListener();
        virtual void OnInputComponentRegistered(InputManager* manager, InputComponent& component) {}
        virtual void OnInputComponentUnregistered(InputManager* manager, InputComponent& component) {}
        virtual void OnInternalPlayerInputUpdated(InputManager* manager, int64_t playerInputid) {}
        virtual void IML_UnkFunc0() {}
    };

    class InputManager : public GameService, public GamePauseListener, public GameStepListener {
        csl::ut::MoveArray<hid::InputMapSettings*> inputMapSettings;
        csl::ut::MoveArray<InputComponent*> inputComponents;
        csl::ut::MoveArray<InternalPlayerInput*> internalPlayerInputs;
        csl::ut::InplaceMoveArray<InputManagerListener*, 1> listeners; // Something being done with this in RegisterInputComponent
        char activeInternalPlayerInputs; // bitmask
        int32_t unk6;
    public:
        struct SetupInfo {
            uint32_t internalPlayerInputCount;
            uint32_t inputMapSettingsCount;
            hid::InputMapSettings* settings;
        };
        void Setup(const SetupInfo& setupInfo);

        void RegisterInputComponent(InputComponent& inputComponent);
        void UnregisterInputComponent(InputComponent& inputComponent);
        void CreateInputMaps(hid::InputMapSettings* settings);
        void AddListener(InputManagerListener* listener);
        void RemoveListener(InputManagerListener* listener);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void DebugPauseUpdateCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
        virtual void PreStepCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(InputManager)
    };
}
