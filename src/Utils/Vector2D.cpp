#include "TwoDEngine/Utils/Vector2D.hpp"

Vector2D Vector2D::operator+(const Vector2D& v)
{
  return Vector2D{x + v.x, y + v.y};
}

Vector2D Vector2D::operator-(const Vector2D& v)
{
  return Vector2D{x - v.x, y - v.y};
}

float Vector2D::operator*(const Vector2D& v)
{
  return x * v.x + y * v.y;
}

Vector2D Vector2D::operator*(const float& a)
{
  return Vector2D{x * a, y * a};
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
  x += v.x;
  y += v.y;
  return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
  x -= v.x;
  y -= v.y;
  return *this;
}

Vector2D& Vector2D::operator*=(const float& a)
{
  x *= a;
  y *= a;
  return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
  stream << "Vec2D(" << v.x << ", " << v.y << ")";
  return stream;
}