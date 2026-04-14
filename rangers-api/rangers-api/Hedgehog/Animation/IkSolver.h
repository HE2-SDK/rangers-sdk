#pragma once

namespace hh::anim {
    class GOCAnimationSingle;
    class GOCCharacterIk;
}

namespace hh::anim::iksolver {
    class SolverBase : public hh::fnd::ReferencedObject {
    public:
        enum class SolverType : unsigned char {
            FOOT,
            HAND,
            LOOKAT,
        };

        struct Unk1 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
        };

        virtual void* GetRuntimeTypeInfo() const = 0;
        virtual bool UnkFunc1(unsigned char unkParam) const = 0;
        virtual void Initialize(GOCCharacterIk* gocCharacterIk, ResSkeleton* skeleton) = 0;
        virtual void Deinitialize(GOCCharacterIk* gocCharacterIk) = 0;
        virtual bool SetFloatParameter(SolverType solverType, float unkParam2, int index) = 0;
        virtual bool GetFloatParameter(SolverType solverType, float& unkParam2, int index) const = 0;
        virtual bool SetVectorParameter(SolverType solverType, const csl::math::Vector3& unkParam2, int index) = 0;
        virtual bool GetVectorParameter(SolverType solverType, csl::math::Vector3& unkParam2, int index) const = 0;
        virtual bool SetUnk1Parameter(SolverType solverType, const Unk1& unkParam2, int index) = 0;
        virtual bool GetUnk1Parameter(SolverType solverType, Unk1& unkParam2, int index) const = 0;
        virtual void Update(IkInfoBase* unkParam1, GOCAnimationSingle* gocAnimationSingle, float deltaTime) = 0;
        virtual bool UnkFunc11(void* unkParam1) = 0;
        virtual void UnkFunc12(void* unkParam1, SolverBase* unkParam2, GOCAnimationSingle* gocAnimationSingle) = 0;
    };

    class FootSolver : public SolverBase {
    public:
        csl::ut::InplaceMoveArray<float, 2> floatParameter;
        csl::ut::InplaceMoveArray<void*, 2> unk40;
        csl::ut::InplaceMoveArray<csl::math::Transform, 2> unk70;
        uint64_t qwordF0;

        DEFAULT_CREATE_FUNC(FootSolver);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc1(unsigned char unkParam) const override;
        virtual void Initialize(GOCCharacterIk* gocCharacterIk, ResSkeleton* skeleton) override;
        virtual void Deinitialize(GOCCharacterIk* gocCharacterIk) override;
        virtual bool SetFloatParameter(SolverType solverType, float unkParam2, int index) override;
        virtual bool GetFloatParameter(SolverType solverType, float& unkParam2, int index) const override;
        virtual bool SetVectorParameter(SolverType solverType, const csl::math::Vector3& unkParam2, int index) override;
        virtual bool GetVectorParameter(SolverType solverType, csl::math::Vector3& unkParam2, int index) const override;
        virtual bool SetUnk1Parameter(SolverType solverType, const Unk1& unkParam2, int index) override;
        virtual bool GetUnk1Parameter(SolverType solverType, Unk1& unkParam2, int index) const override;
        virtual void Update(IkInfoBase* unkParam1, GOCAnimationSingle* gocAnimationSingle, float deltaTime) override;
        virtual bool UnkFunc11(void* unkParam1) override;
        virtual void UnkFunc12(void* unkParam1, SolverBase* unkParam2, GOCAnimationSingle* gocAnimationSingle) override;
    };

    class HandSolver : public SolverBase {
        csl::ut::InplaceMoveArray<float, 2> floatParameter;
        csl::ut::InplaceMoveArray<Unk1, 2> unk40;

        DEFAULT_CREATE_FUNC(HandSolver);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc1(unsigned char unkParam) const override;
        virtual void Initialize(GOCCharacterIk* gocCharacterIk, ResSkeleton* skeleton) override;
        virtual void Deinitialize(GOCCharacterIk* gocCharacterIk) override;
        virtual bool SetFloatParameter(SolverType solverType, float unkParam2, int index) override;
        virtual bool GetFloatParameter(SolverType solverType, float& unkParam2, int index) const override;
        virtual bool SetVectorParameter(SolverType solverType, const csl::math::Vector3& unkParam2, int index) override;
        virtual bool GetVectorParameter(SolverType solverType, csl::math::Vector3& unkParam2, int index) const override;
        virtual bool SetUnk1Parameter(SolverType solverType, const Unk1& unkParam2, int index) override;
        virtual bool GetUnk1Parameter(SolverType solverType, Unk1& unkParam2, int index) const override;
        virtual void Update(IkInfoBase* unkParam1, GOCAnimationSingle* gocAnimationSingle, float deltaTime) override;
        virtual bool UnkFunc11(void* unkParam1) override;
        virtual void UnkFunc12(void* unkParam1, SolverBase* unkParam2, GOCAnimationSingle* gocAnimationSingle) override;
    };

    // float parameter 0 = angle offset
    // vector parameter 0 = target
    class LookAtSolver : public SolverBase {
        float angleOffset;
        csl::math::Vector3 target;

        DEFAULT_CREATE_FUNC(LookAtSolver);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc1(unsigned char unkParam) const override;
        virtual void Initialize(GOCCharacterIk* gocCharacterIk, ResSkeleton* skeleton) override;
        virtual void Deinitialize(GOCCharacterIk* gocCharacterIk) override;
        virtual bool SetFloatParameter(SolverType solverType, float unkParam2, int index) override;
        virtual bool GetFloatParameter(SolverType solverType, float& unkParam2, int index) const override;
        virtual bool SetVectorParameter(SolverType solverType, const csl::math::Vector3& unkParam2, int index) override;
        virtual bool GetVectorParameter(SolverType solverType, csl::math::Vector3& unkParam2, int index) const override;
        virtual bool SetUnk1Parameter(SolverType solverType, const Unk1& unkParam2, int index) override;
        virtual bool GetUnk1Parameter(SolverType solverType, Unk1& unkParam2, int index) const override;
        virtual void Update(IkInfoBase* unkParam1, GOCAnimationSingle* gocAnimationSingle, float deltaTime) override;
        virtual bool UnkFunc11(void* unkParam1) override;
        virtual void UnkFunc12(void* unkParam1, SolverBase* unkParam2, GOCAnimationSingle* gocAnimationSingle) override;
    };
}
