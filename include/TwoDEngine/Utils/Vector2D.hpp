#ifndef TWO2DENGINE_UTILS_VECTOR2D_HPP
#define TWO2DENGINE_UTILS_VECTOR2D_HPP

#include <iostream>

class Vector2D {
public:
  float x{0.0f}, y{0.0f};
  Vector2D() = default;
  Vector2D(float xx, float yy) : x{xx}, y{yy} { }
  Vector2D(const Vector2D& v) = default;
  Vector2D(Vector2D&& v) = default;

  Vector2D& operator=(const Vector2D& v) = default;

  Vector2D operator+(const Vector2D& v);
  Vector2D operator-(const Vector2D& v);
  float operator*(const Vector2D& v);
  Vector2D operator*(const float& a);

  Vector2D& operator+=(const Vector2D& v);
  Vector2D& operator-=(const Vector2D& v);
  Vector2D& operator*=(const float& a);

  friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};



#endif