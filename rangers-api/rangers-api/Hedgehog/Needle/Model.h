#pragma once

#define NEEDLE_RESOURCE_MODEL_DATA 0x5441444C45444F4Dui64 // 'TADLEDOM'

namespace hh::needle {
    struct ShaderMaterialParameterSetting {};

    struct MaterialResourcePassSetupInfo {};
    struct MaterialResourcePassMeasureInfo {};
    class InstanceParameterContainerData;
    class InstanceParameterContainer;

    class ModelCreationInfoCreator : public NeedleObject {
        PODArray<InstanceParameterContainerData> instanceParameterContainerDatas;
        PODArray<InstanceParameterContainer> instanceParameterContainers;
        PODArray<unsigned short> unk1;
        uint64_t unk2;

    public:
        virtual void SetupMaterialPass(const MaterialResource* material, CNameIDObject* a3, const MaterialResourcePassSetupInfo* setupInfo, MaterialResourcePassMeasureInfo* measureInfo) const;
        virtual ~ModelCreationInfoCreator();

        void Setup(MeshResource* meshResource, const ShaderMaterialParameterSetting& shaderParamSetting, int64_t unk0);
    };

    class LocalModelCreationInfoCreator : public ModelCreationInfoCreator {

    };

    class Model : TNeedleRefcountUniqueObjectBase<TNeedleRefcountResource<NEEDLE_RESOURCE_MODEL_DATA, NeedleRefcountResource>> {
    public:
        MeshResource* GetMeshResource(unsigned int idx) const;
    };
}
