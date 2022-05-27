#include "Event.h"
#include "SDL.h"
#include<iostream>
#include <bits/stdc++.h>
#include <Table.h>

using namespace std;

Event* Event::instance = nullptr;

int Event::GetEvent() {

    SDL_PollEvent( &Eve );

    if ( Eve.type == SDL_QUIT ) return 1;
    if ( Eve.type == SDL_MOUSEBUTTONDOWN ) return 0;

return -1;
}

int Event::GetRect(int lv) {

    int d = 4 - lv/2;

    int x = Eve.button.x ,
        y = Eve.button.y ;

    if ( x < 60 * d || y < 60*d || x > 60*d + 80*lv || y > 60*d + 80*lv ) return -1;

    int kt = 0;
    int u , v;

    x -= 60*d;
    u = x/80 + 1 - (x % 80 == 0);
    y -= 60*d;
    v = y/80 + 1 - (y % 80 == 0);

    if ( x < u * 80 && u <= lv ) kt += u;
    if ( y < v * 80 && v <= lv ) kt += (v - 1) * lv;

return kt - 1;
}

bool Event::clickInRect(const SDL_Rect& r) {
    int x = Eve.button.x ,
        y = Eve.button.y ;
    return x >= r.x && y >= r.y && x <= r.x + r.w && y <= r.y + r.h;
}

