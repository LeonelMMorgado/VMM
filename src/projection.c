#include <math.h>
#include "mat4.h"

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