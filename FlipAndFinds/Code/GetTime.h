#ifndef GETTIME_H
#define GETTIME_H

#include <SDL.h>

using namespace std;

class GetTime {
    public:
        GetTime() {} ;

        void scoreUp(SDL_Renderer* gR, SDL_Rect r, int n);
        void TimeUp(SDL_Renderer* gR, int n);
        string StrTime(int n);

    static GetTime* Instance()
        {
            if (instance == nullptr) instance = new GetTime();
            return instance;
        }

    private:
        static GetTime* instance;
        SDL_Renderer *gR = NULL;
};

#endif
