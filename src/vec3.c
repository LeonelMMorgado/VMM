#include <math.h>
#include <vec3.h>
#include <stdbool.h>

bool vec3_equal_vec(Vector3 a, Vector3 b) {
    return a.x == b.x && a.y && b.y && a.z == b.z;
}

Vector3 vec3_scalar_add(Vector3 in, float scalar) {
    return (Vector3){in.x + scalar, in.y + scalar, in.z + scalar};
}

Vector3 vec3_scalar_sub(Vector3 in, float scalar) {
    return (Vector3){in.x - scalar, in.y - scalar, in.z - scalar};
}

Vector3 vec3_scalar_mul(Vector3 in, float scalar) {
    return (Vector3){in.x * scalar, in.y * scalar, in.z * scalar};
}

Vector3 vec3_scalar_div(Vector3 in, float scalar) {
    if(scalar == 0) return (Vector3){0, 0, 0};
    return (Vector3){in.x / scalar, in.y / scalar, in.z / scalar};
}

Vector3 vec3_negate(Vector3 in) {
    return (Vector3){-in.x, -in.y, -in.z};
}

Vector3 vec3_add(Vector3 a, Vector3 b) {
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3 vec3_sub(Vector3 a, Vector3 b) {
    return (Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

float vec3_dot(Vector3 a, Vector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 vec3_cross(Vector3 a, Vector3 b) {
    return (Vector3){(a.y*b.z)-(a.z*b.y), (a.z*b.x)-(a.x*b.z), (a.x*b.y)-(a.y*b.x)};
}

float vec3_len(Vector3 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z));
}

float vec3_angle(Vector3 a, Vector3 b) {
    float la = vec3_len(a);
    float lb = vec3_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec3_dot(a, b)/(la*lb));
}

Vector3 vec3_normalize(Vector3 in) {
    float len = vec3_len(in);
    if(len == 0) return (Vector3){0, 0, 0};
    return vec3_scalar_div(in, len);
}
