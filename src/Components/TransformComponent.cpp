#include "TwoDEngine/Components/TransformComponent.hpp"

bool TransformComponent::Init()
{
  return true;
}

bool TransformComponent::Update()
{
  /**
   * The images I'm using are 25ppi => 1px per mm,
   * thus, to mimic a 0.5cm square, we need to move by
   * 5 px * speed in each direction.
   */
  _Velocity.x = 1.0f;
  _Velocity.y = 0.0f;
  _Position += _Velocity * _Speed;
  return true;
}

bool TransformComponent::Draw()
{
  return true;
}