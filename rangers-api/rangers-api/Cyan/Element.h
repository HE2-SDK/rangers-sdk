#pragma once

namespace Cyan{
    class HistoricalStripe;

    

    class Element {
    public:
        enum class AxisFlag : unsigned char {
            X,
            Y,
            Z,
        };

        struct _Texcoord {
            csl::math::Vector2 current;
            csl::math::Vector2 start;
            csl::math::Vector2 step;
            AnimCtrl* tilingAnimation;
            AnimCtrl* rotationAnimation;
            AnimCtrl* offsetAnimation;
        };

        int64_t qword8;
        Element* self;
        int64_t qword18;
        int64_t qword20;
        int32_t dword28;
        Emitter* emitter;
        Resource::ElementParam* element;
        float dword40;
        float aliveTime;
        float dword48;
        int32_t dword4C;
        csl::math::Vector3 position;
        csl::math::Vector3 previousPosition;
        csl::math::Vector3 spreadVector;
        csl::math::Vector3 unkVec;
        csl::math::Vector3 unkVec2;
        csl::math::Position unkVec2Offset;
        csl::math::Position unkVec2Multiplier;
        float emitterSize[3];
        float emitterScale[3];
        float fps;
        int8_t gap4Cbb[12];
        float unk4Cbba;
        float unk4Cbbb;
        float directionJitter; //unsure
        unsigned int unkCount1;
        csl::ut::Color8 colors[2][2];
        float unk4C23f2f[2];
        float unk4C643w2[2][2];
        int8_t gap4Cbbc[4];
        csl::ut::Bitset<AxisFlag> unkVec2Axes;
        char byte11D;
        char byte11E; // 0x01 init children
        bool byte11F;
        EmitParam emitParam;
        AnimCtrl* childrenAnimation[16];
        AnimCtrl* unkVec2Animation;
        AnimCtrl* scaleAnimation;
        AnimCtrl* colorAnimation[2][2];
        AnimCtrl* alphaAnimation[2][2];
        AnimCtrl* unk4C643w2Animation[2][2];
        AnimCtrl* unk4C23f2fAnimation[2];
        AnimCtrl* modifierAnimation[8][5];
        int64_t qword290[16];
        AnimCtrl* patternAnimation[4];
        AnimCtrl* animationControl;
        float textureUvScale[2]; //unsure, when used, it's multiplied by worldScale
        _Texcoord texCoords[4][2];
        Matrix23 matrices[4][2];
        HistoricalStripe* historicalStripe1;
        int relatedToUpdateLight;
        uint32_t unk4r23414;
        int unk452434[4];
        HistoricalStripe* historicalStripe;
        unsigned int lightId;
        int32_t dword73C;
        int64_t qword740;
        int64_t qword748;

        void UpdatePattern(float unk0, const Resource::TextureParam* textureParam, unsigned int unk1, float* unk2, float* unk3);
        void CalcTexcoordImpl(
            float arg0,
            const Resource::TextureParam* texParam,
            _Texcoord* texcoord,
            Cyan::Matrix23* matrix,
            float* p1,
            float* p2,
            unsigned int scrollIdx
        );
        void CalcTexcoord(float unk);
        void InitColor(System::Random* random);
        void CalcInitVelocity(const csl::math::Vector3& accelaration, const csl::math::Vector3& velocity, const csl::math::Vector3& accelarationNormal);
        static void CalcSphericalVector(csl::math::Vector3* direction, Cyan::System::Random* random);
        MemObject<AnimCtrl> CreateAnimCtrl(
            const Resource::PtrData<Resource::AnimationParam>& animParam,
            unsigned int unk0,
            float unk1,
            const void* colorSet, //Cyan::ColorRandomSet*
            AnimCtrl::CreateParam::RandomSetType type
        );
        void InitElement();
        void EmitChild();

        virtual void Process(float unk);
        virtual void Update(float unk);
        virtual void PrepareRender(Graphics::Renderer* renderer, Graphics::EffectObject* effectObject) {} //Graphics::EffectObject* effectObj
        virtual void UnkFunc1(Graphics::Renderer* renderer, Graphics::EffectObject* effectObject) {}
        virtual int GetHistoricalStripeBufferSize() const;
        virtual ~Element();
        virtual void InitParameter() {}

        Element(Emitter* emitter, const Resource::ElementParam* element);
    };
}
