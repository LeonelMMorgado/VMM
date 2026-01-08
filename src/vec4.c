#include <math.h>
#include <vec4.h>
#include <stdbool.h>

Vec4 vec4_float(float x, float y, float z, float w) {
    return (Vec4){.x = x, .y = y, .z = z, .w = w};
}

Vec4 vec4_vec4(Vec4 vec) {
    return vec;
}

Vec4 vec4_zero(void) {
    return (Vec4){.x = 0, .y = 0, .z = 0, .w = 0};
}

Vec4 vec4_one(void) {
    return (Vec4){.x = 1.0, .y = 1.0, .z = 1.0, .w = 1.0};
}

bool vec4_equal_vec(Vec4 a, Vec4 b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

Vec4 vec4_min(Vec4 a, Vec4 b) {
    return (Vec4){.x = fminf(a.x, b.x), .y = fminf(a.y, b.y), .z = fminf(a.z, b.z), .w = fminf(a.w, b.w)};
}

Vec4 vec4_max(Vec4 a, Vec4 b) {
    return (Vec4){.x = fmaxf(a.x, b.x), .y = fmaxf(a.y, b.y), .z = fmaxf(a.z, b.z), .w = fmaxf(a.w, b.w)};
}

Vec4 vec4_abs(Vec4 a) {
    return (Vec4){.x = fabsf(a.x), .y = fabsf(a.y), .z = fabsf(a.z), .w = fabsf(a.w)};
}

Vec4 vec4_sign(Vec4 a) {
    return vec4_div(a, vec4_abs(a));
}

Vec4 vec4_scalar_add(Vec4 in, float scalar) {
    return (Vec4){.x = in.x + scalar, .y = in.y + scalar, .z = in.z + scalar, .w = in.w + scalar};
}

Vec4 vec4_scalar_sub(Vec4 in, float scalar) {
    return (Vec4){.x = in.x - scalar, .y = in.y - scalar, .z = in.z - scalar, .w = in.w - scalar};
}

Vec4 vec4_scalar_mul(Vec4 in, float scalar) {
    return (Vec4){.x = in.x * scalar, .y = in.y * scalar, .z = in.z * scalar, .w = in.w * scalar};
}

Vec4 vec4_scalar_div(Vec4 in, float scalar) {
    if(scalar == 0) return (Vec4){.x = 0, .y = 0, .z = 0, .w = 0};
    return (Vec4){.x = in.x / scalar, .y = in.y / scalar, .z = in.z / scalar, .w = in.w / scalar};
}

Vec4 vec4_negate(Vec4 in) {
    return (Vec4){.x = -in.x, .y = -in.y, .z = -in.z, .w = -in.w};
}

Vec4 vec4_add(Vec4 a, Vec4 b) {
    return (Vec4){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w};
}

Vec4 vec4_sub(Vec4 a, Vec4 b) {
    return (Vec4){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .w = a.w - b.w};
}

Vec4 vec4_mul(Vec4 a, Vec4 b) {
    return (Vec4){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z, .w = a.w * b.w};
}

Vec4 vec4_div(Vec4 a, Vec4 b) {
    if(b.x == 0.0) {
        a.x = 0.0;
        b.x = 1.0;
    }
    if(b.y == 0.0) {
        a.y = 0.0;
        b.y = 1.0;
    }
    if(b.z == 0.0) {
        a.z = 0.0;
        b.z = 1.0;
    }
    if(b.w == 0.0) {
        a.w = 0.0;
        b.w = 1.0;
    }
    return (Vec4){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z, .w = a.w / b.w};
}

float vec4_dot(Vec4 a, Vec4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

float vec4_len(Vec4 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z) + (in.w*in.w));
}

float vec4_angle(Vec4 a, Vec4 b) {
    float la = vec4_len(a);
    float lb = vec4_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec4_dot(a, b)/(la*lb));
}

Vec4 vec4_normalize(Vec4 in) {
    float len = vec4_len(in);
    if(len == 0) return (Vec4){.x = 0, .y = 0, .z = 0, .w = 0};
    return vec4_scalar_div(in, len);
}

