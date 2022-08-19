#include "TwoDEngine/Engine/Engine.hpp"

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);
  Engine eng{"Test",768,768,false};

  eng.AddTexture("maptiles", "../Maps/TileSet.png");

  while(eng.isRunning(event)) {
    SDL_RenderClear(eng.GetRenderer());
    eng.DrawMap();
    SDL_RenderPresent(eng.GetRenderer());
  }

  SDL_Quit();

  return 0;
}