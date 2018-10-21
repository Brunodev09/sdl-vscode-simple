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

    // --------------- SETUP SDL
    // 01 Create Window
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

    // 02 Create Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_PRESENTVSYNC);
    // 03 Create Texture
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Create a buffer for the image
    Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    
    // Set colors
    memset(buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)); // fills the BG
    for(int i=0; i<SCREEN_HEIGHT*SCREEN_WIDTH;i++){
        buffer[i] = 0x2B84ABFF;
    }
    
    // Update the texture
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    // Clear the renderer
    SDL_RenderClear(renderer);
    // Copy the texture into the renderer and present it to screen
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // --------------- GAME LOOP
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
    
    // --------------- DESTROYERS
    // Deconstructors
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}