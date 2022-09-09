#include "TwoDEngine/Engine/Engine.hpp"

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);
  Engine eng{"Test",768,768,false};

  while(eng.isRunning(event)) { }

  SDL_Quit();

  return 0;
}