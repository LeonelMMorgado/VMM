#include <math.h>
#include <vec4.h>

Vector4 vec4_scalar_add(Vector4 in, float scalar) {
    return (Vector4){in.x + scalar, in.y + scalar, in.z + scalar, in.w + scalar};
}

Vector4 vec4_scalar_sub(Vector4 in, float scalar) {
    return (Vector4){in.x - scalar, in.y - scalar, in.z - scalar, in.w - scalar};
}

Vector4 vec4_scalar_mul(Vector4 in, float scalar) {
    return (Vector4){in.x * scalar, in.y * scalar, in.z * scalar, in.w * scalar};
}

Vector4 vec4_scalar_div(Vector4 in, float scalar) {
    if(scalar == 0) return (Vector4){0, 0, 0};
    return (Vector4){in.x / scalar, in.y / scalar, in.z / scalar, in.w / scalar};
}

Vector4 vec4_negate(Vector4 in) {
    return (Vector4){-in.x, -in.y, -in.z, -in.w};
}

Vector4 vec4_add(Vector4 a, Vector4 b) {
    return (Vector4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

Vector4 vec4_sub(Vector4 a, Vector4 b) {
    return (Vector4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
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
    if(len == 0) return (Vector4){0, 0, 0, 0};
    return vec4_scalar_div(in, len);
}

