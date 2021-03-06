#include "RunningSDL.h"

RunningSDL* RunningSDL::instance = nullptr;

bool RunningSDL::load(SDL_Renderer *renderer, std::string path)
{
  if (textureMap.find(path) != textureMap.end()) return true;

  SDL_Surface *surface = IMG_Load(path.c_str());

  if (surface == nullptr)
  {
    return false;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  if (texture == nullptr)
  {
    return false;
  }
  else
  {
    textureMap[path] = texture;
    return true;
  }
}

void RunningSDL::draw(SDL_Renderer *renderer, SDL_Rect r, std::string path)
{
  if (load(renderer, path))
  {
    SDL_RenderCopy(renderer, textureMap[path], NULL, &r);
  }
}

void RunningSDL::clearTexture(std::string path)
{
  SDL_DestroyTexture(textureMap[path]);
  textureMap.erase(path);
}
void RunningSDL::clearAllTexture()
{
  while (!textureMap.empty())
  {
    SDL_DestroyTexture(textureMap.begin() -> second);
    textureMap.erase(textureMap.begin());
  }
}
