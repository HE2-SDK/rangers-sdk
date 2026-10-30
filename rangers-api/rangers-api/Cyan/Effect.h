#pragma once

namespace hh::eff{
    class ResEffect;
}

namespace Cyan {
    struct PerEffectData {
        int64_t unk0;
        int unk1;
        float unk2;
        int unk3;
        char unk4[0x100];
        int64_t unk5;
        csl::math::Matrix44 unk6;
    };

    class Effect;
    class Emitter;
    class EffectHandle {
    public:
        int unk1;
        Effect* effect;
        EffectHandle();
        EffectHandle(const EffectHandle& other);

        const csl::math::Vector3& GetScale() const;
        const csl::ut::Color8& GetColor() const;
        uint8_t GetAlpha() const;

        void SetScale(const csl::math::Vector3& scale);
        void SetColor(const csl::ut::Color8& color);
        void SetAlpha(uint8_t alpha);
    };

    class Effect {
    public:
        struct SetupInfo { };

        virtual void Start() = 0;
        virtual void Stop(bool unk) = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;
        virtual bool IsPaused() const = 0;
        virtual void Step() = 0;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) = 0;
        virtual csl::math::Matrix34 GetMatrix() const = 0;
        virtual void SetColor(csl::ut::Color8 color) = 0;
        virtual csl::ut::Color8 GetColor() const = 0;
        virtual void SetAlpha(unsigned char alpha) = 0;
        virtual unsigned char GetAlpha() const = 0;
        virtual void SetScale(const csl::math::Vector3& scale) = 0;
        virtual csl::math::Vector3 GetScale() const = 0;
        virtual void SetElementScale(const csl::math::Vector3 scale) = 0;
        virtual csl::math::Vector3 GetElementScale() const = 0;
        virtual void SetEmitRatio(float emitRatio) = 0;
        virtual float GetEmitRatio() const = 0;
        virtual void* GetData() = 0;
        virtual Resource::EffectParam* GetParam() const = 0;
        virtual const char* GetName() const = 0;
        virtual void* GetUnk1() const = 0;
        virtual void SetViewMask(unsigned int viewMask) = 0;
        virtual unsigned int GetViewMask() const = 0;
        virtual void SetUnk2(unsigned int value) = 0;
        virtual unsigned int GetUnk2() const = 0;
        virtual void SetVisibility(bool enabled) = 0;
        virtual bool GetVisibility() const = 0;
        virtual void SetBillboardViewportID(unsigned int viewportId) = 0;
        virtual void* UnkFunc30() = 0;
        virtual void Setup(SetupInfo& setupInfo) = 0;
        virtual void SetUnk3(float value) = 0;
        virtual void SetUnk4(float value) = 0;
        virtual bool GetUnk5() const = 0;
        virtual bool GetUnk6() const = 0;
        virtual bool GetUnk7() const = 0;
        virtual ~Effect() = default;
    };

    class EffectImpl : public Effect {
    public:
        struct SetupInfo : Effect::SetupInfo {
            hh::eff::ResEffect* resource;
            int64_t unk0;
            int64_t unk1;
            int32_t unk2;
            int64_t unk3;
        };

        char name[128];
        ManagerImpl* manager;
        uint64_t root;
        Resource::EffectParam* effectParam;
        uint32_t dwordA0;
        uint32_t viewMask;
        uint32_t dwordA8;
        Emitter* emitter;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        EffectHandle hh__eff__effecthandleE8;
        EffectHandle hh__eff__effecthandleF8;
        uint32_t flags; // 0x02 = is paused, 0x80 = is visible
        uint64_t qword110;
        hh::needle::NeedleRefcountObject* qword118;
        uint64_t qword120;
        uint32_t dword128;
        uint64_t qword130;
        PerEffectData* perEffectData;

        EffectImpl(ManagerImpl* managerImpl, Resource::EffectParam* effectParam, unsigned int unkParam1, void* unkParam2, const InheritChildParam* unkParam3, void* unkParam4, bool unkParam5, int unkParam6);

        void SetDataBuffer(PerEffectData* data);
        void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        float GetWorldScale() const;

        virtual void Start() override;
        virtual void Stop(bool unk) override; //bool prolly means "immediately"
        virtual void Pause() override;
        virtual void Resume() override;
        virtual bool IsPaused() const override;
        virtual void Step() override;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) override;
        virtual csl::math::Matrix34 GetMatrix() const override;
        virtual void SetColor(csl::ut::Color8 color) override;
        virtual csl::ut::Color8 GetColor() const override;
        virtual void SetAlpha(unsigned char alpha) override;
        virtual unsigned char GetAlpha() const override;
        virtual void SetScale(const csl::math::Vector3& scale) override;
        virtual csl::math::Vector3 GetScale() const override;
        virtual void SetElementScale(const csl::math::Vector3 scale) override;
        virtual csl::math::Vector3 GetElementScale() const override;
        virtual void SetEmitRatio(float emitRatio) override;
        virtual float GetEmitRatio() const override;
        virtual void* GetData() override;
        virtual Resource::EffectParam* GetParam() const override;
        virtual const char* GetName() const override;
        virtual void* GetUnk1() const override;
        virtual void SetViewMask(unsigned int viewMask) override;
        virtual unsigned int GetViewMask() const override;
        virtual void SetUnk2(unsigned int value) override;
        virtual unsigned int GetUnk2() const override;
        virtual void SetVisibility(bool enabled) override;
        virtual bool GetVisibility() const override;
        virtual void SetBillboardViewportID(unsigned int viewportId) override;
        virtual void* UnkFunc30() override;
        virtual void Setup(Effect::SetupInfo& setupInfo) override;
        virtual void SetUnk3(float value) override;
        virtual void SetUnk4(float value) override;
        virtual bool GetUnk5() const override;
        virtual bool GetUnk6() const override;
        virtual bool GetUnk7() const override;
        virtual void SetUnk8(bool enabled);
    };
}
