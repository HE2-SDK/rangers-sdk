#pragma once

namespace hh::gfx {
    class ResModelNeedle : public ResModelBase, public ResModelParameterInterface<ResModelNeedle> {
    public:
        bool unk201;
        needle::intrusive_ptr<needle::MeshResource> meshResource;
        csl::ut::MoveArray<fnd::ManagedResource*> dependencies; // Materials, textures, models, etc.
        csl::ut::MoveArray<csl::math::Matrix44> nodeMatrices;

        ResModelNeedle();

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;
        virtual uint32_t GetNodeCount() override;
        virtual csl::ut::MoveArray<csl::math::Matrix44> GetNodeMatrices() override;
        virtual int64_t GetParentNodeIndex(unsigned int nodeIndex) override;
        virtual const char* GetNodeName(unsigned int nodeIndex) override;
        virtual int32_t GetLODCount() override;
        virtual void* GetParameterInterface() override;
    };
}
