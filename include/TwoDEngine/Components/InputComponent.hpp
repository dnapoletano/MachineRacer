#ifndef TWO2DENGINE_COMPONENTS_InputComponent_H
#define TWO2DENGINE_COMPONENTS_InputComponent_H

#include "TwoDEngine/Components/ComponentBase.hpp"
#include "TwoDEngine/Components/TransformComponent.hpp"
#include <SDL2/SDL.h>

class InputComponent : public ComponentBase
{
private:
  TransformComponent* _TransformComponent;
  SDL_Event * _Event;
public:
  InputComponent(TransformComponent* TransformComponent) :
    _TransformComponent{TransformComponent} {}

  inline bool Init() override {
    return true;
  }

  inline bool Update() override {
    switch(_Event->type) {
      case SDL_KEYDOWN:
        switch(_Event->key.keysym.sym) {
          case SDLK_RIGHT:
          case SDLK_d:
            std::cout << "Pressed Right Button! " << std::endl;
            _TransformComponent->Velocity().x = 1;
            break;
          case SDLK_UP:
          case SDLK_w:
            _TransformComponent->Velocity().y = -1;
            break;
          case SDLK_LEFT:
          case SDLK_a:
            _TransformComponent->Velocity().x = -1;
            break;
          case SDLK_DOWN:
          case SDLK_s:
            _TransformComponent->Velocity().y = 1;
            break;
        }
        break;
      case SDL_KEYUP:
      default:
        break;
    }
    return true;
  }
  inline bool Draw() override {return true;}

  inline void SetEvent(SDL_Event * Event) {_Event = Event;}
};

#endif