#include <math.h>
#include <vec4.h>
#include <stdbool.h>

Vector4 vec4_float(float x, float y, float z, float w) {
    return (Vector4){.x = x, .y = y, .z = z, .w = w};
}

Vector4 vec4_vec4(Vector4 vec) {
    return vec;
}

Vector4 vec4_zero(void) {
    return (Vector4){.x = 0, .y = 0, .z = 0, .w = 0};
}

Vector4 vec4_one(void) {
    return (Vector4){.x = 1.0, .y = 1.0, .z = 1.0, .w = 1.0};
}

bool vec4_equal_vec(Vector4 a, Vector4 b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

Vector4 vec4_min(Vector4 a, Vector4 b) {
    return (Vector4){.x = fminf(a.x, b.x), .y = fminf(a.y, b.y), .z = fminf(a.z, b.z), .w = fminf(a.w, b.w)};
}

Vector4 vec4_max(Vector4 a, Vector4 b) {
    return (Vector4){.x = fmaxf(a.x, b.x), .y = fmaxf(a.y, b.y), .z = fmaxf(a.z, b.z), .w = fmaxf(a.w, b.w)};
}

Vector4 vec4_abs(Vector4 a) {
    return (Vector4){.x = fabsf(a.x), .y = fabsf(a.y), .z = fabsf(a.z), .w = fabsf(a.w)};
}

Vector4 vec4_sign(Vector4 a) {
    return vec4_div(a, vec4_abs(a));
}

Vector4 vec4_scalar_add(Vector4 in, float scalar) {
    return (Vector4){.x = in.x + scalar, .y = in.y + scalar, .z = in.z + scalar, .w = in.w + scalar};
}

Vector4 vec4_scalar_sub(Vector4 in, float scalar) {
    return (Vector4){.x = in.x - scalar, .y = in.y - scalar, .z = in.z - scalar, .w = in.w - scalar};
}

Vector4 vec4_scalar_mul(Vector4 in, float scalar) {
    return (Vector4){.x = in.x * scalar, .y = in.y * scalar, .z = in.z * scalar, .w = in.w * scalar};
}

Vector4 vec4_scalar_div(Vector4 in, float scalar) {
    if(scalar == 0) return (Vector4){.x = 0, .y = 0, .z = 0, .w = 0};
    return (Vector4){.x = in.x / scalar, .y = in.y / scalar, .z = in.z / scalar, .w = in.w / scalar};
}

Vector4 vec4_negate(Vector4 in) {
    return (Vector4){.x = -in.x, .y = -in.y, .z = -in.z, .w = -in.w};
}

Vector4 vec4_add(Vector4 a, Vector4 b) {
    return (Vector4){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w};
}

Vector4 vec4_sub(Vector4 a, Vector4 b) {
    return (Vector4){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .w = a.w - b.w};
}

Vector4 vec4_mul(Vector4 a, Vector4 b) {
    return (Vector4){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z, .w = a.w * b.w};
}

Vector4 vec4_div(Vector4 a, Vector4 b) {
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
    return (Vector4){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z, .w = a.w / b.w};
}

float vec4_dot(Vector4 a, Vector4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

float vec4_len(Vector4 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z) + (in.w*in.w));
}

float vec4_angle(Vector4 a, Vector4 b) {
    float la = vec4_len(a);
    float lb = vec4_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec4_dot(a, b)/(la*lb));
}

Vector4 vec4_normalize(Vector4 in) {
    float len = vec4_len(in);
    if(len == 0) return (Vector4){.x = 0, .y = 0, .z = 0, .w = 0};
    return vec4_scalar_div(in, len);
}

