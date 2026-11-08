#pragma once

namespace hh::dv{
    class DvNodeCamera;

    class DvSceneNodeTree : public fnd::ReferencedObject{
    public:
        DvNodeBase* mainNode;
        DvParamUpdater* paramUpdater;
        DvSceneControl* parent;
        int diEventManagerDWORDC0;

        void FindNodesByType(DvNodeBase::NodeType type, csl::ut::MoveArray<DvNodeBase*>* result);
        void GetChildren(DvNodeBase::NodeType type, DvNodeBase* parent, csl::ut::MoveArray<DvNodeBase*>* result);
        DvNodeBase* FindNodeByGUID(char* guid, DvNodeBase* startNode);
        DvNodeBase* FindNodeByGUID(char* guid);
        DvNodeBase* GetMainNode() const;
        DvNodeCamera* GetMainCameraNode() const;
        bool GetViewportDataByFrame(int currentFrame, hh::gfnd::ViewportData* returnValue);
        void InitializeClasses();
        void InitializeMainNode();
        void Update(int currentFrame);
        void PostUpdate(int currentFrame);

        DvSceneNodeTree(csl::fnd::IAllocator* allocator, DvSceneControl* dvSceneControl, int diEvtMgrUnk);
    };
}
