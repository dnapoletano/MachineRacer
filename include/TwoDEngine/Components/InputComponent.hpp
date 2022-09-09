#ifndef TWO2DENGINE_COMPONENTS_InputComponent_H
#define TWO2DENGINE_COMPONENTS_InputComponent_H

#include "TwoDEngine/Components/ComponentBase.hpp"
#include "TwoDEngine/Components/TransformComponent.hpp"
#include <SDL2/SDL.h>

class InputComponent : public ComponentBase
{
private:
  TransformComponent* _TransformComponent;

public:
  InputComponent();

  inline bool Init() override {
    return true;
  }

  inline bool Update() override {

    return true;
  }
};

#endif