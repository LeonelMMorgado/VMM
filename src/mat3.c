#include <math.h>
#include <vec3.h>
#include <mat3.h>

Mat3 mat3(float val) {
    Mat3 ret = {0};
    ret.a = val;
    ret.d = val;
    ret.g = val;
    return ret;
}

Mat3 mat3_scalar(Mat3 in, float scalar) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
        ret.mat[i] = in.mat[i] * scalar;
    }
    return ret;
}

Mat3 mat3_add(Mat3 a, Mat3 b) {
    //Using godbolt, the assembly of this sum and the sum using for is almost the same, but the for uses SIMD for performance so lets choose it
    Mat3 ret = {0};
    //ret.a = a.a + b.a;
    //ret.b = a.b + b.b;
    //ret.c = a.c + b.c;
    //ret.d = a.d + b.d;
    //ret.e = a.e + b.e;
    //ret.f = a.f + b.f;
    //ret.g = a.g + b.g;
    //ret.h = a.h + b.h;
    //ret.i = a.i + b.i;
    for(int i = 0; i < 9; i++) ret.mat[i] = a.mat[i] + b.mat[i];
    return ret;
}

Mat3 mat3_sub(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 9; i++) {
        ret.mat[i] = a.mat[i] - b.mat[i];
    }
    return ret;
}

Mat3 mat3_mul(Mat3 a, Mat3 b) {
    Mat3 ret = {0};
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            ret.mat[i*3 + j] = (a.mat[i*3]*b.mat[j])+(a.mat[i*3 + 1]*b.mat[3 + j])+(a.mat[i*3 + 2]*b.mat[6 + j]);
    return ret;
}

Vec3 mat3_vec3(Mat3 a, Vec3 b) {
    Vec3 ret = {0};
    ret.x = (a.a*b.x) + (a.b*b.y) + (a.c*b.z);
    ret.y = (a.d*b.x) + (a.e*b.y) + (a.f*b.z);
    ret.z = (a.g*b.x) + (a.h*b.y) + (a.i*b.z);
    return ret;
}


float mat3_det(Mat3 a) {
    //a(ei-hf)-d(bi-ch)+g(bf-ce);
    return a.a * (a.e * a.i - a.h * a.f)
         - a.d * (a.b * a.i - a.c * a.h)
         + a.g * (a.b * a.f - a.c * a.e);
}

Mat3 mat3_transp(Mat3 a) {
    Mat3 ret = {0};
    ret.a = a.mat[0];
    ret.b = a.d;
    ret.c = a.g;
    ret.d = a.b;
    ret.e = a.mat[4];
    ret.f = a.h;
    ret.g = a.c;
    ret.h = a.f;
    ret.i = a.mat[8];
    return ret;
}

Mat3 mat3_inverse(Mat3 in) {
    float det;
    float a = in.a, b = in.b, c = in.c,
          d = in.d, e = in.e, f = in.f,
          g = in.g, h = in.h, i = in.i;

    Mat3 dest;
    dest.a =   e * i - f * h;
    dest.b = -(b * i - h * c);
    dest.c =   b * f - e * c;
    dest.d = -(d * i - g * f);
    dest.e =   a * i - c * g;
    dest.f = -(a * f - d * c);
    dest.g =   d * h - g * e;
    dest.h = -(a * h - g * b);
    dest.i =   a * e - b * d;

  det = 1.0f / (a * dest.a + b * dest.d + c * dest.g);
  return mat3_scalar(dest, det);
}

Mat3 mat3_scale(float s1, float s2) {
    Mat3 ret = {0};
    ret.a = s1;
    ret.e = s2;
    ret.i = 1;
    return ret;
}

Mat3 mat3_translation(float t1, float t2) {
    Mat3 ret = mat3(1);
    ret.c = t1;
    ret.f = t2;
    return ret;
}

Mat3 mat3_rotation(float r1) {
    float cx = cosf(r1);
    float sx = sinf(r1);
    Mat3 ret = mat3(1);
    ret.a = cx;
    ret.e = cx;
    ret.b = -sx;
    ret.d = sx;
    return ret;
}
