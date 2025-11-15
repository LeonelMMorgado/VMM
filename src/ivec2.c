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

IVector2 ivec2_int(int32_t x, int32_t y, int32_t z) {
    return (IVector2){.x = x, .y = y};
}

IVector2 ivec2_ivec2(IVector2 vec) {
    return vec;
}

IVector2 ivec2_vec3(Vector2 vec) {
    return (IVector2){.x = (int32_t)vec.x, .y = (int32_t)vec.y};
}

IVector2 ivec2_zero(void) {
    return (IVector2){.x = 0, .y = 0};
}

IVector2 ivec2_one(void) {
    return (IVector2){.x = 1, .y = 1};
}

IVector2 ivec2_left(void) {
    return (IVector2){.x = -1, .y = 0};
}

IVector2 ivec2_right(void) {
    return (IVector2){.x = 1, .y = 0};
}

IVector2 ivec2_down(void) {
    return (IVector2){.x = 0, .y = -1};
}

IVector2 ivec2_up(void) {
    return (IVector2){.x = 0, .y = 1};
}


bool ivec2_equal_vec(IVector2 a, IVector2 b) {
    return a.x == b.x && a.y && b.y;
}

IVector2 ivec2_min(IVector2 a, IVector2 b) {
    return (IVector2){.x = _ivec2_min(a.x, b.x), .y = _ivec2_min(a.y, b.y)};
}

IVector2 ivec2_max(IVector2 a, IVector2 b) {
    return (IVector2){.x = _ivec2_max(a.x, b.x), .y = _ivec2_max(a.y, b.y)};
}

IVector2 ivec2_abs(IVector2 a) {
    return (IVector2){.x = abs(a.x), .y = abs(a.y)};
}

IVector2 ivec2_sign(IVector2 a) {
    return ivec2_div(a, ivec2_abs(a));
}

IVector2 ivec2_scalar_add(IVector2 in, int scalar) {
    return (IVector2){.x = in.x + scalar, .y = in.y + scalar};
}

IVector2 ivec2_scalar_sub(IVector2 in, int scalar) {
    return (IVector2){.x = in.x - scalar, .y = in.y - scalar};
}

IVector2 ivec2_scalar_mul(IVector2 in, int scalar) {
    return (IVector2){.x = in.x * scalar, .y = in.y * scalar};
}

IVector2 ivec2_scalar_div(IVector2 in, int scalar) {
    if(scalar == 0) return (IVector2){.x = 0, .y = 0};
    return (IVector2){.x = in.x / scalar, .y = in.y / scalar};
}

IVector2 ivec2_negate(IVector2 in) {
    return (IVector2){.x = -in.x, .y = -in.y};
}

IVector2 ivec2_add(IVector2 a, IVector2 b) {
    return (IVector2){.x = a.x + b.x, .y = a.y + b.y};
}

IVector2 ivec2_sub(IVector2 a, IVector2 b) {
    return (IVector2){.x = a.x - b.x, .y = a.y - b.y};
}

IVector2 ivec2_mul(IVector2 a, IVector2 b) {
    return (IVector2){.x = a.x * b.x, .y = a.y * b.y};
}

IVector2 ivec2_div(IVector2 a, IVector2 b) {
    return (IVector2){.x = a.x / b.x, .y = a.y / b.y};
}

float ivec2_dot(IVector2 a, IVector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

float ivec2_len(IVector2 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y));
}

float ivec2_angle(IVector2 a, IVector2 b) {
    float la = ivec2_len(a);
    float lb = ivec2_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(ivec2_dot(a, b)/(la*lb));
}

IVector2 ivec2_normalize(IVector2 in) {
    float len = ivec2_len(in);
    if(len == 0) return (IVector2){.x = 0, .y = 0};
    return ivec2_scalar_div(in, len);
}
