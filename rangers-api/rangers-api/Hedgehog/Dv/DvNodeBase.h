#pragma once

namespace hh::dv{
    class DvSceneControl;
    class DvSceneNodeTree;

    class DvNodeBase : public hh::fnd::ReferencedObject{
    public:
        struct Description {};

        enum class NodeType : uint32_t{
            PATH = 1,
            PATH_MOTION,
            CAMERA,
            CAMERA_MOTION,
            CHARACTER,
            CHARACTER_MOTION,
            CHARACTER_BEHAVIOR,
            MODEL,
            MODEL_MOTION = 10,
            MODEL_NODE,
            ELEMENT,
            STAGE = 13
        };

        enum class Flags : uint32_t {
            INITIALIZED = 29
        };

        uint32_t flags; //prolly a bitset
        NodeType nodeType;
        char guid[16];
        char parentGuid[16];
        csl::ut::String nodeName;
        csl::math::Transform transform;
        csl::math::Matrix44 matrix;
        hh::fnd::Reference<DvResource> dvResource;
        hh::fnd::Reference<DvNodeBase> parent;
        csl::ut::MoveArray<DvNodeBase*> childrenElements0;
        csl::ut::MoveArray<DvNodeBase*> childrenPath;
        csl::ut::MoveArray<DvNodeBase*> childrenCamera;
        csl::ut::MoveArray<DvNodeBase*> childrenMotion;
        csl::ut::MoveArray<DvNodeBase*> childrenElements1;
        csl::ut::MoveArray<DvNodeBase*> childrenElements2;
        DvSceneNodeTree* dvsceneNodeTree;

        virtual void Setup(Description& description);
        virtual void Start();
        virtual void Update(int currentFrame) {};
        virtual void PreStepUpdate(int currentFrame) {};
        virtual void PostStepUpdate(int currentFrame) {};
        virtual bool IsInitialized();
        virtual bool UnkFunc3() { return true; }
        virtual void UnkFunc4() {};
        virtual int GetUpdateTiming();
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) {};

        char* GetGUID() const;
        csl::math::Transform& GetTransform() const;
        void SetTransform(csl::math::Transform& transform);
        void SetTransformRecursively(csl::math::Transform& transform);
        void PreStepUpdateRecursively(unsigned int unk0);
        void SetInitializedFlag(bool enabled);
        DvNodeBase* GetParent() const;
        unsigned long long GetChildrenAmount() const;
        DvNodeBase* GetElement0ByIdx(unsigned long long idx) const;
        void UpdateChildren(int arrayIdx, int currentFrame);
        void PostStepUpdateRecursively(int currentFrame);
        DvSceneControl* GetDvSceneControl() const;
        void GetNodes(NodeType type, csl::ut::MoveArray<DvNodeBase*>& retValue);

        DvNodeBase(csl::fnd::IAllocator* allocator);
    };
}
