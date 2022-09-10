#include "TwoDEngine/Engine/Engine.hpp"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Player::Player(const std::pair<int,int>& SrcPos, const int imgsize, const int rescalefactorX,
               const int rescalefactorY, TextureWrapper *Texture, const Vector2D& Position) :
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
: _Window{SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,(fullscreen? SDL_WINDOW_FULLSCREEN : 0))}, _Renderer{SDL_CreateRenderer(_Window,-1,0)},
  _map{_Renderer,"../Maps/TileSet.png"}
{
  _Player = std::make_unique<Player>(std::make_pair<int,int>(0,0), 8, 2, 2, nullptr,
                                     Vector2D{100,100});
  _Player->SetTexture(_Renderer);
  _map.LoadMap(_Window);
}

Engine::~Engine()
{
  SDL_DestroyRenderer(_Renderer);
  SDL_DestroyWindow(_Window);
}

bool Engine::isRunning(SDL_Event& event)
{
  /// To make it continuous SDL_PollEvent
  SDL_WaitEvent(&event);
  _Player->Update(&event);
  if(event.type == SDL_QUIT) return false;

  SDL_RenderClear(_Renderer);
  _map.DrawMap();
  _Player->Draw();
  SDL_RenderPresent(_Renderer);

  return true;
}
