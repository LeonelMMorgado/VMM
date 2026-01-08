#include <math.h>
#include <ivec2.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int32_t _ivec2_min(int32_t a, int32_t b) {
    return a < b ? a : b;
}

int32_t _ivec2_max(int32_t a, int32_t b) {
    return a > b ? a : b;
}

IVec2 ivec2_int(int32_t x, int32_t y) {
    return (IVec2){.x = x, .y = y};
}

IVec2 ivec2_ivec2(IVec2 vec) {
    return vec;
}

IVec2 ivec2_vec3(Vec2 vec) {
    return (IVec2){.x = (int32_t)vec.x, .y = (int32_t)vec.y};
}

IVec2 ivec2_zero(void) {
    return (IVec2){.x = 0, .y = 0};
}

IVec2 ivec2_one(void) {
    return (IVec2){.x = 1, .y = 1};
}

IVec2 ivec2_left(void) {
    return (IVec2){.x = -1, .y = 0};
}

IVec2 ivec2_right(void) {
    return (IVec2){.x = 1, .y = 0};
}

IVec2 ivec2_down(void) {
    return (IVec2){.x = 0, .y = -1};
}

IVec2 ivec2_up(void) {
    return (IVec2){.x = 0, .y = 1};
}


bool ivec2_equal_vec(IVec2 a, IVec2 b) {
    return a.x == b.x && a.y && b.y;
}

IVec2 ivec2_min(IVec2 a, IVec2 b) {
    return (IVec2){.x = _ivec2_min(a.x, b.x), .y = _ivec2_min(a.y, b.y)};
}

IVec2 ivec2_max(IVec2 a, IVec2 b) {
    return (IVec2){.x = _ivec2_max(a.x, b.x), .y = _ivec2_max(a.y, b.y)};
}

IVec2 ivec2_abs(IVec2 a) {
    return (IVec2){.x = abs(a.x), .y = abs(a.y)};
}

IVec2 ivec2_sign(IVec2 a) {
    return ivec2_div(a, ivec2_abs(a));
}

IVec2 ivec2_scalar_add(IVec2 in, int scalar) {
    return (IVec2){.x = in.x + scalar, .y = in.y + scalar};
}

IVec2 ivec2_scalar_sub(IVec2 in, int scalar) {
    return (IVec2){.x = in.x - scalar, .y = in.y - scalar};
}

IVec2 ivec2_scalar_mul(IVec2 in, int scalar) {
    return (IVec2){.x = in.x * scalar, .y = in.y * scalar};
}

IVec2 ivec2_scalar_div(IVec2 in, int scalar) {
    if(scalar == 0) return (IVec2){.x = 0, .y = 0};
    return (IVec2){.x = in.x / scalar, .y = in.y / scalar};
}

IVec2 ivec2_negate(IVec2 in) {
    return (IVec2){.x = -in.x, .y = -in.y};
}

IVec2 ivec2_add(IVec2 a, IVec2 b) {
    return (IVec2){.x = a.x + b.x, .y = a.y + b.y};
}

IVec2 ivec2_sub(IVec2 a, IVec2 b) {
    return (IVec2){.x = a.x - b.x, .y = a.y - b.y};
}

IVec2 ivec2_mul(IVec2 a, IVec2 b) {
    return (IVec2){.x = a.x * b.x, .y = a.y * b.y};
}

IVec2 ivec2_div(IVec2 a, IVec2 b) {
    return (IVec2){.x = a.x / b.x, .y = a.y / b.y};
}

float ivec2_dot(IVec2 a, IVec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

float ivec2_len(IVec2 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y));
}

float ivec2_angle(IVec2 a, IVec2 b) {
    float la = ivec2_len(a);
    float lb = ivec2_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(ivec2_dot(a, b)/(la*lb));
}

IVec2 ivec2_normalize(IVec2 in) {
    float len = ivec2_len(in);
    if(len == 0) return (IVec2){.x = 0, .y = 0};
    return ivec2_scalar_div(in, len);
}
