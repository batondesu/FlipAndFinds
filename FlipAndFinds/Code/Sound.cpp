#include "Sound.h"
#include "Sound.h"
bool bSound = 1;

bool Sound::state()
{
    return bSound;
}

void Sound::on()
{
    bSound = 1;
}

void Sound::off()
{
    bSound = 0;
}

void Sound::open(std::string path, int loops)
{

    if (!bSound) return;
    Mix_FadeOutChannel(-1, 0);
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    Mix_PlayChannel(-1, chunk, loops);

//    Mix_
}

/*void Sound::close() {

    Mix_PlayChannel(-1, chunk, loops);

}*/
