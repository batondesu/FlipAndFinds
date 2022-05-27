#ifndef MENUGAME_H
#define MENUGAME_H
 #include <SDL.h>

class MenuGame
{
    public:
        MenuGame() {};

        int Checked = 1;

        SDL_Texture *m_texture = NULL;
        SDL_Renderer *m_renderer = NULL;

        SDL_Rect rect;

        void Running();

        void HighScore();

        void Settings();

};

#endif // MENUGAME_H
