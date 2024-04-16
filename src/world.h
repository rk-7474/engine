#include <map>
#include "types.h"
#include <SDL2/SDL_image.h>

class World {
    private: 
        inline static std::map<int, std::map<int, char>> tiles = {};
        inline static std::map<char, SDL_Texture*> textures = {};
    public: 
        static void render();
        static void update();
        static void load(int x, int y, char id);
        static void unload(int x, int y);
        static void registerTile(char* texture, char id);
        static void reload();
        static iCoords getCurrent();
        static iCoords getPlayerChunkPosition();
        static SDL_Texture* getTexture(char id);
        static void create(int x, int y);
        static void loadFromMemory(int x, int y);
};
