#pragma once

namespace SurfRide {
    class CastExtension : public Extension {
    public:
        virtual void AddCallback(Cast* cast) = 0;
        virtual void RemoveCallback(Cast* cast) = 0; // guessed
    };
}
