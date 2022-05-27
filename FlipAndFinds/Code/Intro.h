#ifndef INTRO_H
#define INTRO_H
#include "SDL.h"


class Intro
{
    public:
    Intro() {};

    int cur = 0;
    bool Show( SDL_Renderer *gRenderer );
    void reset();

    static Intro* Instance()
        {
            if (instance == nullptr) instance = new Intro();
            return instance;
        }

    protected:

    private:
        static Intro* instance;
};


#endif // INTRO_H
