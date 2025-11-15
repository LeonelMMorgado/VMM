#include <math.h>
#include "mat4.h"

Mat4 mat4_orthogonal(float left, float right, float bottom, float top, float zNear, float zFar) {
    Mat4 ret = mat4(1);
    float width = right - left;
    float height = top - bottom;
    float zDist = zFar - zNear;
    if(width == 0 || height == 0 || zDist == 0) return mat4(0);
    ret.mat[0] = 2 / width;
    ret.mat[5] = 2 / height;
    ret.mat[10] = 1 / zDist;
    ret.mat[12] = (right + left) / width;
    ret.mat[13] = (top + bottom) / height;
    ret.mat[14] = zNear / zDist;
    return ret;
}

Mat4 mat4_perspective(float fovy, float aspect, float zNear, float zFar) {
    float tanHalfFovy = tanf(fovy / 2);
    Mat4 ret = mat4(0);
    if(aspect == 0 || tanHalfFovy == 0 || zFar == zNear) return mat4(0);
    ret.mat[0] = 1 / (aspect * tanHalfFovy);
    ret.mat[5] = 1 / tanHalfFovy;
    ret.mat[10] = zFar / (zNear - zFar);
    ret.mat[11] = -1;
    ret.mat[14] = -(zFar * zNear) / (zFar - zNear);
    return ret;
}
