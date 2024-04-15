#include <vector>
#include "chunk.h"

class World {
    private: 
        static std::vector<Chunk*> loaded;
        inline static std::vector<Chunk*> rendered = {};

        inline static std::vector<SDL_Texture*> tiles_textures = {};

    public: 
        static void render();
        static void update();
        static void load(Chunk* chunk);
        static void unload(int id);
        static SDL_Texture* getTexture(int id);
        static void registerTile(char* texture);
        static void reload();
        static Chunk* getCurrent();
        static iCoords getPlayerChunkPosition();
        static void create(int x, int y);
        static void loadFromMemory(int x, int y);
};
