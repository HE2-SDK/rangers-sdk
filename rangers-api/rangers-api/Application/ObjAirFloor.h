#pragma once

namespace app {
    class ObjAirFloor : public hh::game::GameObject {
    public:
        enum class IdType {
            NORMAL,
            NOID,
        };

        struct Unk1 {
            float qword2C0;
            uint32_t qword2C4;
            uint32_t dword2C8;
            uint16_t word2CC;
            uint64_t qword2D0;
            IdType dword2D8;
            uint8_t byte2DC;
        };

        hh::gfx::GOCVisualModel* model;
        hh::game::GOCTransform* gocTransform;
        uint64_t qword258;
        hh::eff::EffectHandle hh__eff__effecthandle260;
        uint32_t dword270;
        uint32_t dword274;
        hh::fnd::Reference<gfx::ModelAnimationPlayer> modelAnimationPlayer;
        csl::math::Vector3 moveStart;
        csl::math::Vector3 moveEnd;
        float waitTime;
        float dword2A4;
        float dword2A8;
        uint32_t dword2AC;
        float qword2B0;
        float phase;
        uint8_t word2B8;
        bool word2B9;
        uint8_t byte2BA;
        Unk1 unk2C0;

		static const hh::game::GameObjectClass* GetClass();
        CREATE_FUNC(ObjAirFloor, IdType type);

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

    private:
		static const hh::game::GameObjectClass gameObjectClass;
		static hh::game::GameObject* Create(csl::fnd::IAllocator* allocator);

        void LoadModel();
    };
}
