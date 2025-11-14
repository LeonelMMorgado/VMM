#include <math.h>
#include <vec2.h>
#include <stdbool.h>

Vector2 vec2_float(float x, float y) {
    return (Vector2){.x = x, .y = y};
}

Vector2 vec2_vec2(Vector2 vec) {
    return vec;
}

Vector2 vec2_zero(void) {
    return (Vector2){.x = 0, .y = 0};
}

Vector2 vec2_one(void) {
    return (Vector2){.x = 1.0, .y = 1.0};
}

Vector2 vec2_left(void) {
    return (Vector2){.x = -1.0, .y = 0.0};
}

Vector2 vec2_right(void) {
    return (Vector2){.x = 1.0, .y = 0.0};
}

Vector2 vec2_down(void) {
    return (Vector2){.x = 0.0, .y = -1.0};
}

Vector2 vec2_up(void) {
    return (Vector2){.x = 0.0, .y = 1.0};
}

bool vec2_equal_vec(Vector2 a, Vector2 b) {
    return a.x == b.x && a.y == b.y;
}

Vector2 vec2_min(Vector2 a, Vector2 b) {
    return (Vector2){.x = fminf(a.x, b.x), .y = fminf(a.y, b.y)};
}

Vector2 vec2_max(Vector2 a, Vector2 b) {
    return (Vector2){.x = fmaxf(a.x, b.x), .y = fmaxf(a.y, b.y)};
}

Vector2 vec2_abs(Vector2 a) {
    return (Vector2){.x = fabsf(a.x), .y = fabsf(a.y)};
}

Vector2 vec2_sign(Vector2 a) {
    return vec2_div(a, vec2_abs(a));
}

Vector2 vec2_scalar_add(Vector2 in, float scalar) {
    return (Vector2){.x = in.x + scalar, .y = in.y + scalar};
}

Vector2 vec2_scalar_sub(Vector2 in, float scalar) {
    return (Vector2){.x = in.x - scalar, .y = in.y - scalar};
}

Vector2 vec2_scalar_mul(Vector2 in, float scalar) {
    return (Vector2){.x = in.x * scalar, .y = in.y * scalar};
}

Vector2 vec2_scalar_div(Vector2 in, float scalar) {
    if(scalar == 0) return (Vector2){.x = 0, .y = 0};
    return (Vector2){.x = in.x / scalar, .y = in.y / scalar};
}

Vector2 vec2_negate(Vector2 in) {
    return (Vector2){.x = -in.x, .y = -in.y};
}

Vector2 vec2_add(Vector2 a, Vector2 b) {
    return (Vector2){.x = a.x + b.x, .y = a.y + b.y};
}

Vector2 vec2_sub(Vector2 a, Vector2 b) {
    return (Vector2){.x = a.x - b.x, .y = a.y - b.y};
}

Vector2 vec2_mul(Vector2 a, Vector2 b) {
    return (Vector2){.x = a.x * b.x, .y = a.y * b.y};
}

Vector2 vec2_div(Vector2 a, Vector2 b) {
    if(b.x == 0.0) {
        a.x = 0.0;
        b.x = 1.0;
    }
    if(b.y == 0.0) {
        a.y = 0.0;
        b.y = 1.0;
    }
    return (Vector2){.x = a.x / b.x, .y = a.y / b.y};
}

float vec2_dot(Vector2 a, Vector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

float vec2_len(Vector2 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y));
}

float vec2_angle(Vector2 a, Vector2 b) {
    float la = vec2_len(a);
    float lb = vec2_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec2_dot(a, b)/(la*lb));
}

Vector2 vec2_normalize(Vector2 in) {
    float len = vec2_len(in);
    if(len == 0) return (Vector2){{0, 0}};
    return vec2_scalar_div(in, len);
}
