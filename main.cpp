#include <iostream>
#include<SDL.h>

using namespace std;

int main(int argc, char *argv[]){
    
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    SDL_Window *window;
    Uint32 flags = SDL_WINDOW_OPENGL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "SDL could not initialise! SDL Error: " << SDL_GetError;
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        SCREEN_WIDTH,                      // width, in pixels
        SCREEN_HEIGHT,                     // height, in pixels
        flags                 // flags - see below
    );

    // Check if window was created
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
    }

    // Game loop
    bool quit = false;
    SDL_Event event;

    while(!quit){
        // Update particles
        // Draw particles
        // Check for messages/event

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
                }
        }
    }
    
    //SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}