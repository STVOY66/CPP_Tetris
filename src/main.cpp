/*** include ***/
#include <iostream>
#include <SDL2/SDL.h>

/*** define ****/

/*** prototypes ***/
int initialize(); //function to initialize SDL and other elements of the program
int input(SDL_Event&); // input handler
void render(); //render handler
int egress(); // cleans up and exits the program

/*** global variables ***/
SDL_Window *window;
const int WIDTH = 800;
const int HEIGHT = 600;

/*** main ***/
int main( int argc, char *argv[] )
{
    if(!initialize())
    {
        std::cout << "Function call to \'initialize()\' failed\n\n";
        return egress();
    }

    SDL_Event windowEvent;

    std::cout << "Program running...\n\n";

    while (input(windowEvent)) // main game loop, function 'input()' returns a '0' when the user wishes to exit the program.
    {
        render();
    }

    return egress();
}

int initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING); // initialize SDL

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI); // creates the window

    if ( NULL == window ) // if the windows fails to be created
    {
        return 0;
    }

    std::cout << "Initializing program...\n\n";

    return 1;
}

int input(SDL_Event& windowEvent)
{
    if ( SDL_PollEvent( &windowEvent ) )
    {
        if (SDL_QUIT == windowEvent.type) { return 0; } // breaks the while loop when the window is closed
    }

    return 1;
}

void render()
{

}

int egress()
{
    SDL_DestroyWindow( window );
    SDL_Quit();

    std::cout << "Exiting program...\n";

    return 0;
}