#ifndef TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H
#define TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H

#include "TwoDEngine/Components/ComponentBase.hpp"
#include "TwoDEngine/Utils/Vector2D.hpp"

class TransformComponent : public ComponentBase {
private:
  int _Speed{0};
  Vector2D _Position;
  Vector2D _Velocity;

public:
  TransformComponent(const Vector2D& InitialPosition) :
    ComponentBase(), _Position{InitialPosition}, _Velocity{} {}
  bool Init() override;
  bool Update() override;
  bool Draw() override;
  inline const Vector2D& GetPosition() const {return _Position;}
  inline const Vector2D& GetVelocity() const {return _Velocity;}
  inline Vector2D& Position() {return _Position;}
  inline Vector2D& Velocity() {return _Velocity;}
};

#endif // TWO2DENGINE_COMPONENTS_TRANSFORMCOMPONENT_H