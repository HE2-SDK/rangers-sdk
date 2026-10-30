#pragma once

namespace app {
    class ObjCameraVolume : public hh::game::GameObject, public VolumeListener {
    public:
        struct Unk1 {
            hh::fnd::Handle<hh::fnd::Messenger> unk1;
            uint8_t unk2;

            Unk1(hh::fnd::Messenger* unk1Param);
        };

        uint8_t flags;
        uint8_t playersInsideFlags;
        csl::ut::InplaceMoveArray<unsigned int, 1> enterCountPerPlayer;
        VolumeTrigger volume;
        Unk1 unk3;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void OnEnter(hh::physics::MsgTriggerEnter& msg) override;
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) override;

        void TurnCameraOff(char playerId);

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjCameraVolume)
    };
}
