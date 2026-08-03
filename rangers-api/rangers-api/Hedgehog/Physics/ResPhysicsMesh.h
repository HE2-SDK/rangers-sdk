#pragma once
#include <ucsl/resources/btmesh/v3.h>

namespace hh::physics {
    class ResPhysicsMesh : public fnd::ManagedResource {
    public:
        struct Dimensions {
            enum class ShapeType : unsigned char {
                SPHERE,
                BOX,
                CAPSULE,
                CYLINDER,
                MESH = 7
            };

            struct Sphere {
                float radius;
            };

            struct Box {
                csl::math::Vector3 extents;
            };

            struct Capsule {
                csl::math::Vector3 size;
            };

            struct Cylinder {
                csl::math::Vector3 extents;
            };

            struct Mesh {
                csl::math::Vector3 a;
                csl::math::Vector3 b;
                csl::math::Vector3 c;
            };

            ShapeType shapeType;
            union {
                Sphere sphere;
                Box box;
                Capsule capsule;
                Cylinder cylinder;
                Mesh mesh;
            };
        };

        struct MeshInfo {
            struct Face {
                unsigned int a, b, c;
            };

            csl::ut::MoveArray<csl::math::Vector3> vertices;
            csl::ut::MoveArray<Face> faces;
            csl::fnd::IAllocator* allocator;

            inline MeshInfo(csl::fnd::IAllocator* allocator) : vertices{ allocator }, faces{ allocator }, allocator{ allocator } {}
            ~MeshInfo() {
                vertices.~MoveArray();
                faces.~MoveArray();
            }
        };

        virtual bool GetMeshInfo(csl::ut::MoveArray<MeshInfo*>& meshInfos, csl::fnd::IAllocator* allocator) = 0;
        virtual bool PM_UnkFunc1(int packedId, int64_t a3, int64_t a4) = 0;
        virtual bool PM_UnkFunc2(int a2, int a3, int64_t a4) = 0;
        virtual bool GetDimensionsAndWorldPosition(int packedId, Dimensions& dimensions, hh::fnd::WorldPosition* childPosition = nullptr) = 0;
        virtual int GetFaceType(int packedId) = 0;
        virtual int GetFaceType(unsigned int shapeIndex, unsigned int faceIndex) = 0;
        virtual int GetUnk(int packedId) = 0;
        virtual int GetUnk(unsigned int shapeIndex, unsigned int unused = 0) = 0;
        virtual bool IsConvex() const = 0;
        virtual bool IsConvex(int packedId) const = 0;
        virtual int64_t PM_UnkFunc10(int64_t a2) = 0;
        virtual int64_t PM_UnkFunc11(int64_t a2) = 0;
        virtual int64_t PM_UnkFunc12(int64_t a2) = 0;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicsMesh);
    };

    class ResPhysicsMeshBullet : public ResPhysicsMesh {
    public:
        csl::ut::InplaceMoveArray<btCompoundShape*, 1> compoundShapes;
        csl::ut::MoveArray<csl::ut::MoveArray<int>> faceTypes;
        csl::ut::PointerMap<btCollisionShape*, csl::ut::MoveArray<int>*> shapesFaceTypes;
        csl::ut::MoveArray<int64_t> unk3; // uses BtAllocator
        csl::ut::MoveArray<int64_t> unk4; // uses BtAllocator
        csl::ut::MoveArray<int64_t> unk5;
        csl::ut::MoveArray<int64_t> unk6;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        // packedId is first 12 bits index of the child, and the rest is an index idx
        virtual bool GetMeshInfo(csl::ut::MoveArray<MeshInfo*>& meshInfos, csl::fnd::IAllocator* allocator) override;
        virtual bool PM_UnkFunc1(int a2, int64_t a3, int64_t a4) override;
        virtual bool PM_UnkFunc2(int a2, int a3, int64_t a4) override;
        virtual bool GetDimensionsAndWorldPosition(int packedId, Dimensions& dimensions, hh::fnd::WorldPosition* childPosition = nullptr) override;
        virtual int GetFaceType(int packedId) override;
        virtual int GetFaceType(unsigned int shapeIndex, unsigned int faceIndex) override;
        virtual int GetUnk(int packedId) override;
        virtual int GetUnk(unsigned int shapeIndex, unsigned int unused = 0) override;
        virtual bool IsConvex() const override;
        virtual bool IsConvex(int packedId) const override;
        virtual int64_t PM_UnkFunc10(int64_t a2) override;
        virtual int64_t PM_UnkFunc11(int64_t a2) override;
        virtual int64_t PM_UnkFunc12(int64_t a2) override;
    
        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicsMeshBullet);
    };
}
