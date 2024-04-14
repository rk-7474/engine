#include <map>
#include <SDL2/SDL.h>
#include <string>

typedef struct {
    char* name;
    SDL_Texture* texture;
} state;

class Sprite {
    private:
        std::map<std::string, SDL_Texture*> states;
        state current_state;
    public:
        void addState(char* name, char* texture_path);
        void setState(char* name);
        state getState();
};
