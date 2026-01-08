#include <math.h>
#include <vec3.h>
#include <stdbool.h>

Vec3 vec3_float(float x, float y, float z) {
    return (Vec3){.x = x, .y = y, .z = z};
}

Vec3 vec3_vec3(Vec3 vec) {
    return vec;
}

Vec3 vec3_vec4(Vec4 vec) {
    return (Vec3){.x = vec.x, .y = vec.y, .z = vec.z};
}

Vec3 vec3_ivec3(IVec3 vec) {
    return (Vec3){.x = (float)vec.x, .y = (float)vec.y, .z = (float)vec.z};
}

Vec3 vec3_zero(void) {
    return (Vec3){.x = 0, .y = 0, .z = 0};
}

Vec3 vec3_one(void) {
    return (Vec3){.x = 1.0, .y = 1.0, .z = 1.0};
}

Vec3 vec3_left(void) {
    return (Vec3){.x = -1.0, .y = 0.0, .z = 0.0};
}

Vec3 vec3_right(void) {
    return (Vec3){.x = 1.0, .y = 0.0, .z = 0.0};
}

Vec3 vec3_back(void) {
    return (Vec3){.x = 0.0, .y = 0.0, .z = -1.0};
}

Vec3 vec3_forward(void) {
    return (Vec3){.x = 0.0, .y = 0.0, .z = 1.0};
}

Vec3 vec3_down(void) {
    return (Vec3){.x = 0.0, .y = -1.0, .z = 0.0};
}

Vec3 vec3_up(void) {
    return (Vec3){.x = 0.0, .y = 1.0, .z = 0.0};
}


bool vec3_equal_vec(Vec3 a, Vec3 b) {
    return a.x == b.x && a.y && b.y && a.z == b.z;
}

Vec3 vec3_min(Vec3 a, Vec3 b) {
    return (Vec3){.x = fminf(a.x, b.x), .y = fminf(a.y, b.y), .z = fminf(a.z, b.z)};
}

Vec3 vec3_max(Vec3 a, Vec3 b) {
    return (Vec3){.x = fmaxf(a.x, b.x), .y = fmaxf(a.y, b.y), .z = fmaxf(a.z, b.z)};
}

Vec3 vec3_abs(Vec3 a) {
    return (Vec3){.x = fabsf(a.x), .y = fabsf(a.y), .z = fabsf(a.z)};
}

Vec3 vec3_sign(Vec3 a) {
    return vec3_div(a, vec3_abs(a));
}

Vec3 vec3_scalar_add(Vec3 in, float scalar) {
    return (Vec3){.x = in.x + scalar, .y = in.y + scalar, .z = in.z + scalar};
}

Vec3 vec3_scalar_sub(Vec3 in, float scalar) {
    return (Vec3){.x = in.x - scalar, .y = in.y - scalar, .z = in.z - scalar};
}

Vec3 vec3_scalar_mul(Vec3 in, float scalar) {
    return (Vec3){.x = in.x * scalar, .y = in.y * scalar, .z = in.z * scalar};
}

Vec3 vec3_scalar_div(Vec3 in, float scalar) {
    if(scalar == 0) return (Vec3){.x = 0, .y = 0, .z = 0};
    return (Vec3){.x = in.x / scalar, .y = in.y / scalar, .z = in.z / scalar};
}

Vec3 vec3_negate(Vec3 in) {
    return (Vec3){.x = -in.x, .y = -in.y, .z = -in.z};
}

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
}

Vec3 vec3_mul(Vec3 a, Vec3 b) {
    return (Vec3){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z};
}

Vec3 vec3_div(Vec3 a, Vec3 b) {
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
    return (Vec3){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z};
}

float vec3_dot(Vec3 a, Vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){.x = (a.y*b.z)-(a.z*b.y), .y = (a.z*b.x)-(a.x*b.z), .z = (a.x*b.y)-(a.y*b.x)};
}

float vec3_len(Vec3 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z));
}

float vec3_angle(Vec3 a, Vec3 b) {
    float la = vec3_len(a);
    float lb = vec3_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec3_dot(a, b)/(la*lb));
}

Vec3 vec3_normalize(Vec3 in) {
    float len = vec3_len(in);
    if(len == 0) return (Vec3){.x = 0, .y = 0, .z = 0};
    return vec3_scalar_div(in, len);
}
