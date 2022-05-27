#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SDL.h>
#include <iostream>
#include <vector>

class HighScore
{
    public:

    HighScore() {};

    std::vector < int > scoreArr;

    void showScore(SDL_Renderer *gR);
    void addScore(int score);
    int ranking(int score);

    static HighScore* Instance()
        {
            if (instance == nullptr) instance = new HighScore();
            return instance;
        }

    protected:

    private:
        static HighScore* instance;
};

#endif // HIGHSCORE_H
