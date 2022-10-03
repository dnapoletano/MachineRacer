#ifndef TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H
#define TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H

#include "TwoDEngine/Components/ComponentBase.hpp"
#include "TwoDEngine/Utils/Vector2D.hpp"

class TransformComponent : public ComponentBase {
private:
  int _Speed{5};
  Vector2D<int> _Position;
  Vector2D<int> _Velocity;

public:
  TransformComponent(const Vector2D<int>& InitialPosition) :
    ComponentBase(), _Position{InitialPosition}, _Velocity{} {}
  bool Init() override;
  bool Update() override;
  bool Draw() override;
  inline const Vector2D<int>& GetPosition() const {return _Position;}
  inline const Vector2D<int>& GetVelocity() const {return _Velocity;}
  inline Vector2D<int>& Position() {return _Position;}
  inline Vector2D<int>& Velocity() {return _Velocity;}
  inline void ResetVelocity() {_Velocity.Reset();}
};

#endif // TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H