#include <math.h>
#include <vec4.h>
#include <mat4.h>

Mat4 mat4(float val) {
    Mat4 ret = {0};
    ret.m[0] = val;
    ret.m[5] = val;
    ret.m[10] = val;
    ret.m[15] = val;
    return ret;
}

Mat4 mat4_scalar(Mat4 in, float scalar) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.m[i] = in.m[i] * scalar;
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

Mat4 mat4_sub(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.m[i] = a.m[i] - b.m[i];
    }
    return ret;
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ret.m[i*4 + j] = (a.m[i*4]*b.m[j])+(a.m[i*4 + 1]*b.m[4 + j])+(a.m[i*4 + 2]*b.m[8 + j])+(a.m[i*4 + 3]*b.m[12+j]);
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

Mat4 mat4_scale(float s1, float s2, float s3) {
    Mat4 ret = {0};
    ret.m[0] = s1;
    ret.m[5] = s2;
    ret.m[10] = s3;
    ret.m[15] = 1;
    return ret;
}

Mat4 mat4_translation(float t1, float t2, float t3) {
    Mat4 ret = mat4(1);
    ret.m[3] = t1;
    ret.m[7] = t2;
    ret.m[11] = t3;
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