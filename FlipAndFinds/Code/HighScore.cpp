#include "HighScore.h"
#include "GetTime.h"
#include <algorithm>

HighScore* HighScore::instance = nullptr;

void HighScore::showScore(SDL_Renderer *gR) {
    if (scoreArr.size() > 0) GetTime::Instance() -> scoreUp(gR, { 680 , 300 , 0, 0 } , scoreArr[0]);
    if (scoreArr.size() > 1) GetTime::Instance() -> scoreUp(gR, { 680 , 350 , 0, 0 }, scoreArr[1]);
    if (scoreArr.size() > 2) GetTime::Instance() -> scoreUp(gR, { 680 , 400 , 0, 0 }, scoreArr[2]);
}

int HighScore::ranking(int score) {
    int cur = 0;
    for (auto i : scoreArr) {
        cur++;
        if (i == score) return cur;
    }
    return 0;
}

void HighScore::addScore(int score) {
    scoreArr.push_back(score);
    std::sort(scoreArr.begin(), scoreArr.end());
    if (scoreArr.size() > 3) scoreArr.pop_back();
}
