#include "TTF.h"
#include "iostream"
#include "GetTime.h"
#include "BuildGame.h"
#include "SDL.h"

using namespace std;

GetTime* GetTime::instance = nullptr;

string GetTime::StrTime(int n) {
    string mm , ss;
    string kq;

    mm = char(n / 60 + 48);
    mm = "0" + mm;

    n %= 60;
    ss = char(n % 10 + 48);
    if ( n > 9 )
        ss = char(n / 10 + 48) + ss;
    else
        ss = "0" + ss;

    kq = mm + ":" + ss;
return kq;
}

void GetTime::TimeUp(SDL_Renderer* gR, int n) {

    TIMER::Text( gR , { 680 , 150 , 0, 0 } , StrTime(n) , "vndi02.ttf" , 50 , { 255,255,0,255 } );

return;
}

void GetTime::scoreUp(SDL_Renderer* gR, SDL_Rect r, int n) {

    TIMER::Text( gR , r , StrTime(n) , "vndi02.ttf" , 30 , { 255,255,0,255 } );

return;
}
