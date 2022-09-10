#include "TwoDEngine/Components/SpriteComponent.hpp"

#include <SDL2/SDL_image.h>

SpriteComponent::SpriteComponent(const std::pair<int,int>& SrcPos,const int imgsize,
                                 const int rescalefactorX, const int rescalefactorY,
                                 TextureWrapper * Texture, const Vector2D& Position) :
  _ImgSize{imgsize}, _RescaleFactorX{rescalefactorX},
  _RescaleFactorY{rescalefactorY}, _Texture{Texture},
  _TransformComponent{new TransformComponent{Position}}
{
  _SrcRect = SDL_Rect{SrcPos.first,SrcPos.second,imgsize,imgsize};
  _DstRect = SDL_Rect{static_cast<int>(Position.x),
                      static_cast<int>(Position.y),
                      imgsize * rescalefactorX, imgsize * rescalefactorY};
}

SpriteComponent::SpriteComponent(SpriteComponent&& sc) :
  _ImgSize{sc._ImgSize}, _RescaleFactorX{sc._RescaleFactorX},
  _RescaleFactorY{sc._RescaleFactorY}, _Texture{sc._Texture},
  _TransformComponent{std::move(sc._TransformComponent)},
  _SrcRect{sc._SrcRect}, _DstRect{sc._DstRect} {}

bool SpriteComponent::Init()
{
  return true;
}

bool SpriteComponent::Update()
{
  bool res = _TransformComponent->Update();
  _DstRect.x = static_cast<int>(_TransformComponent->GetPosition().x);
  _DstRect.y = static_cast<int>(_TransformComponent->GetPosition().y);
  return res;
}

bool SpriteComponent::Draw()
{
  SDL_RenderCopy(_Texture->GetRenderer(), _Texture->GetTexture(), &_SrcRect, &_DstRect);
  return true;
}