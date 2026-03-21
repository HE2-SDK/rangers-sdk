#pragma once

namespace hh::needle{
    class Texture;
}

namespace Cyan {
    class Element;

    class EmitterDecl {};

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
            bool unk1;
        };

        struct EntryElement {
            Element* elem;
            EntryElement* nextElem;
            EntryElement* prevElem;
        };

        struct Unk1Resource {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        struct Unk2 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;

            Unk2(int index);
        };

        uint32_t flags;
        const Resource::EmitterParam* param;
        EffectImpl* effect;
        uint64_t qword40;
        uint64_t qword48;
        uint64_t qword50;
        EntryElement* entryElement;
        int elementCount;
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
        uint32_t billboardViewportId2;
        uint8_t gap3D4[16];
        float mask1[4];
        float mask2[4];
        uint8_t gap404[32];
        float unkMask3[2];
        float unkMask4[2];
        Resource::EmitterParam::CullMode cullMode;
        Unk2 unk438;
        bool unk450;
        bool unk451;
        bool unk452;
        float unk454;
        float unk458;
        float unk45C;
        float unk460;
        float unk464;
        float unk468;
        float unk46C;
        float unk470;
        uint32_t dword474;
        TextureInfo textureInfos[4];
        float unk4B8;
        float unk4BC;
        float unk4C0;
        float unk4C4;
        float unk4C8;
        float unk4CC;
        float unk4D0;
        float unk4D4;
        uint8_t gap4D8[4];
        float unkTexFloat0;
        float unkTexFloat1;
        float unkTexFloat2;
        float unk4E8;
        float unk4EC;
        float unk4F0;
        float unk4F4;
        float unk4F8[4];
        float unk508[4];
        uint64_t gap518;
        uint32_t unk520;
        float unk524;
        uint8_t gap528[16];
        float unk538;
        float unk53C;
        uint32_t gap540;
        float unk544;
        uint32_t unk548;
        uint32_t unk54C;
        uint32_t unk550;
        uint32_t unk554;
        uint8_t gap558[16];
        uint32_t qword568;
        uint32_t qword56C;
        uint64_t qword570;
        Graphics::MeshInstance* meshInstance;
        uint32_t qword580;
        uint32_t qword584;
        uint32_t qword588;
        uint32_t qword58C;
        uint8_t dword590;
        uint8_t dword591;
        uint8_t dword592;
        uint8_t dword593;
        uint64_t qword598;
        csl::ut::Color8 color;
        float emitRatio;
        uint32_t unk5A0;
        float unk5A4;
        float unk5A8;
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
        uint32_t dword658;
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
        float fps;
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
        uint8_t gapBB0[192]; // ResObj<NodeAnim>, but don't know exact size yet.
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
        uint8_t gap15E8[728];
        EmitterDecl* emitterDecl;
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
        virtual void Reset(const Resource::EmitterParam* param);
        virtual void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        virtual System::FSMState* GetState(unsigned int stateId);
        virtual void UnkFunc8();
        virtual void UnkFunc9(void* unkParam1);
        virtual void InitEmitter(bool useLocalMatrix);
        virtual void ProcessEmitter(float time);
        virtual void UpdateEmitter(float time);
        virtual void EmitElements(float time);
        virtual void EmitElements2(float time);

        void ProcessAnimations(float time);
        void RandomizeStartAndEndAngles();

        AnimCtrl* CreateAnimCtrl(const Resource::PtrData<Resource::AnimationParam>& param, unsigned int flags);
    };
}
