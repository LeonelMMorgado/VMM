#include <math.h>
#include <ivec3.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int32_t _ivec3_min(int32_t a, int32_t b) {
    return a < b ? a : b;
}

int32_t _ivec3_max(int32_t a, int32_t b) {
    return a > b ? a : b;
}

IVec3 ivec3_int(int32_t x, int32_t y, int32_t z) {
    return (IVec3){.x = x, .y = y, .z = z};
}

IVec3 ivec3_ivec3(IVec3 vec) {
    return vec;
}

IVec3 ivec3_vec3(Vec3 vec) {
    return (IVec3){.x = (int32_t)vec.x, .y = (int32_t)vec.y, .z = (int32_t)vec.z};
}

IVec3 ivec3_zero(void) {
    return (IVec3){.x = 0, .y = 0, .z = 0};
}

IVec3 ivec3_one(void) {
    return (IVec3){.x = 1, .y = 1, .z = 1};
}

IVec3 ivec3_left(void) {
    return (IVec3){.x = -1, .y = 0, .z = 0};
}

IVec3 ivec3_right(void) {
    return (IVec3){.x = 1, .y = 0, .z = 0};
}

IVec3 ivec3_back(void) {
    return (IVec3){ .x = 0, .y = 0, .z = -1};
}

IVec3 ivec3_forward(void) {
    return (IVec3){.x = 0, .y = 0, .z = 1};
}

IVec3 ivec3_down(void) {
    return (IVec3){.x = 0, .y = -1, .z = 0};
}

IVec3 ivec3_up(void) {
    return (IVec3){.x = 0, .y = 1, .z = 0};
}


bool ivec3_equal_vec(IVec3 a, IVec3 b) {
    return a.x == b.x && a.y && b.y && a.z == b.z;
}

IVec3 ivec3_min(IVec3 a, IVec3 b) {
    return (IVec3){.x = _ivec3_min(a.x, b.x), .y = _ivec3_min(a.y, b.y), .z = _ivec3_min(a.z, b.z)};
}

IVec3 ivec3_max(IVec3 a, IVec3 b) {
    return (IVec3){.x = _ivec3_max(a.x, b.x), .y = _ivec3_max(a.y, b.y), .z = _ivec3_max(a.z, b.z)};
}

IVec3 ivec3_abs(IVec3 a) {
    return (IVec3){.x = abs(a.x), .y = abs(a.y), .z = abs(a.z)};
}

IVec3 ivec3_sign(IVec3 a) {
    return ivec3_div(a, ivec3_abs(a));
}

IVec3 ivec3_scalar_add(IVec3 in, int scalar) {
    return (IVec3){.x = in.x + scalar, .y = in.y + scalar, .z = in.z + scalar};
}

IVec3 ivec3_scalar_sub(IVec3 in, int scalar) {
    return (IVec3){.x = in.x - scalar, .y = in.y - scalar, .z = in.z - scalar};
}

IVec3 ivec3_scalar_mul(IVec3 in, int scalar) {
    return (IVec3){.x = in.x * scalar, .y = in.y * scalar, .z = in.z * scalar};
}

IVec3 ivec3_scalar_div(IVec3 in, int scalar) {
    if(scalar == 0) return (IVec3){.x = 0, .y = 0, .z = 0};
    return (IVec3){.x = in.x / scalar, .y = in.y / scalar, .z = in.z / scalar};
}

IVec3 ivec3_negate(IVec3 in) {
    return (IVec3){.x = -in.x, .y = -in.y, .z = -in.z};
}

IVec3 ivec3_add(IVec3 a, IVec3 b) {
    return (IVec3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z};
}

IVec3 ivec3_sub(IVec3 a, IVec3 b) {
    return (IVec3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
}

IVec3 ivec3_mul(IVec3 a, IVec3 b) {
    return (IVec3){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z};
}

IVec3 ivec3_div(IVec3 a, IVec3 b) {
    return (IVec3){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z};
}

float ivec3_dot(IVec3 a, IVec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

IVec3 ivec3_cross(IVec3 a, IVec3 b) {
    return (IVec3){.x = (a.y*b.z)-(a.z*b.y), .y = (a.z*b.x)-(a.x*b.z), .z = (a.x*b.y)-(a.y*b.x)};
}

float ivec3_len(IVec3 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z));
}

float ivec3_angle(IVec3 a, IVec3 b) {
    float la = ivec3_len(a);
    float lb = ivec3_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(ivec3_dot(a, b)/(la*lb));
}

IVec3 ivec3_normalize(IVec3 in) {
    float len = ivec3_len(in);
    if(len == 0) return (IVec3){.x = 0, .y = 0, .z = 0};
    return ivec3_scalar_div(in, len);
}
