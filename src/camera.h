#pragma once

#include "types.h"
#include "config.h"

class Camera {  
    private:
        static inline fCoords absolute;
        static inline fCoords offset = {
            (float) -SCREEN_WIDTH/2, 
            (float) -SCREEN_HEIGHT/2
        };

    public:
        static void move(int x, int y);
        static fCoords getPosition();
        static void setPosition(fCoords coords);
};