#include "TwoDEngine/Engine/Engine.hpp"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Engine::Engine(const std::string& title, const int width, const int height, const bool fullscreen)
: _Window{SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,(fullscreen? SDL_WINDOW_FULLSCREEN : 0))}, _Renderer{SDL_CreateRenderer(_Window,-1,0)},
  _map{_Renderer,"../Maps/TileSet.png"}
{
  _map.LoadMap(_Window);
}

Engine::~Engine()
{
  SDL_DestroyRenderer(_Renderer);
  SDL_DestroyWindow(_Window);
}

bool Engine::isRunning(SDL_Event& event)
{
  SDL_WaitEvent(&event);
  if(event.type == SDL_QUIT) return false;

  SDL_RenderClear(_Renderer);
  _map.DrawMap();
  SDL_RenderPresent(_Renderer);

  return true;
}
