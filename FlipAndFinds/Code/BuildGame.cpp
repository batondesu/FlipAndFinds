#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <Event.h>
#include <bits/stdc++.h>
#include <BuildGame.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <RunningSDL.h>
#include "HighScore.h"
#include "Intro.h"
#include "Level.h"
#include "GetTime.h"
#include "TTF.h"
#include "Sound.h"

BuildGame* BuildGame::instance = nullptr;

using namespace std;

int Checker = 0;

bool BuildGame::Init()
{
    TTF_Init();

	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        success = false;
	else
	{
		gWindow_ = SDL_CreateWindow( "Flip And Finds", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow_ == NULL )
			success = false;
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow_, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
				success = false;
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
					success = false;
			}
		}
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	int x;
    ifstream inp( "HighScore.txt" );
    while( inp >>x ) {
        HighScore::Instance() -> scoreArr.push_back(x);
    }

	return success;
}

void BuildGame::close()
{
    ofstream out( "HighScore.txt" );
    for (auto x : HighScore::Instance() -> scoreArr ) {
        out <<x <<'\n';
    }

	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow_ );
	gWindow_ = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

string BuildGame::ToString(int n , string x) {
    string s;
    string s1 = "Image/";
    while( n ) {
        s = char( n % 10 + 48 ) + s;
        n /= 10;
    }

    return s1 + s + x;
}

bool BuildGame::TableGame() {

    Toado.x = 40;
    Toado.y = 40;
    Toado.h = 510;
    Toado.w = 510;

    u.clear();
    v.clear();
    g.clear();

    for (int i = 1 ; i <= 18 ; ++i) {
        string a = ToString( i , ".png" );
        v.push_back( a );
    }

    random_shuffle( v.begin() , v.end() );

    for (int i = 0 ; i < Level::Instance() -> getLevel() * Level::Instance() -> getLevel() / 2 ; ++i) {
        u.push_back( v[i] );
        u.push_back( v[i] );
    }

    int d = 4 - Level::Instance() -> getLevel() / 2;
    int x = 60*d ,
        y = 60*d ;

    Dem[0] = 0;
    for (int i = 1 ; i <= Level::Instance() -> getLevel() * Level::Instance() -> getLevel() ; ++i) {
        Dem[i] = 0;
        g.push_back( {x , y} );
        x += 80;
        if ( i % Level::Instance() -> getLevel() == 0 ) {
            y += 80;
            x = 60 * d;
        }
    }

    random_shuffle( u.begin() , u.end() );

return 1;
}

int dem = 0 ;
pair<int , int> I;

bool BuildGame::PlayClient() {
    if (!isClient) return 0;

    RunningSDL::Instance() -> draw( gRenderer , { 0 , 0 , 800 , 600 } , "Image/BgrCovid.jpg" );
    //SDL_RenderPresent( gRenderer );

    SDL_Rect r = {0, 0, WIDTH, HEIGHT};
    TIMER::Text( gRenderer , { 390 , 280 , 0, 0 } , "PLAY!" , "Font/12345678.ttf" , 50 , { 255 ,255,255,255 } );

    if (Event::Instance() -> GetEvent() == 0) {
        if (Event::Instance() -> clickInRect(r)) {
            isClient = 0;
            bTime = 0;
            Level::Instance() -> reset();
            TableGame();
            return 0;
        }
    }

    return 1;
}

void BuildGame::Victory() {

    RunningSDL::Instance() -> draw( gRenderer , { 0 , 0 , 800 , 600 } , "Image/BgrCovid.jpg" );
    SDL_Rect r = {0, 0, WIDTH, HEIGHT};
    TIMER::Text( gRenderer , r , "VICTORY!!" , "Font/12345678.ttf" , 100 , { 241 ,228,226,255 } );
    int top = HighScore::Instance() -> ranking( curTime );
    if ( top != 0 )  {
        string s = "New HighScore: ";
        s = s + GetTime::Instance() -> StrTime(curTime) + " Top ";
        s = s + char( top + 48 );
        TIMER::Text( gRenderer , { 400 , 550 , 0 , 0 } , s , "Font/12345678.ttf" , 30 , { 255, 255, 255, 255 } );
    }

    if (Event::Instance() -> GetEvent() == 0) {
        if (Event::Instance() -> clickInRect(r)) {
            isVictory = 0;
            isClient = 1;
            curTime = 0;
            Intro::Instance() -> reset();
            return;
        }
    }
}

int BuildGame::PlayTable() {

    if (PlayClient()) return -1;
    if (Intro::Instance() -> Show( gRenderer )) return -1;
    if (isVictory) {
        Victory();
        return -1;
    }

    if ( Checker == 0 ) {
        Sound::open( "source/game.mp3" , 10000 );
        Checker = 1;
    }

    if ( dem == 2 ) {
        if ( u[I.first] == u[I.second] ) {
            Dem[I.first]  = -1;
            Dem[I.second] = -1;
        }
        else {
            Dem[I.first]  = 0;
            Dem[I.second] = 0;
        }
        dem = 0;
        SDL_Delay(500);
    }

    int type = Event::Instance() -> GetEvent();
    if ( type == 0 ) {
        int kt = Event::Instance() -> GetRect(Level::Instance() -> getLevel());
        if ( kt != -1 ) {
            if (Dem[kt] == 0) {
                if ( dem == 0 ) I.first = kt;
                if ( dem == 1 && kt != I.first ) I.second = kt;
                Dem[kt] = 1;
                 ++dem;
            }
        }
    }

    if ( type == 1 ) return 1;

    RunningSDL::Instance()->draw( gRenderer , { 0 ,0 , 1000 , 750 } , "Image/back.jpg" );
    RunningSDL::Instance()->draw( gRenderer , { 40 , 40 , 510 , 510 } , "Image/back4.png" );

    for (int i = 0 ; i < Level::Instance() -> getLevel() * Level::Instance() -> getLevel() ; ++i) {

        int x = g[i].first ,
            y = g[i].second ;

        POS.x = x;
        POS.y = y;
        POS.w = 70;
        POS.h = 70;

        if ( Dem[i] != -1 ) {
            if ( Dem[i] == 1 ) {
                RunningSDL::Instance()->draw( gRenderer , POS , u[i] ) ;
            }
            else
                RunningSDL::Instance()->draw( gRenderer , POS , "Image/it1.png" );
        }
    }

    bool check = 1;
    for (int i = 0 ; i < Level::Instance() -> getLevel() * Level::Instance() -> getLevel() ; ++i)
        if (Dem[i] != -1) check = 0;

    if (bTime == 0) {
        bTime = 1;
        startTime = SDL_GetTicks();
    }

    RunningSDL::Instance() -> draw( gRenderer , { 580 , 40 , 200 , 510 } , "Image/back5.png" );
    TIMER::Text( gRenderer , { 680 , 80 , 0, 0 } , "TIME:" , "Font/12345678.ttf" , 50 , { 255,255,0,255 } );
    TIMER::Text( gRenderer , { 680 , 240 , 0, 0 } , "HighScore:" , "Font/12345678.ttf" , 30 , { 255,255,0,255 } );
    curTime = int(SDL_GetTicks() - startTime) / 1000;
    GetTime::Instance() -> TimeUp(gRenderer, curTime);

    HighScore::Instance() -> showScore(gRenderer);

    if (check) {
        if (Level::Instance() -> getLevel() == 2) {
            Sound::open( "source/win.mp3" , 0);
            HighScore::Instance() -> addScore(curTime);
            isVictory = 1;
            return -1;
        }

        Level::Instance() -> inc();
        TableGame();
    }

return -1;
}
