#include "TwoDEngine/Engine/Engine.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Engine::Engine(const std::string& title, const int width, const int height, const bool fullscreen)
: _Window{SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,(fullscreen? SDL_WINDOW_FULLSCREEN : 0))}
{
  _Renderer = SDL_CreateRenderer(_Window,-1,0);
  if (_Renderer){
		SDL_SetRenderDrawColor(_Renderer, 255, 255, 255, 255);
	}
}

Engine::~Engine()
{
  for(auto& t: _Textures) {
    SDL_DestroyTexture(t.second);
  }
  SDL_DestroyRenderer(_Renderer);
  SDL_DestroyWindow(_Window);
}

bool Engine::isRunning(SDL_Event& event) const
{
  SDL_WaitEvent(&event);
  if(event.type == SDL_QUIT) return false;
  return true;
}

void Engine::AddTexture(const std::string& id, const std::string& path)
{
  if(_Textures.find(id) == _Textures.end()) {
    _Textures.emplace(id, IMG_LoadTexture(_Renderer,path.data()));
  }
}

void Engine::DrawMap()
{
  std::ifstream map {"/Users/Nappo/games/machineracing/Maps/map.map", std::ios::in};
  int WindowHeight = 0, WindowWidth = 0;
  SDL_GetWindowSize(_Window, &WindowHeight, &WindowWidth);
  const int RescaleFactorY = WindowHeight/256;
  const int RescaleFactorX = WindowWidth/256;
  const int TileSetSize = 32;
  const int ImgSize = 8;

  SDL_Rect srcRect  {0,0,ImgSize,ImgSize};
  SDL_Rect destRect {0,0,ImgSize*RescaleFactorX,ImgSize*RescaleFactorY};

  for (int j{0}; j < TileSetSize; ++j) {
    for (int i{0}; i < TileSetSize; ++i) {
      char c;
      map.get(c);
      if (c == '1') { // Grass, 0-offset
        srcRect.x = srcRect.y = 0;
      }
      else if (c == '2') { // Curb, 2-offset
        srcRect.x = ImgSize * 2;
        srcRect.y = 0;
      }
      else if (c == '3') { // Tarmac
        srcRect.x = ImgSize;
        srcRect.y = 0;
      }
      // dest pixel is i*8*RescaleFactor,j*8*RescaleFactor
      destRect.x = i * ImgSize * RescaleFactorX;
      destRect.y = j * ImgSize * RescaleFactorY;

      std::cout << destRect.x <<" "<< destRect.y  << std::endl;
      std::cout << destRect.w <<" "<< destRect.h  << std::endl;
      SDL_RenderCopy(_Renderer, _Textures["maptiles"], &srcRect, &destRect);
      map.ignore();
    }
  }
  map.close();
}
