#ifndef RUNNINGSDL_H
#define RUNNINGSDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <map>

class RunningSDL {
public:
  bool load(SDL_Renderer *renderer, std::string path);
  void draw(SDL_Renderer *renderer, SDL_Rect r, std::string path);
  void clearTexture(std::string path);
  void clearAllTexture();

  RunningSDL() {};
  static RunningSDL* Instance()
	{
		if (instance == nullptr) instance = new RunningSDL();
		return instance;
	}

private:
  static RunningSDL* instance;
  std::map<std::string, SDL_Texture*> textureMap;
};

#endif // TEXTUREMANAGER_H
