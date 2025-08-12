#include <math.h>
#include <vec3.h>
#include <mat3.h>

Mat3 mat3(float val) {
    Mat3 ret = {0};
    ret.m[0] = val;
    ret.m[4] = val;
    ret.m[8] = val;
    return ret;
}

Mat3 mat3_scalar(Mat3 in, float scalar) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
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

Mat3 mat3_sub(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
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

Vector3 mat3_vec3(Mat3 a, Vector3 b) {
    Vector3 ret = {0};
    ret.x = (a.m[0]*b.x) + (a.m[1]*b.y) + (a.m[2]*b.z);
    ret.y = (a.m[3]*b.x) + (a.m[4]*b.y) + (a.m[5]*b.z);
    ret.z = (a.m[6]*b.x) + (a.m[7]*b.y) + (a.m[8]*b.z);
    return ret;
}

Mat3 mat3_scale(float s1, float s2) {
    Mat3 ret = {0};
    ret.m[0] = s1;
    ret.m[4] = s2;
    ret.m[8] = 1;
    return ret;
}

Mat3 mat3_translation(float t1, float t2) {
    Mat3 ret = mat3(1);
    ret.m[2] = t1;
    ret.m[5] = t2;
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