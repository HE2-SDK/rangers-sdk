#pragma once

namespace hh::path {
    class PathGeometry : public hh::fnd::ReferencedObject {
    public:
        char unk0;
        csl::ut::MoveArray<int64_t> unk2;
        csl::ut::MoveArray<int64_t> unk3;

        PathGeometry(csl::fnd::IAllocator* allocator);
    };

    class ResUserDataData {};

    class ResPathObject : public hh::fnd::ReferencedObject {
    public:
        void EvaluateResult(float distance, csl::math::Vector3* position, csl::math::Vector3* normal, csl::math::Vector3* tangent, int* key) const;
        void EvaluateResult2(float distance, csl::math::Vector3* position, csl::math::Vector3* normal, csl::math::Vector3* tangent, int* key) const;
        float NormalizeDistance(float distance) const;
    };

    int GetKeyAtDistance(const ResPathObject& pathObject, float distance, int* key);
    int GetKeyAtDistanceCore(const ResPathObject& pathObject, float distance, int* key);
    csl::math::Vector3 InterpolatePosition(float distance, int key, float* maybeDistances, csl::math::Vector3* positions);
    ResPathObject* Convert(const char* name, const PathGeometry& pathGeom, const csl::ut::MoveArray<ResUserDataData>* userDataArray, csl::fnd::IAllocator* allocator, bool unk0);
}
