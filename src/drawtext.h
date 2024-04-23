#include <SDL2/SDL_ttf.h>
#include "types.h"

class Text {
    static inline TTF_Font* Sans = NULL;

    static inline SDL_Color White = {255, 255, 255};

    public:
        static void Init();
        static void Draw(char* text, int size, iCoords pos);
};