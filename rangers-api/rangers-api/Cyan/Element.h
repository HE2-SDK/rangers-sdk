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

        int64_t qword8;
        Element* self;
        int64_t qword18;
        int64_t qword20;
        int32_t dword28;
        Emitter* emitter;
        Resource::ElementParam* element;
        float dword40;
        float dword44;
        int32_t dword48;
        int32_t dword4C;
        csl::math::Vector3 position0;
        csl::math::Vector3 position1;
        csl::math::Vector3 spreadVector; //stores
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
        int8_t gap4Cbbc[48];
        csl::ut::Bitset<AxisFlag> unkVec2Axes;
        char byte11D;
        char byte11E; // 0x01 init children
        bool byte11F;
        EmitParam emitParam;
        AnimCtrl* childrenAnim[16];
        AnimCtrl* unkVec2Anim;
        AnimCtrl* scaleAnim;
        AnimCtrl* unkColorAnim0[4];
        AnimCtrl* unkColorAnim1[4];
        AnimCtrl* unkColorAnim2[4];
        AnimCtrl* unkAnim[2];
        AnimCtrl* modifierAnim[8][5];
        int64_t qword290[16];
        AnimCtrl* patternAnim[4];
        AnimCtrl* animationControl;
        float textureUvScale[2]; //unsure, when used, it's multiplied by worldScale
        int64_t qword480;
        int8_t gap488[648];
        HistoricalStripe* historicalStripe;
        int relatedToUpdateLight;
        HistoricalStripe* historicalStripe2;
        int unk738;
        uint32_t unk73C;
        int64_t qword730;
        int32_t dword738;
        int32_t dword73C;
        int64_t qword740;
        int64_t qword748;

        void UpdatePattern(float unk0, const Resource::TextureParam* textureParam, unsigned int unk1, float* unk2, float* unk3);
        void CalcTexcoordImpl(
            float arg0,
            const Resource::TextureParam* texParam,
            void* texcoord, //Cyan::Texcoord*
            float* matrix, //Cyan::Matrix23*
            float* p1,
            float* p2,
            unsigned int flags
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
        virtual void PrepareRender(Graphics::Renderer* renderer, void* effectObj) {} //Graphics::EffectObject* effectObj
        virtual void UnkFunc1() {}
        virtual int GetHistoricalStripeBufferSize() const;
        virtual ~Element();
        virtual void InitParameter() {}

        Element(Emitter* emitter, const Resource::ElementParam* element);
    };
}
