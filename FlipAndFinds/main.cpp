#include <SDL.h>
#include <Event.h>
#include <iostream>
#include <BuildGame.h>
#include <MenuGame.h>
#include <RunningSDL.h>
#include <GetTime.h>

using namespace std;

const int FPS = 20;
const int DelayTime = 1000/FPS;

int quit = 0;

int main( int argc, char* args[] )
{
    Uint32 beginTime, frameStart , frameTime , Start;

    if ( BuildGame::Instance() -> Init() ) {

        BuildGame::Instance() -> TableGame();
        while(1) {

            frameStart = SDL_GetTicks();

            if (BuildGame::Instance() -> PlayTable() == 1) break;

            frameTime = SDL_GetTicks() - frameStart;

            if ( frameTime < DelayTime )
                SDL_Delay((int)(DelayTime - frameTime));

            SDL_RenderPresent( BuildGame::Instance() -> gRenderer );
            SDL_RenderClear( BuildGame::Instance() -> gRenderer );

        }
    }


    RunningSDL::Instance() -> clearAllTexture();
    BuildGame::Instance() -> close();

return 0;
}
