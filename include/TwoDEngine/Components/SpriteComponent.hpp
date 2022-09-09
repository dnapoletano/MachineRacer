#ifndef TWO2DENGINE_COMPONENTS_SPRITECOMPONENT_H
#define TWO2DENGINE_COMPONENTS_SPRITECOMPONENT_H

#include "TwoDEngine/Components/ComponentBase.hpp"
#include "TwoDEngine/Components/TransformComponent.hpp"
#include "TwoDEngine/Utils/Vector2D.hpp"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <memory>

class TextureWrapper{
private:
  SDL_Renderer* _Renderer;
  SDL_Texture* _Texture;
public:
  TextureWrapper(SDL_Renderer * Renderer, const std::string& texture_path) : _Renderer{Renderer}
  {
    _Texture = IMG_LoadTexture(Renderer, texture_path.data());
  }

  ~TextureWrapper()
  {
    SDL_DestroyTexture(_Texture);
  }
  inline SDL_Texture* GetTexture() {return _Texture;}
  inline SDL_Renderer* GetRenderer() {return _Renderer;}
};

class TransformComponent;
class SpriteComponent : public ComponentBase {
private:
  const int _ImgSize;
  const int _RescaleFactorX, _RescaleFactorY;
  TextureWrapper * _Texture;
  SDL_Rect         _SrcRect;
  SDL_Rect         _DstRect;
  std::unique_ptr<TransformComponent> _TransformComponent;

public:
  SpriteComponent(const std::pair<int,int>& SrcPos, const int imgsize, const int rescalefactorX,
                  const int rescalefactorY, TextureWrapper *Texture, const Vector2D& Position);
  SpriteComponent(SpriteComponent&& sc);
  ~SpriteComponent() override {}

  bool Init() override;
  bool Update() override;
  bool Draw() override;

  inline void SetTexture(TextureWrapper* texture) {_Texture  = texture;}
  inline auto GetTextureComponent() {return _TransformComponent.get();}
};

#endif // TWO2DENGINE_COMPONENTS_SPRITECOMPONENT_H