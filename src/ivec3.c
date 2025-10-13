#include <math.h>
#include <ivec3.h>
#include <stdbool.h>

bool ivec3_equal_vec(IVector3 a, IVector3 b) {
    return a.x == b.x && a.y && b.y && a.z == b.z;
}

IVector3 ivec3_scalar_add(IVector3 in, int scalar) {
    return (IVector3){in.x + scalar, in.y + scalar, in.z + scalar};
}

IVector3 ivec3_scalar_sub(IVector3 in, int scalar) {
    return (IVector3){in.x - scalar, in.y - scalar, in.z - scalar};
}

IVector3 ivec3_scalar_mul(IVector3 in, int scalar) {
    return (IVector3){in.x * scalar, in.y * scalar, in.z * scalar};
}

IVector3 ivec3_scalar_div(IVector3 in, int scalar) {
    if(scalar == 0) return (IVector3){0, 0, 0};
    return (IVector3){in.x / scalar, in.y / scalar, in.z / scalar};
}

IVector3 ivec3_negate(IVector3 in) {
    return (IVector3){-in.x, -in.y, -in.z};
}

IVector3 ivec3_add(IVector3 a, IVector3 b) {
    return (IVector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

IVector3 ivec3_sub(IVector3 a, IVector3 b) {
    return (IVector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

IVector3 ivec3_mul(IVector3 a, IVector3 b) {
    return (IVector3){a.x * b.x, a.y * b.y, a.z * b.z};
}

IVector3 ivec3_div(IVector3 a, IVector3 b) {
    return (IVector3){a.x / b.x, a.y / b.y, a.z / b.z};
}

float ivec3_dot(IVector3 a, IVector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

IVector3 ivec3_cross(IVector3 a, IVector3 b) {
    return (IVector3){(a.y*b.z)-(a.z*b.y), (a.z*b.x)-(a.x*b.z), (a.x*b.y)-(a.y*b.x)};
}

float ivec3_len(IVector3 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z));
}

float ivec3_angle(IVector3 a, IVector3 b) {
    float la = ivec3_len(a);
    float lb = ivec3_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(ivec3_dot(a, b)/(la*lb));
}

IVector3 ivec3_normalize(IVector3 in) {
    float len = ivec3_len(in);
    if(len == 0) return (IVector3){0, 0, 0};
    return ivec3_scalar_div(in, len);
}
