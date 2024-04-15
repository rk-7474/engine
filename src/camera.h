#pragma once

#include "types.h"

class Camera {  
    private:
        static inline fCoords absolute;
    public:
        static void move(int x, int y);
        static fCoords getPosition();
        static void setPosition(fCoords coords);
};