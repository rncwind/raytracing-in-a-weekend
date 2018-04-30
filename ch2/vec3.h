#include <iostream>
#include <math.h>
#include <stdlib.h>

class vec3
{
public:
    vec3() {}                          // Default constructor
    vec3(float e0, float e1, float e2) // Constructor from 3 scalars
    {
        e[0] = e0, e[1] = e1, e[2] = e2;
    }

    // Geometry functions
    const inline float x() { return e[0]; } // Return x co-ord
    const inline float y() { return e[1]; } // Return y co-ord
    const inline float z() { return e[2]; } // Return z co-ord

    // Colour functions
    const inline float r() { return e[0]; } // Return Red value
    const inline float g() { return e[1]; } // Return Green value
    const inline float b() { return e[2]; } // Return Blue value

    // Vector functions
    inline const vec3& operator+() const { return *this; }              // Vector addition
    inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } // Vector subtraction
    inline float operator[](int i) const { return e[i]; }               // subscript operator
    inline float& operator[](int i) { return e[i]; };                   // Subscript a ref

    inline vec3& operator+=(const vec3 &v2); // Incriment and asign
    inline vec3& operator-=(const vec3 &v2); // Deincriment and assign
    inline vec3& operator*=(const vec3 &v2); // Multiply and assign
    inline vec3& operator/=(const vec3 &v2); // Divide and assign

    inline vec3& operator*=(const float t); // Multiply and asign, ret float
    inline vec3& operator/=(const float t); // Divide and assign, ret float

    friend inline std::istream& operator>>(std::istream& is, vec3& t);
    friend inline std::ostream& operator<<(std::ostream& os, const vec3 &t);

    const inline float length() // Return length of the vector
    {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }

    const inline float squared_length() // Return the squared length of the vector
    {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    inline void make_unit_vector();

    float e[3];
};

// Make a unit-vector from a vec3
inline void vec3::make_unit_vector()
{
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}



// Returns the dot-product of two vec3s
inline float dot(const vec3& v1, const vec3& v2)
{
    return (v1.e[0] * v2.e[0]) + (v1.e[1] * v2.e[1]) + (v1.e[2] * v2.e[2]);
}

// Returns the cross-product of two vec3s
inline vec3 cross(const vec3& v1, const vec3& v2)
{
    return vec3 ((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                  (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
                  (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

inline std::istream& operator>>(std::istream& is, vec3& t)
{
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const vec3 &t)
{
    os << t.e[0] << ' ' << t.e[1] << ' ' << t.e[2];
    return os;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator*(float t, const vec3& v)
{
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator/(float t, const vec3& v)
{
    return vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
}

inline vec3& vec3::operator+=(const vec3& v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3& v)
{
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v)
{
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v)
{
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const float t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

inline vec3& vec3::operator/=(const float t)
{
    float k = 1.0/t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

inline vec3 unit_vector(vec3 v)
{
    return v /= v.length();
}
