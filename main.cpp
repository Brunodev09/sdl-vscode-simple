#include <iostream>
#include<SDL.h>

using namespace std;

int main(int argc, char *argv[]){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "SDL could not initialise! SDL Error: " << SDL_GetError;
    }
    cout << "Print something" << endl;
    system("pause");
    return EXIT_SUCCESS;
}