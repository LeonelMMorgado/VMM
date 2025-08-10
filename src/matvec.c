#include <math.h>
#include <matvec.h>

Vector2 vec2_scalar_add(Vector2 in, float scalar) {
    return (Vector2){in.x + scalar, in.y + scalar};
}

Vector3 vec3_scalar_add(Vector3 in, float scalar) {
    return (Vector3){in.x + scalar, in.y + scalar, in.z + scalar};
}

Vector4 vec4_scalar_add(Vector4 in, float scalar) {
    return (Vector4){in.x + scalar, in.y + scalar, in.z + scalar, in.w + scalar};
}


Vector2 vec2_scalar_sub(Vector2 in, float scalar) {
    return (Vector2){in.x - scalar, in.y - scalar};
}

Vector3 vec3_scalar_sub(Vector3 in, float scalar) {
    return (Vector3){in.x - scalar, in.y - scalar, in.z - scalar};
}

Vector4 vec4_scalar_sub(Vector4 in, float scalar) {
    return (Vector4){in.x - scalar, in.y - scalar, in.z - scalar, in.w - scalar};
}


Vector2 vec2_scalar_mul(Vector2 in, float scalar) {
    return (Vector2){in.x * scalar, in.y * scalar};
}

Vector3 vec3_scalar_mul(Vector3 in, float scalar) {
    return (Vector3){in.x * scalar, in.y * scalar, in.z * scalar};
}

Vector4 vec4_scalar_mul(Vector4 in, float scalar) {
    return (Vector4){in.x * scalar, in.y * scalar, in.z * scalar, in.w * scalar};
}


Vector2 vec2_scalar_div(Vector2 in, float scalar) {
    if(scalar == 0) return (Vector2){0, 0};
    return (Vector2){in.x / scalar, in.y / scalar};
}

Vector3 vec3_scalar_div(Vector3 in, float scalar) {
    if(scalar == 0) return (Vector3){0, 0, 0};
    return (Vector3){in.x / scalar, in.y / scalar, in.z / scalar};
}

Vector4 vec4_scalar_div(Vector4 in, float scalar) {
    if(scalar == 0) return (Vector4){0, 0, 0};
    return (Vector4){in.x / scalar, in.y / scalar, in.z / scalar, in.w / scalar};
}


Vector2 vec2_negate(Vector2 in) {
    return (Vector2){-in.x, -in.y};
}

Vector3 vec3_negate(Vector3 in) {
    return (Vector3){-in.x, -in.y, -in.z};
}

Vector4 vec4_negate(Vector4 in) {
    return (Vector4){-in.x, -in.y, -in.z, -in.w};
}


Vector2 vec2_add(Vector2 a, Vector2 b) {
    return (Vector2){a.x + b.x, a.y + b.y};
}

Vector3 vec3_add(Vector3 a, Vector3 b) {
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector4 vec4_add(Vector4 a, Vector4 b) {
    return (Vector4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}


Vector2 vec2_sub(Vector2 a, Vector2 b) {
    return (Vector2){a.x - b.x, a.y - b.y};
}

Vector3 vec3_sub(Vector3 a, Vector3 b) {
    return (Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vector4 vec4_sub(Vector4 a, Vector4 b) {
    return (Vector4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}


float vec2_dot(Vector2 a, Vector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

float vec3_dot(Vector3 a, Vector3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float vec4_dot(Vector4 a, Vector4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}


Vector3 vec3_cross(Vector3 a, Vector3 b) {
    return (Vector3){(a.y*b.z)-(a.z*b.y), (a.z*b.x)-(a.x*b.z), (a.x*b.y)-(a.y*b.x)};
}


float vec2_len(Vector2 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y));
}

float vec3_len(Vector3 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z));
}

float vec4_len(Vector4 in) {
    return sqrtf((in.x*in.x) + (in.y*in.y) + (in.z*in.z) + (in.w*in.w));
}


float vec2_angle(Vector2 a, Vector2 b) {
    float la = vec2_len(a);
    float lb = vec2_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec2_dot(a, b)/(la*lb));
}

float vec3_angle(Vector3 a, Vector3 b) {
    float la = vec3_len(a);
    float lb = vec3_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec3_dot(a, b)/(la*lb));
}

float vec4_angle(Vector4 a, Vector4 b) {
    float la = vec4_len(a);
    float lb = vec4_len(b);
    if(la == 0 || lb == 0) return 0;
    return acosf(vec4_dot(a, b)/(la*lb));
}


Vector2 vec2_normalize(Vector2 in) {
    float len = vec2_len(in);
    if(len == 0) return (Vector2){0, 0};
    return vec2_scalar_div(in, len);
}

Vector3 vec3_normalize(Vector3 in) {
    float len = vec3_len(in);
    if(len == 0) return (Vector3){0, 0, 0};
    return vec3_scalar_div(in, len);
}

Vector4 vec4_normalize(Vector4 in) {
    float len = vec4_len(in);
    if(len == 0) return (Vector4){0, 0, 0, 0};
    return vec4_scalar_div(in, len);
}


Mat3 mat3(float val) {
    Mat3 ret = {0};
    ret.m[0] = val;
    ret.m[4] = val;
    ret.m[8] = val;
    return ret;
}

Mat4 mat4(float val) {
    Mat4 ret = {0};
    ret.m[0] = val;
    ret.m[5] = val;
    ret.m[10] = val;
    ret.m[15] = val;
    return ret;
}


Mat3 mat3_scalar(Mat3 in, float scalar) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
        ret.m[i] = in.m[i] * scalar;
    }
    return ret;
}

Mat4 mat4_scalar(Mat4 in, float scalar) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.m[i] = in.m[i] * scalar;
    }
    return ret;
}


Mat3 mat3_add(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
        ret.m[i] = a.m[i] + b.m[i];
    }
    return ret;
}

Mat4 mat4_add(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.m[i] = a.m[i] + b.m[i];
    }
    return ret;
}


Mat3 mat3_sub(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
        ret.m[i] = a.m[i] - b.m[i];
    }
    return ret;
}

Mat4 mat4_sub(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.m[i] = a.m[i] - b.m[i];
    }
    return ret;
}


Mat3 mat3_mul(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            ret.m[i*3 + j] = (a.m[i*3]*b.m[j])+(a.m[i*3 + 1]*b.m[3 + j])+(a.m[i*3 + 2]*b.m[6 + j]);
    return ret;
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ret.m[i*4 + j] = (a.m[i*4]*b.m[j])+(a.m[i*4 + 1]*b.m[4 + j])+(a.m[i*4 + 2]*b.m[8 + j])+(a.m[i*4 + 3]*b.m[12+j]);
    return ret;
}


Vector3 mat3_vec3(Mat3 a, Vector3 b) {
    Vector3 ret = {0};
    ret.x = (a.m[0]*b.x) + (a.m[1]*b.y) + (a.m[2]*b.z);
    ret.y = (a.m[3]*b.x) + (a.m[4]*b.y) + (a.m[5]*b.z);
    ret.z = (a.m[6]*b.x) + (a.m[7]*b.y) + (a.m[8]*b.z);
    return ret;
}

Vector4 mat4_vec4(Mat4 a, Vector4 b) {
    Vector4 ret = {0};
    ret.x = (a.m[0]*b.x) + (a.m[1]*b.y) + (a.m[2]*b.z) + (a.m[3]*b.w);
    ret.y = (a.m[4]*b.x) + (a.m[5]*b.y) + (a.m[6]*b.z) + (a.m[7]*b.w);
    ret.z = (a.m[8]*b.x) + (a.m[9]*b.y) + (a.m[10]*b.z) + (a.m[11]*b.w);
    ret.w = (a.m[12]*b.x) + (a.m[13]*b.y) + (a.m[14]*b.z) + (a.m[15]*b.w);
    return ret;
}


Mat3 mat3_scale(float s1, float s2) {
    Mat3 ret = {0};
    ret.m[0] = s1;
    ret.m[4] = s2;
    ret.m[8] = 1;
    return ret;
}

Mat4 mat4_scale(float s1, float s2, float s3) {
    Mat4 ret = {0};
    ret.m[0] = s1;
    ret.m[5] = s2;
    ret.m[10] = s3;
    ret.m[15] = 1;
    return ret;
}


Mat3 mat3_translation(float t1, float t2) {
    Mat3 ret = mat3(1);
    ret.m[2] = t1;
    ret.m[5] = t2;
    return ret;
}

Mat4 mat4_translation(float t1, float t2, float t3) {
    Mat4 ret = mat4(1);
    ret.m[3] = t1;
    ret.m[7] = t2;
    ret.m[11] = t3;
    return ret;
}


Mat3 mat3_rotation(float r1) {
    float cx = cosf(r1);
    float sx = sinf(r1);
    Mat3 ret = mat3(1);
    ret.m[0] = cx;
    ret.m[4] = cx;
    ret.m[1] = -sx;
    ret.m[3] = sx;
    return ret;
}

Mat4 mat4_rotation(float r1, float r2, float r3) {
    Mat4 ret = mat4(1);
    float cz = cosf(r3);
    float cy = cosf(r2);
    float cx = cosf(r1);
    float sz = sinf(r3);
    float sy = sinf(r2);
    float sx = sinf(r1);
    ret.m[0] = cz * cy;
    ret.m[1] = -(sz * cx) + (cz * sy * sx);
    ret.m[2] = (sz * sx) + (cz * sy * cx);
    ret.m[4] = sz * cy;
    ret.m[5] = (cz * cx) + (sz * sy * sx);
    ret.m[6] = -(cz * sx) + (sz * sy * cx);
    ret.m[8] = -sy;
    ret.m[9] = cy * sx;
    ret.m[10] = cy * cx;
    return ret;
}


Mat4 mat4_orthogonal(float left, float right, float bottom, float top, float zNear, float zFar) {
    Mat4 ret = mat4(1);
    float width = right - left;
    float height = top - bottom;
    float zDist = zFar - zNear;
    if(width == 0 || height == 0 || zDist == 0) return mat4(0);
    ret.m[0] = 2 / width;
    ret.m[5] = 2 / height;
    ret.m[10] = 1 / zDist;
    ret.m[12] = (right + left) / width;
    ret.m[13] = (top + bottom) / height;
    ret.m[14] = zNear / zDist;
    return ret;
}

Mat4 mat4_perspective(float fovy, float aspect, float zNear, float zFar) {
    float tanHalfFovy = tanf(fovy / 2);
    Mat4 ret = mat4(0);
    if(aspect == 0 || tanHalfFovy == 0 || zFar == zNear) return mat4(0);
    ret.m[0] = 1 / (aspect * tanHalfFovy);
    ret.m[5] = 1 / tanHalfFovy;
    ret.m[10] = zFar / (zNear - zFar);
    ret.m[11] = -1;
    ret.m[14] = -(zFar * zNear) / (zFar - zNear);
    return ret;
}

