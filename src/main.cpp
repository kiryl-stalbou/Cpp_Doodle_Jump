#define SDL_MAIN_HANDLED

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "RSDL/rsdl.hpp"
#include "consts.hpp"
#include "system.hpp"

// clang++ -v -std=c++11 main.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_mixer -framework SDL2_image -framework SDL2_ttf

// g++ -Wall -pedantic -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_mixer -framework SDL2_image -framework SDL2_ttf build/obj/scenes/gameover_scene.o build/obj/scenes/scene.o build/obj/scenes/menu_scene.o build/obj/scenes/pause_scene.o build/obj/scenes/game_scene.o build/obj/platforms/platform_normal.o build/obj/platforms/platform_breakable.o build/obj/platforms/platform_movable.o build/obj/spritesheet.o build/obj/button.o build/obj/sequence_manager.o build/obj/utils/calc.o build/obj/menu_ufo.o build/obj/game_object.o build/obj/system.o build/obj/items/spring.o build/obj/main.o build/obj/input_manager.o build/obj/RSDL/rsdl.o build/obj/enemies/enemy_normal.o build/obj/doodle.o -o build/bin/doodle_jump.exe -rpath /Library/Frameworks

void gameLoop(Window* win) {
    System system(win);

    unsigned currTime = SDL_GetTicks();
    unsigned prevTime = currTime;
    unsigned lag = 0;

    bool canUpdate = true;
    while (canUpdate) {
        prevTime = SDL_GetTicks();
        lag += currTime - prevTime;

        // while (canUpdate && lag >= consts::MS_PER_UPDATE) {
        //     lag -= consts::MS_PER_UPDATE;
        // }

        canUpdate = system.update();
        win->clear();
        system.draw();
        win->update_screen();

        currTime = SDL_GetTicks();

        delay(consts::MS_PER_UPDATE - (currTime - prevTime));
    }
}

int main() {
    Window win(consts::WIN_WIDTH, consts::WIN_HEIGHT, consts::WIN_NAME);

    win.set_icon(consts::ICON);

    gameLoop(&win);
}
