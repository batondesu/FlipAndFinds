#include "Intro.h"
#include <SDL.h>
#include "RunningSDL.h"
#include "TTF.h"
#include "Sound.h"

Intro* Intro::instance = nullptr;

void Intro::reset() {
    cur = 0;
}

bool Intro::Show( SDL_Renderer *gRenderer ) {

    SDL_Rect rect = {0 , 0 , 800 , 600 };
    SDL_SetRenderDrawColor( gRenderer, 3 , 11 , 32 , 255 );
    SDL_RenderFillRect( gRenderer, &rect );

    cur++;

    if (cur == 1) {
        Sound::open( "source/Intro.mp3" , 0 );
        RunningSDL::Instance() -> draw( gRenderer , { 200 , 150 , 400 , 300 } , "Image/three.png" );
    }
    else
    if (cur == 2) {
        RunningSDL::Instance() -> draw( gRenderer , { 200 , 150 , 400 , 300 } , "Image/two.png" );
    }
    else
    if (cur == 3) {
        RunningSDL::Instance() -> draw( gRenderer , { 200 , 150 , 400 , 300 } , "Image/one.png" );
    }
    else
    if (cur == 4) {
        SDL_Rect rect = {0 , 0 , 800 , 600 };
        SDL_SetRenderDrawColor( gRenderer, 3 , 11 , 32 , 255 );
        SDL_RenderFillRect( gRenderer, &rect );

        TIMER::Text( gRenderer , { 400 , 250 , 0, 0 } , "Let's Go !!" , "TimesNewRoman.ttf" , 100 , { 241 ,228,226,255 } );

    }
    else {
        return 0;
    }

    SDL_RenderPresent( gRenderer );


    SDL_Delay(1000);
    SDL_RenderClear( gRenderer );

    return 1;
}
