#pragma once

#define NEEDLE_RESOURCE_MODEL_INSTANCE 0x3030534E494C444Dui64 // '00SNILDM'

namespace hh::needle {
    struct ModelInstanceData {
        char unk0[16];
        Model* model;
        void* shader;
        void* unk1;
        char unk2;
        char unk3[31];
        csl::math::Position* aabb; // csl::math::Position[2]*
        char unk3b[8];
        int unk4;
        int unk5;
        char unk6[12];
    };

    class ModelInstance : public TNeedleRefcountResource<NEEDLE_RESOURCE_MODEL_INSTANCE, NeedleRefcountResource> {
    public:
        ModelInstanceData instanceData;
        EntryLink link;
        char unk1;
        int unk2;

        virtual void UnkFunc8();
        virtual void UnkFunc9();
        virtual void UnkFunc10() {}
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual void UnkFunc13();
        virtual void UnkFunc14();
        virtual void UnkFunc15();

        ModelInstance();

        int GetParameterValueObjectContainerByName(CNameIDObject* name);
        ParameterValueObjectContainer* GetParameterValueObjectContainer(int index);

        static ModelInstance* Create(Model* model, ModelInstanceRenderer* renderer);
    };
}
