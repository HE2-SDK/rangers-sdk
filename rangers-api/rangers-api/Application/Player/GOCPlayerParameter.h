#pragma once

namespace app::player {
    class GOCPlayerParameter : public hh::game::GOComponent {
    public:
        enum class Mode : uint32_t {
            NORMAL,
            WATER,
            CYBERSPACE_FORWARD_VIEW,
            CYBERSPACE_SIDE_VIEW,
        };

        enum class SuperState : uint32_t {
            NORMAL_SONIC,
            SUPER_SONIC,
            SUPER_SONIC_2,
        };

        union CharacterModePackage {
            heur::rfl::ModePackageSonic sonic;
            heur::rfl::ModePackageAmy amy;
            heur::rfl::ModePackageKnuckles knuckles;
            heur::rfl::ModePackageTails tails;
            heur::rfl::ModePackage unknown;
        };

        hh::fnd::Reference<hh::fnd::ResReflection> characterParameters;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::PlayerCameraSetParameters>> cameraSetParameters;
        heur::rfl::ModePackage* modePackages[4];
        heur::rfl::WaterModePackage* waterModePackage;
        Mode mode;
        SuperState superState;
        CharacterId characterId;
        heur::rfl::PlayerParamCommon* commonParameters[4];
        heur::rfl::PlayerParamSpeed* speedParameters[4];
        heur::rfl::PlayerParamJump* jumpParameters[4];
        heur::rfl::PlayerParamJumpSpeed* jumpSpeedParameters[4];
        heur::rfl::PlayerParamDoubleJump* doubleJumpParameters[4];
        heur::rfl::PlayerParamBoost* boostParameters[4];
        heur::rfl::PlayerParamAirBoost* airBoostParameters[4];

    private:
        void* GetPlayerParameter(const hh::fnd::RflClass& rflClass);
    public:
        struct SetupInfo {
            uint32_t flags;
            hh::fnd::ResReflection* characterParameters;
            hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::PlayerCameraSetParameters>> cameraSetParameters;
            CharacterId characterId;
        };

        GOCPlayerParameter(csl::fnd::IAllocator* allocator);
        void Setup(const SetupInfo& setupInfo);

        heur::rfl::PlayerParamCommon& GetCommonParameters() const;
        heur::rfl::PlayerParamSpeed& GetSpeedParameters() const;
        heur::rfl::PlayerParamJump& GetJumpParameters() const;
        heur::rfl::PlayerParamJumpSpeed& GetJumpSpeedParameters() const;
        heur::rfl::PlayerParamDoubleJump& GetDoubleJumpParameters() const;
        heur::rfl::PlayerParamBoost& GetBoostParameters() const;
        heur::rfl::PlayerParamAirBoost& GetAirBoostParameters() const;

        heur::rfl::PlayerParamAcceleCombo& GetAcceleComboParameters() const;
        heur::rfl::PlayerParamLoopKick& GetLoopKickParameters() const;
        heur::rfl::PlayerParamCrasher& GetCrasherParameters() const;
        heur::rfl::PlayerParamSpinSlash& GetSpinSlashParameters() const;
        heur::rfl::PlayerParamChargeAttack& GetChargeAttackParameters() const;
        heur::rfl::PlayerParamStompingAttack& GetStompingAttackParameters() const;
        heur::rfl::PlayerParamComboFinish& GetComboFinishParameters() const;
        heur::rfl::PlayerParamSonicBoom& GetSonicBoomParameters() const;
        heur::rfl::PlayerParamCrossSlash& GetCrossSlashParameters() const;
        heur::rfl::PlayerParamHomingShot& GetHomingShotParameters() const;
        heur::rfl::PlayerParamSmash& GetSmashParameters() const;

        void SetMode(Mode mode);
        void SetSuperState(SuperState state);

        template<typename T>
        T* GetPlayerParameter() {
            return reinterpret_cast<T*>(GetPlayerParameter(RESOLVE_STATIC_VARIABLE(T::rflClass)));
        }

        // template<typename T>
        // T* GetPlayerParameter(const hh::fnd::RflClass& rflClass) {
        //     return reinterpret_cast<T*>(GetPlayerParameter(rflClass));
        // }

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void LoadParameters();

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerParameter)
    };
}
