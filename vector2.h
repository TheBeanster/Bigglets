#pragma once

#include <math.h>
#include <iostream>



namespace vector2namespace
{

template<typename T>
struct vector2base
{
	T x, y;

	inline constexpr vector2base() { x = 0.0f; y = 0.0f; }
	inline constexpr vector2base(T a) { x = a; y = a; }
	inline constexpr vector2base(T _x, T _y) { x = _x; y = _y; }
	inline constexpr vector2base(const vector2base& v) { x = v.x; y = v.y; }

	inline ~vector2base() = default;

	inline void set(float _x, float _y) { x = _x; y = _y; }

	inline vector2base& operator = (const vector2base& v) { x = v.x; y = v.y; return *this; }
	inline vector2base& operator = (const T& f) { x = f; y = f; return *this; }
	inline vector2base& operator - () { x = -x; y = -y; return *this; }
	inline bool operator == (const vector2base& v) const { return (x == v.x) && (y == v.y); }
	inline bool operator != (const vector2base& v) const { return (x != v.x) || (y != v.y); }

	inline const vector2base& operator + (const vector2base& v) const { return vector2base(x + v.x, y + v.y); }
	inline const vector2base& operator - (const vector2base& v) const { return vector2base(x - v.x, y - v.y); }
	inline const vector2base& operator * (const vector2base& v) const { return vector2base(x * v.x, y * v.y); }
	inline const vector2base& operator / (const vector2base& v) const { return vector2base(x / v.x, y / v.y); }

	inline const vector2base& operator + (const T& f) const { return vector2base(x + f, y + f); }
	inline const vector2base& operator - (const T& f) const { return vector2base(x - f, y - f); }
	inline const vector2base& operator * (const T& f) const { return vector2base(x * f, y * f); }
	inline const vector2base& operator / (const T& f) const { return vector2base(x / f, y / f); }

	inline const vector2base& operator += (const vector2base& v) { x += v.x; y += v.y; return *this; }
	inline const vector2base& operator -= (const vector2base& v) { x -= v.x; y -= v.y; return *this; }
	inline const vector2base& operator *= (const vector2base& v) { x *= v.x; y *= v.y; return *this; }
	inline const vector2base& operator /= (const vector2base& v) { x /= v.x; y /= v.y; return *this; }

	inline const vector2base& operator += (const T& f) { x += f; y += f; return *this; }
	inline const vector2base& operator -= (const T& f) { x -= f; y -= f; return *this; }
	inline const vector2base& operator *= (const T& f) { x *= f; y *= f; return *this; }
	inline const vector2base& operator /= (const T& f) { x /= f; y /= f; return *this; }

};

}



typedef vector2namespace::vector2base<float> vector2;

inline vector2 round(vector2 vec) 
{
	return { roundf(vec.x), roundf(vec.y) };
}



inline std::ostream& operator<<(std::ostream& o, vector2 v)
{
	return o << "{ " << v.x << ", " << v.y << " }";
}
