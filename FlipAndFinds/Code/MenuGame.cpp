#include "MenuGame.h"
#include "Event.h"
#include "BuildGame.h"
#include "TTF.h"
#include "RunningSDL.h"
#include <bits/stdc++.h>

BuildGame BG;
Event E;
RunningSDL RunMG;

void MenuGame::HighScore() {

}

void MenuGame::Settings() {
   /* RunMG.gTexture = RunMG.loadMedia(RunMG.gTexture, "settings" , "png" );
    SDL_RenderCopy( RunMG.gRenderer , RunMG.gTexture , NULL , NULL );
    RunMG.gTexture = RunMG.loadMedia(RunMG.gTexture, "ovuong" , "png" );

    rect.x = 500;
    rect.y = 350;
    rect.w = 10;
    rect.h = 10;

    int y = 350;
    for (int i = 0 ; i < 5 ; ++i) {
        y += i * 50;
        rect.y = y;
        SDL_RenderCopy( RunMG.gRenderer , RunMG.gTexture , NULL , &rect );
    }

    RunMG.gTexture = RunMG.loadMedia( RunMG.gTexture , "tickxanh" , "png" );

    if ( !E.GetEvent() ) {
        int x = E.Eve.button.x ,
            y = E.Eve.button.y ;


        if ( 500 <= x && x <= 510 )
        for (int j = 0 ; j < 5 ; ++j) {
            if ( 350 + j*50 <= y && y <= 360 * j*50 ) {
                rect.y = 350 + j*50;
                SDL_RenderCopy( RunMG.gRenderer , RunMG.gTexture , NULL , &rect );
            }
        }
    }

    SDL_RenderPresent( RunMG.gRenderer );*/

}

void MenuGame::Running() {

   /* //if ( RunMG.gTexture == NULL ) cout <<0 <<'\n';

    RunMG.gTexture = RunMG.loadMedia(RunMG.gTexture ,  "BgrCovid" , "jpg" );
    SDL_RenderCopy( RunMG.gRenderer , RunMG.gTexture , NULL , NULL );

    //if ( RunMG.gTexture == NULL ) cout <<0 <<'\n';

    SDL_RenderPresent( RunMG.gRenderer );
    //SDL_RenderClear( RunMG.gRenderer );

    int mode;

    if ( ! E.GetEvent() )
        mode = E.RectMenu();

    if ( mode == 1 ) Checked = 0;
    if ( mode == 3 ) Settings();


    SDL_RenderClear( RunMG.gRenderer );*/
}
