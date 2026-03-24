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

        struct Unk1Resource {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        enum class Flag : unsigned int {
            UNK0,
            UNK1,
            HAS_CHILD_EFFECTS,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            USE_DISTANCE_ATTENUATION,
            UNK8,
            UNK9,
            UNK10,
            UNK11,
            UNK12,
            UNK13,
        };

        csl::ut::Bitset<Flag> flags;
        const Resource::EmitterParam* param;
        EffectImpl* effect;
        Cyan::System::LinkList<Element> elements;
        csl::math::Matrix34 emitterMatrix;
        csl::math::Matrix34 poseMatrix;
        csl::math::Matrix34 localMatrix;
        csl::math::Matrix34 inheritMatrix;
        csl::math::Matrix34 invInheritMatrix;
        csl::math::Matrix34 emissionMatrix;
        csl::math::Matrix34 invEmissionMatrix;
        csl::math::Matrix34 emissionMatrix2;
        csl::math::Matrix34 poseMatrix2;
        csl::math::Matrix34 whoKnowsMatrix;
        csl::math::Matrix34 worldMatrix;
        csl::math::Vector3 position;
        csl::math::Vector3 scale;
        csl::math::Vector3 elementScale;
        System::Random random;
        uint64_t pad0;
        Graphics::EmitterDecl declaration;
        csl::ut::Color8 color;
        float emitRatio;
        uint32_t unk5A0;
        float unk5A4;
        float distanceAttenuation;
        float unk5AC;
        float unk5B0;
        uint8_t gap5B4[52];
        float unk5E8;
        uint8_t gap5EC[52];
        uint8_t unk5A0a;
        uint8_t gap5A0b[23];
        //Particle* particle630;
        Emitter* parentEmitter;
        uint64_t qword648;
        uint64_t qword650;
        float renderPriority;
        int dword65C;
        uint32_t billboardViewportId;
        uint8_t gap65Cb[4];
        FSMEmitter fsm;
        System::FreeListAllocator* renderAllocator;
        WaitingState waitingState;
        AliveState aliveState;
        DeadState deadState;
        uint64_t gap6C8;
        csl::math::Vector3 position1;
        csl::math::Vector3 rotation1;
        csl::math::Vector3 scale1;
        csl::math::Vector3 unkPosition;
        uint8_t gap6C8a[16];
        csl::math::Vector3 inheritPosition;
        float lifeTime;
        float unkTime;
        float unkTime2;
        float frequency;
        float subDivisionCount;
        float unkTime3;
        uint8_t gap6C8bbb[8];
        float emitCount;
        float accelerationMultiplier; 
        float accelerationNormalMultiplier; 
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
        AnimCtrl* animCtrl1;
        AnimCtrl* animCtrl2;
        AnimCtrl* animCtrl3;
        AnimCtrl* emitCountAnimation;
        AnimCtrl* accelerationMultiplierAnimation;
        AnimCtrl* accelerationNormalMultiplierAnimation;
        AnimCtrl* velocityMultiplierAnimation;
        AnimCtrl* shapeRadiusAnimation;
        AnimCtrl* velocityScaleAnimation;
        AnimCtrl* emitSizeAnimation;
        AnimCtrl* emitVectorAnimation;
        AnimCtrl* randomPositionAnimation;
        AnimCtrl* spreadAnimation;
        AnimCtrl* startAngleAnimation;
        AnimCtrl* endAngleAnimation;
        AnimCtrl* sizeAnimation;
        uint64_t qword830;
        AnimCtrl* nextFreeAnimCtrl;
        Resource::ResObject<Resource::Texture> textures[4];
        Resource::ResObject<Unk1Resource> unk1Resource;
        Resource::ResObject<Resource::Effect> childEffects[16];
        Resource::ResObject<Resource::Model> model;
        Resource::ResObject<Resource::Skeleton> skeleton;
        Resource::ResObject<Resource::NodeAnim> nodeAnim;
        System::LinkPool<EffectHandle, 32> childEffectHandlePool;
        Graphics::EffectObject* effectObject;
        Graphics::Renderer* renderer;
        Graphics::EmitterDecl* emitterDecl;
        int unk1860;
        float unk1864;
        uint64_t gap1868;
        csl::math::Vector3 unkVec1;
        csl::math::Vector3 unkVec2;
        csl::math::Vector3 unkVec3;
        csl::math::Vector3 unkVec4;
        AnimCtrl* unkVec1Animation;
        AnimCtrl* unkVec2Animation;
        AnimCtrl* unkVec3Animation;
        AnimCtrl* unkVec4Animation;
        uint8_t gap18B0[512];
        uint64_t qword1B38;
        Graphics::Renderer* renderer2;
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
        void CalcDistanceAttenuation();
        void EntryElement(Element* element);
        csl::math::Matrix34& GetEmissionMatrix();
        bool IsEnableEmit() const;

        virtual void Process(float unk) override;
        virtual uint64_t UnkFunc2(float unkParam1) override;
        virtual uint64_t UnkFunc3(void* unkParam1) override;
        virtual void UnkFunc4(void* unkParam1);
        virtual void Reset(const Resource::EmitterParam* param);
        virtual void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        virtual System::FSMState* GetState(unsigned int stateId);
        virtual void UnkFunc8(float time);
        virtual void UnkFunc9(void* unkParam1);
        virtual void InitEmitter(bool useLocalMatrix);
        virtual void ProcessEmitter(float time);
        virtual void UpdateEmitter(float time);
        virtual void EmitElements(float time);
        virtual void EmitElements2(float time);

        void ProcessAnimations(float time);
        void RandomizeStartAndEndAngles();
        void DeleteAllElements();
        void DeleteAllChildren();
        void DeleteAllAnimation();
        void StopChildren();

        AnimCtrl* CreateAnimCtrl(const Resource::PtrData<Resource::AnimationParam>& param, unsigned int flags);
    };
}
