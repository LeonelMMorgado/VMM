#include <math.h>
#include <vec2.h>
#include <stdbool.h>

Vec2 vec2_float(float x, float y) {
    return (Vec2){.x = x, .y = y};
}

Vec2 vec2_vec2(Vec2 vec) {
    return vec;
}

Vec2 vec2_ivec2(IVec2 vec) {
    return (Vec2){.x = (float)vec.x, .y = (float)vec.y};
}

Vec2 vec2_zero(void) {
    return (Vec2){.x = 0, .y = 0};
}

Vec2 vec2_one(void) {
    return (Vec2){.x = 1.0, .y = 1.0};
}

Vec2 vec2_left(void) {
    return (Vec2){.x = -1.0, .y = 0.0};
}

Vec2 vec2_right(void) {
    return (Vec2){.x = 1.0, .y = 0.0};
}

Vec2 vec2_down(void) {
    return (Vec2){.x = 0.0, .y = -1.0};
}

Vec2 vec2_up(void) {
    return (Vec2){.x = 0.0, .y = 1.0};
}

bool vec2_equal_vec(Vec2 a, Vec2 b) {
    return a.x == b.x && a.y == b.y;
}

Vec2 vec2_min(Vec2 a, Vec2 b) {
    return (Vec2){.x = fminf(a.x, b.x), .y = fminf(a.y, b.y)};
}

Vec2 vec2_max(Vec2 a, Vec2 b) {
    return (Vec2){.x = fmaxf(a.x, b.x), .y = fmaxf(a.y, b.y)};
}

Vec2 vec2_abs(Vec2 a) {
    return (Vec2){.x = fabsf(a.x), .y = fabsf(a.y)};
}

Vec2 vec2_sign(Vec2 a) {
    return vec2_div(a, vec2_abs(a));
}

Vec2 vec2_scalar_add(Vec2 in, float scalar) {
    return (Vec2){.x = in.x + scalar, .y = in.y + scalar};
}

Vec2 vec2_scalar_sub(Vec2 in, float scalar) {
    return (Vec2){.x = in.x - scalar, .y = in.y - scalar};
}

Vec2 vec2_scalar_mul(Vec2 in, float scalar) {
    return (Vec2){.x = in.x * scalar, .y = in.y * scalar};
}

Vec2 vec2_scalar_div(Vec2 in, float scalar) {
    if(scalar == 0) return (Vec2){.x = 0, .y = 0};
    return (Vec2){.x = in.x / scalar, .y = in.y / scalar};
}

Vec2 vec2_negate(Vec2 in) {
    return (Vec2){.x = -in.x, .y = -in.y};
}

Vec2 vec2_add(Vec2 a, Vec2 b) {
    return (Vec2){.x = a.x + b.x, .y = a.y + b.y};
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
    return (Vec2){.x = a.x - b.x, .y = a.y - b.y};
}

Vec2 vec2_mul(Vec2 a, Vec2 b) {
    return (Vec2){.x = a.x * b.x, .y = a.y * b.y};
}

Vec2 vec2_div(Vec2 a, Vec2 b) {
    if(b.x == 0.0) {
        a.x = 0.0;
        b.x = 1.0;
    }
    if(b.y == 0.0) {
        a.y = 0.0;
        b.y = 1.0;
    }
    return (Vec2){.x = a.x / b.x, .y = a.y / b.y};
}

float vec2_dot(Vec2 a, Vec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

float vec2_len(Vec2 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y));
}

float vec2_angle(Vec2 a, Vec2 b) {
    float la = vec2_len(a);
    float lb = vec2_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec2_dot(a, b)/(la*lb));
}

Vec2 vec2_normalize(Vec2 in) {
    float len = vec2_len(in);
    if(len == 0) return (Vec2){{0, 0}};
    return vec2_scalar_div(in, len);
}
