#pragma once
#include "vec3.h"

// A ray is easy to think of as a function p(t) = A + t*B
// Where p is a 3d position along a 3d vector.
// A is the origin of the vector, And B is it's direction and t is a real number

class ray
{
public:
    vec3 A;
    vec3 B;
    ray() {} //Default constructor
    ray(const vec3& a, const vec3& b) { A = a; B = b;} //Construct ray from 2 vectors
    vec3 origin() const    { return A; } //Get the origin of the ray
    vec3 direction() const { return B; } //Get the direction of the ray
    vec3 point_at_paramter(float t) const { return A+ t*B; }
};
