#pragma once

namespace hh::needle{
    class Texture;
}

namespace Cyan {
    class Element;

    class Emitter : public System::Job {
    public:
        class FSMEmitter : public System::FSM {
        public:
            FSMEmitter();
        };

        class StateBase : public System::FSMState {
        public:
            inline Emitter* GetEmitter(System::FSMContext* ctx) { return reinterpret_cast<Emitter*>(ctx->owner); }

            virtual ~StateBase();
            virtual void OnEnter(System::FSMContext* ctx) override {}
            virtual void OnUpdate(System::FSMContext* ctx) override {}
            virtual void OnExit(System::FSMContext* ctx) override {}
        };

        class WaitingState : public StateBase {
        public:
            WaitingState();

            virtual void OnUpdate(System::FSMContext* ctx) override;
        };

        class AliveState : public StateBase {
        public:
            bool alive;
            bool dead;

            AliveState();

            virtual void OnEnter(System::FSMContext* ctx) override;
            virtual void OnUpdate(System::FSMContext* ctx) override;
            virtual void OnExit(System::FSMContext* ctx) override;
            virtual void UnkFunc1(System::FSMContext* ctx);
        };

        class DeadState : public StateBase {
        public:
            DeadState();

            virtual void OnEnter(System::FSMContext* ctx) override;
        };

        struct TextureInfo {
            hh::needle::Texture* texture;
            char index;
            char unk0;
        };

        struct EntryElement {
            Element* elem;
            EntryElement* nextElem;
            EntryElement* prevElem;
        };

        uint32_t flags;
        const Resource::EmitterParam* param;
        EffectImpl* effect;
        uint64_t qword40;
        uint64_t qword48;
        uint64_t qword50;
        EntryElement* entryElement;
        uint32_t elementCount;
        csl::math::Matrix34 emitterMatrix;
        csl::math::Matrix34 poseMatrix;
        csl::math::Matrix34 localMatrix;
        csl::math::Matrix34 inheritMatrix;
        csl::math::Matrix34 invInheritMatrix;
        csl::math::Matrix34 emissionMatrix;
        csl::math::Matrix34 invEmissionMatrix;
        uint8_t gap64bbb[188];
        csl::math::Matrix34 worldMatrix;
        csl::math::Vector3 position;
        csl::math::Vector3 scale;
        csl::math::Vector3 elementScale;
        System::Random random;
        uint64_t pad0;
        uint64_t qword370; //pointer to self, prolly struct here
        uint64_t pad1;
        uint64_t qword380;
        uint64_t qword388;
        uint64_t qword390;
        uint64_t qword398;
        uint64_t qword3A0;
        uint64_t qword3A8;
        uint64_t qword3B0;
        uint64_t qword3B8;
        csl::math::Vector4 csl__math__vector43C0;
        uint32_t dword3D0;
        uint8_t gap3D4[96];
        Resource::EmitterParam::CullMode cullMode;
        uint8_t gap3D4b[60];
        uint32_t dword474;
        TextureInfo textureInfos[4];
        uint8_t gap4B8[176];
        uint64_t qword568;
        uint64_t qword570;
        uint64_t qword578;
        uint64_t qword580;
        uint64_t qword588;
        uint32_t dword590;
        uint64_t qword598;
        csl::ut::Color8 color;
        float emitRatio;
        uint8_t gap5A0[152];
        //Particle* particle630;
        Emitter* parentEmitter;
        uint64_t qword648;
        uint64_t qword650;
        uint32_t dword658;
        uint8_t gap65C[4];
        uint32_t billboardViewportId;
        uint8_t gap65Cb[4];
        FSMEmitter fsm;
        System::FreeListAllocator* renderAllocator;
        WaitingState waitingState;
        AliveState aliveState;
        DeadState deadState;
        uint8_t gap6C8[88];
        csl::math::Vector3 inheritPosition;
        float fps;
        float maybeTime; // used in Element::CalcTexcoordImpl
        uint8_t gap6C8bb[4];
        float frequency;
        float subDivisionCount;
        uint8_t gap6C8bbb[12];
        float emitCount;
        float accelarationMultiplier; 
        float accelarationNormalMultiplier; 
        float initialSpeed; 
        float velocityMultiplier; 
        float shapeRadius; 
        float velocityScale;
        float emitSize;
        bool useEmitVector;
        csl::math::Position emitVector;
        float emitVectorJitter;
        float directionJitter;
        csl::math::Position randomPosition;
        float spread;
        float startAngle; //randomized, multiplied by Random::GetFloat
        float endAngle; //randomized, multiplied by Random::GetFloat
        float sizeX;
		float sizeXJitter;
		float sizeY;
		float sizeYJitter;
		float sizeZ;
		float sizeZJitter;
        uint8_t gap6C8b[136];
        uint64_t qword838;
        uint64_t qword840;
        Resource::TextureParam textures[4];
        uint8_t byteA88;
        uint8_t gapA89[127];
        uint64_t qwordB08;
        uint64_t qwordB10;
        uint64_t qwordB18;
        uint8_t gapB20[2304];
        uint8_t byte1420;
        uint8_t gap1421[127];
        uint64_t qword14A0;
        uint64_t qword14A8;
        uint64_t qword14B0;
        uint32_t dword14B8;
        uint64_t qword14C0;
        uint8_t byte14C8;
        uint8_t gap14C9[127];
        uint64_t qword1548;
        uint64_t qword1550;
        uint8_t byte1558;
        uint8_t gap1559[127];
        uint64_t qword15D8;
        uint64_t qword15E0;
        uint8_t gap15E8[1360];
        uint64_t qword1B38;
        Graphics::Renderer* renderer;
        uint64_t qword1B48;
        csl::math::Vector3 m1281B50;
        csl::math::Vector3 oword1B60;
        csl::math::Vector3 oword1B70;
        csl::math::Vector3 oword1B80;
        csl::math::Vector3 oword1B90;
        csl::math::Vector3 oword1BA0;
        csl::math::Vector3 oword1BB0;

        Emitter(EffectImpl* effect, const Resource::EmitterParam* param);

        void Start();
        void Stop(bool unk);
        void Pause();
        void Resume();
        void Step();
        void SetMatrix(const csl::math::Matrix34& matrix);
        csl::math::Matrix34 GetMatrix() const;
        void SetColor(csl::ut::Color8 color);
        inline csl::ut::Color8 GetColor() const { return color; }
        void SetAlpha(char alpha);
        inline char GetAlpha() const { return color.a; }
        void SetScale(const csl::math::Vector3& scale);
        inline csl::math::Vector3 GetScale() const { return scale; }
        void SetElementScale(const csl::math::Vector3& scale);
        inline csl::math::Vector3 GetElementScale() const { return elementScale; }
        void SetEmitRatio(float emitRatio);
        inline float GetEmitRatio() const { return emitRatio; }
        void SetViewMask(unsigned int viewMask);
        //inline unsigned int GetViewMask() const { return viewMask; }
        void SetVisibility(bool enabled);
        inline void SetBillboardViewportID(unsigned int viewportId) { billboardViewportId = viewportId; }
        inline unsigned int GetBillboardViewportID() const { return billboardViewportId; }
        void CalcLocalMatrix();
        void CalcPoseMatrix(csl::math::Matrix34* outMatrix) const;
        void CalcInheritMatrix(const csl::math::Matrix34& poseMatrix, unsigned int flags, float inheritRate, csl::math::Matrix34* outMatrix, csl::math::Vector3* outTranslation) const;
        void EntryElement(Element* element);
        csl::math::Matrix34& GetEmissionMatrix();
        bool IsEnableEmit() const;

        virtual void Process(float unk) override;
        virtual uint64_t UnkFunc2(float unkParam1) override;
        virtual uint64_t UnkFunc3(void* unkParam1) override;
        virtual void UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(const Resource::EmitterParam* param);
        virtual void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        virtual System::FSMState* GetState(unsigned int stateId);
        virtual void UnkFunc8();
        virtual void UnkFunc9(void* unkParam1);
        virtual void InitEmitter(bool useLocalMatrix);
        virtual void ProcessEmitter(float time);
        virtual void UpdateEmitter(float time);
        virtual void EmitElements(float time);
        virtual void EmitElements2(float time);
    };
}
