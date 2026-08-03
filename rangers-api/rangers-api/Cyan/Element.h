#pragma once

namespace Cyan{
    class HistoricalStripe;

    class FieldAnim {
    public:
        AnimCtrl* anims[5];

        FieldAnim();
    };

    class Element {
    public:
        class _Texcoord {
        public:
            float scroll[2];
            float scrollBase[2];
            float scale[2];
            AnimCtrl* scaleAnimation;
            AnimCtrl* rotationAnimation;
            AnimCtrl* positionAnimation;

            _Texcoord();
        };

        int64_t qword8;
        Element* self;
        int64_t qword18;
        int64_t qword20;
        int32_t dword28;
        Emitter* emitter;
        Resource::ElementParam* element;
        float dword40;
        float maybeTime; // used in Element::CalcTexcoordImpl
        int32_t dword48;
        int32_t dword4C;
        csl::math::Vector3 position0;
        csl::math::Vector3 position1;
        csl::math::Vector3 spreadVector; //stores
        csl::math::Vector3 unkVec;
        int8_t gap4Cb[40];
        float emitterSize[3];
        float emitterScale[3];
        float fps;
        int8_t gap4Cbb[20];
        float directionJitter; //unsure
        int8_t gap4Cbbb[48];
        short word11C;
        char word11E; // 0x01 init children
        char word11F;
        EmitParam emitParam;
        AnimCtrl* childrenAnim[16];
        AnimCtrl* qword220;
        AnimCtrl* scaleAnim;
        AnimCtrl* unkColorAnim0[4];
        AnimCtrl* unkColorAnim1[4];
        AnimCtrl* unkColorAnim2[4];
        AnimCtrl* modifierAnim[2];
        FieldAnim fieldAnims[8];
        int64_t qword290[16];
        AnimCtrl* patternAnim[4];
        AnimCtrl* animationControl;
        float textureUvScale[2]; //unsure, when used, it's multiplied by worldScale
        _Texcoord texcoords[8];
        float texcoordAffineMatrix0[6];
        int64_t gap488a;
        float texcoordAffineMatrix1[6];
        int64_t gap488[27];
        HistoricalStripe* historicalStripe;
        int relatedToUpdateLight;
        int8_t gap488b[20];
        int64_t qword730;
        int32_t dword738;
        int32_t dword73C;
        int64_t qword740;
        int64_t qword748;

        void UpdatePattern(float time, const Resource::TextureParam* textureParam, unsigned int unk1, float* unk2, float* unk3);
        void CalcTexcoordImpl(
            float time,
            const Resource::TextureParam* texParam,
            _Texcoord* texcoord,
            Matrix23* matrix,
            float* p1,
            float* p2,
            unsigned int flags
        );
        void CalcTexcoord(float time);
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

        virtual void Process(float time);
        virtual void Update(float time);
        virtual void PrepareRender(Graphics::Renderer* renderer, void* effectObj) {} //Graphics::EffectObject* effectObj
        virtual void UnkFunc1() {}
        virtual int GetHistoricalStripeBufferSize() const;
        virtual ~Element();
        virtual void InitParameter() {}

        Element(Emitter* emitter, const Resource::ElementParam* element);
    };
}
