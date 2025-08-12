#include <math.h>
#include <vec2.h>

Vector2 vec2_scalar_add(Vector2 in, float scalar) {
    return (Vector2){in.x + scalar, in.y + scalar};
}

Vector2 vec2_scalar_sub(Vector2 in, float scalar) {
    return (Vector2){in.x - scalar, in.y - scalar};
}

Vector2 vec2_scalar_mul(Vector2 in, float scalar) {
    return (Vector2){in.x * scalar, in.y * scalar};
}

Vector2 vec2_scalar_div(Vector2 in, float scalar) {
    if(scalar == 0) return (Vector2){0, 0};
    return (Vector2){in.x / scalar, in.y / scalar};
}

Vector2 vec2_negate(Vector2 in) {
    return (Vector2){-in.x, -in.y};
}

Vector2 vec2_add(Vector2 a, Vector2 b) {
    return (Vector2){a.x + b.x, a.y + b.y};
}

Vector2 vec2_sub(Vector2 a, Vector2 b) {
    return (Vector2){a.x - b.x, a.y - b.y};
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
    if(len == 0) return (Vector2){0, 0};
    return vec2_scalar_div(in, len);
}