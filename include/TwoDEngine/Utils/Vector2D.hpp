#ifndef TWO2DENGINE_UTILS_VECTOR2D_HPP
#define TWO2DENGINE_UTILS_VECTOR2D_HPP

#include <iostream>

template<class T>
class Vector2D {
public:
  T x{}, y{};
  Vector2D() = default;
  Vector2D(T xx, T yy) : x{xx}, y{yy} { }
  Vector2D(const Vector2D& v) = default;
  Vector2D(Vector2D&& v) = default;

  inline void Reset() {
    x = 0;
    y = 0;
  }

  Vector2D& operator=(const Vector2D& v) = default;

  inline Vector2D operator+(const Vector2D& v) const {
    Vector2D{x + v.x, y + v.y};
  }

  inline Vector2D operator-(const Vector2D& v) const {
    return Vector2D{x - v.x, y - v.y};
  }

  inline T operator*(const Vector2D& v) const {
    return x * v.x + y * v.y;
  }

  inline Vector2D operator*(const T& a) const {
    return Vector2D{x * a, y * a};
  }

  Vector2D& operator+=(const Vector2D& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vector2D& operator-=(const Vector2D& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  Vector2D& operator*=(const T& a) {
    x *= a;
    y *= a;
    return *this;
  }

  inline friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v) {
    stream << "Vec2D(" << v.x << ", " << v.y << ")";
    return stream;
  }
};

#endif