#include <math.h>
#include <vec3.h>
#include <stdbool.h>

Vector3 vec3_float(float x, float y, float z) {
    return (Vector3){{x, y, z}};
}

Vector3 vec3_vec3(Vector3 vec) {
    return vec;
}

Vector3 vec3_vec4(Vector4 vec) {
    return (Vector3){{vec.x, vec.y, vec.z}};
}

Vector3 vec3_ivec3(IVector3 vec) {
    return (Vector3){{(float)vec.x, (float)vec.y, (float)vec.z}};
}

Vector3 vec3_zero(void) {
    return (Vector3){{0}};
}

Vector3 vec3_one(void) {
    return (Vector3){{1.0, 1.0, 1.0}};
}

Vector3 vec3_left(void) {
    return (Vector3){{-1.0, 0.0, 0.0}};
}

Vector3 vec3_right(void) {
    return (Vector3){{1.0, 0.0, 0.0}};
}

Vector3 vec3_back(void) {
    return (Vector3){{0.0, 0.0, -1.0}};
}

Vector3 vec3_forward(void) {
    return (Vector3){{0.0, 0.0, 1.0}};
}

Vector3 vec3_down(void) {
    return (Vector3){{0.0, -1.0, 0.0}};
}

Vector3 vec3_up(void) {
    return (Vector3){{0.0, 1.0, 0.0}};
}


bool vec3_equal_vec(Vector3 a, Vector3 b) {
    return a.x == b.x && a.y && b.y && a.z == b.z;
}

Vector3 vec3_min(Vector3 a, Vector3 b) {
    return (Vector3){{fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z)}};
}

Vector3 vec3_max(Vector3 a, Vector3 b) {
    return (Vector3){{fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z)}};
}

Vector3 vec3_abs(Vector3 a) {
    return (Vector3){{fabsf(a.x), fabsf(a.y), fabsf(a.z)}};
}

Vector3 vec3_sign(Vector3 a) {
    return vec3_div(a, vec3_abs(a));
}

Vector3 vec3_scalar_add(Vector3 in, float scalar) {
    return (Vector3){{in.x + scalar, in.y + scalar, in.z + scalar}};
}

Vector3 vec3_scalar_sub(Vector3 in, float scalar) {
    return (Vector3){{in.x - scalar, in.y - scalar, in.z - scalar}};
}

Vector3 vec3_scalar_mul(Vector3 in, float scalar) {
    return (Vector3){{in.x * scalar, in.y * scalar, in.z * scalar}};
}

Vector3 vec3_scalar_div(Vector3 in, float scalar) {
    if(scalar == 0) return (Vector3){{0, 0, 0}};
    return (Vector3){{in.x / scalar, in.y / scalar, in.z / scalar}};
}

Vector3 vec3_negate(Vector3 in) {
    return (Vector3){{-in.x, -in.y, -in.z}};
}

Vector3 vec3_add(Vector3 a, Vector3 b) {
    return (Vector3){{a.x + b.x, a.y + b.y, a.z + b.z}};
}

Vector3 vec3_sub(Vector3 a, Vector3 b) {
    return (Vector3){{a.x - b.x, a.y - b.y, a.z - b.z}};
}

Vector3 vec3_mul(Vector3 a, Vector3 b) {
    return (Vector3){{a.x * b.x, a.y * b.y, a.z * b.z}};
}

Vector3 vec3_div(Vector3 a, Vector3 b) {
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
    return (Vector3){{a.x / b.x, a.y / b.y, a.z / b.z}};
}

float vec3_dot(Vector3 a, Vector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 vec3_cross(Vector3 a, Vector3 b) {
    return (Vector3){{(a.y*b.z)-(a.z*b.y), (a.z*b.x)-(a.x*b.z), (a.x*b.y)-(a.y*b.x)}};
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
    if(len == 0) return (Vector3){{0, 0, 0}};
    return vec3_scalar_div(in, len);
}
