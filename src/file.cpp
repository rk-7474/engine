#include "file.h"
#include "world.h"
#include "texture.h"
#include "config.h"
#include <string>
#include <fstream>
#include <SDL2/SDL_image.h>

namespace File {
    int read(std::string fileName, std::vector<std::string> &lines) {
        std::ifstream file( fileName );
        
        if (!file.is_open()) {
            return 1;
        }

        std::string line;

        while (std::getline(file, line)) {
            lines.push_back(line.data());
        }

        file.close();
        return 0;
    }
}

void loadTiles() {
    using namespace std;

    vector<string> tiles;
    string fileName = "resources/tiles.data";
    if (File::read(fileName, tiles) == 1) return;

    char c = 1;
    for (std::string line : tiles) {
        printf("Loading tile %s\n", line.data());
        World::registerTile(line.data(), c++);
    }
    TILES_NUMBER = c - 1;

}   

void loadDecors(std::vector<SDL_Texture*>& textures) {
    using namespace std;

    vector<string> decors;
    string fileName = "resources/decors.data";
    if (File::read(fileName, decors) == 1) return;

    for (std::string line : decors) {
        printf("Loading decor %s\n", line.data());
        textures.push_back(loadTexture(line.data()));
    }
}   