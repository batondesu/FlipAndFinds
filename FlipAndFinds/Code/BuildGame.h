#ifndef BUILDGAME_H
#define BUILDGAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

class BuildGame {

    public:

        BuildGame() {} ;

        bool isClient = 1;

        int startTime = 0;
        int curTime = 0;
        bool bTime = 0;
        bool isVictory = 0;

        bool Init() ;
        void Victory();
        bool PlayClient();
        bool TableGame();
        int PlayTable() ;
        void close();

        string ToString(int n , string x);
        SDL_Renderer* gRenderer = NULL ;
        static BuildGame* Instance()
            {
                if (instance == nullptr) instance = new BuildGame();
                return instance;
            }

    private:
        static BuildGame* instance;
        int Dem[100] ;
        vector<string> u , v;
        vector<pair<int , int>> g;

        SDL_Rect    POS , Toado ;
        SDL_Window*   gWindow_  = NULL ;

        SDL_Texture* gTexture = NULL;
        SDL_Texture* gObject = NULL;
        SDL_Texture* Object = NULL;
};

#endif
