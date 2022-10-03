#include "TwoDEngine/Engine/Engine.hpp"

#include <iostream>
#include <random>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Player::Player(const std::pair<int,int>& SrcPos, const int imgsize, const int rescalefactorX,
               const int rescalefactorY, TextureWrapper *Texture, const Vector2D<int>& Position) :
  _SpriteComponent{new SpriteComponent(
    SrcPos, imgsize, rescalefactorX, rescalefactorY, Texture, Position
  )},
  _InputComponent{new InputComponent{_SpriteComponent->GetTransformComponent()}}
{

}

bool Player::SetTexture(SDL_Renderer * Renderer)
{
  _SpriteComponent->SetTexture(new TextureWrapper{Renderer, "../Maps/car1.png"});
  return true;
}

Engine::Engine(const std::string& title, const int width, const int height, const bool fullscreen)
: _WindowWidth{width}, _WindowHeight{height},
  _Window{SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,(fullscreen? SDL_WINDOW_FULLSCREEN : 0))},
  _Renderer{SDL_CreateRenderer(_Window,-1,SDL_RENDERER_ACCELERATED)},
  _map{_Renderer,"../Maps/TileSet.png"}
{
  _map.LoadMap(_Window);
  const int RescaleFactorX = _WindowWidth/256;
  const int RescaleFactorY = _WindowHeight/256;
  for(int w {0}; w < _WindowWidth; w+=5*RescaleFactorX ){
    for(int h {0}; h < _WindowHeight; h+=5*RescaleFactorY) {
      _Points.push_back({w,h});
    }
  }
  std::mt19937 g{std::random_device{}()};
  std::uniform_int_distribution<size_t> d{0,_Points.size()};
  std::cout << _Points[d(g)] << std::endl;
  const Vector2D<int> InitPlayerPos {_Points[d(g)].x-16/2,
                                     _Points[d(g)].y+16/2};

  _Player = std::make_unique<Player>(std::make_pair<int,int>(0,0), 8, 2, 2, nullptr,
                                     InitPlayerPos);
  _Player->SetTexture(_Renderer);
}

Engine::~Engine()
{
  SDL_DestroyRenderer(_Renderer);
  SDL_DestroyWindow(_Window);
}

void Engine::DrawLines()
{
  /**
   * I need to draw a line each 5 pixels in height and width
   * Draw vertical lines first and then horizontal lines
   */

  int w = 0;
  int h = 0;
  SDL_SetRenderDrawColor(_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  while(w < _WindowWidth and h < _WindowHeight){
    SDL_RenderDrawLine(_Renderer, w, 0, w, _WindowHeight);
    SDL_RenderDrawLine(_Renderer, 0, h,_WindowWidth, h);
    w += 5 * 3;
    h += 5 * 3;
  }
}

bool Engine::isRunning(SDL_Event& event)
{
  /// To make it continuous SDL_PollEvent
  SDL_WaitEvent(&event);
  _Player->Update(&event);
  if(event.type == SDL_QUIT) return false;

  SDL_RenderClear(_Renderer);
  _map.DrawMap();
  DrawLines();
  SDL_SetRenderDrawColor(_Renderer, 255,255,255,SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRect(_Renderer, _Player->GetSpriteComponent()->GetDestRect());
  _Player->Draw();
  SDL_RenderPresent(_Renderer);

  _Player->GetSpriteComponent()->GetTransformComponent()->ResetVelocity();

  return true;
}