#include <math.h>
#include <vec3.h>
#include <vec4.h>
#include <mat4.h>

Mat4 mat4(float val) {
    Mat4 ret = {0};
    ret.a = val;
    ret.f = val;
    ret.k = val;
    ret.p = val;
    return ret;
}

Mat4 mat4_scalar(Mat4 in, float scalar) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.mat[i] = in.mat[i] * scalar;
    }
    return ret;
}

Mat4 mat4_add(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.mat[i] = a.mat[i] + b.mat[i];
    }
    return ret;
}

Mat4 mat4_sub(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 16; i++) {
        ret.mat[i] = a.mat[i] - b.mat[i];
    }
    return ret;
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
    Mat4 ret = {0};
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ret.mat[i*4 + j] = (a.mat[i*4]*b.mat[j])+(a.mat[i*4 + 1]*b.mat[4 + j])+(a.mat[i*4 + 2]*b.mat[8 + j])+(a.mat[i*4 + 3]*b.mat[12+j]);
    return ret;
}

Vec4 mat4_vec4(Mat4 a, Vec4 b) {
    Vec4 ret = {0};
    ret.x = (a.a*b.x) + (a.b*b.y) + (a.c*b.z) + (a.d*b.w);
    ret.y = (a.e*b.x) + (a.f*b.y) + (a.g*b.z) + (a.h*b.w);
    ret.z = (a.i*b.x) + (a.j*b.y) + (a.k*b.z) + (a.l*b.w);
    ret.w = (a.m*b.x) + (a.n*b.y) + (a.o*b.z) + (a.p*b.w);
    return ret;
}


float mat4_det(Mat4 in) {
    float t[6];

    t[0] = in.k * in.p - in.o * in.l;
    t[1] = in.j * in.p - in.n * in.l;
    t[2] = in.j * in.o - in.n * in.k;
    t[3] = in.i * in.p - in.m * in.l;
    t[4] = in.i * in.o - in.m * in.k;
    t[5] = in.i * in.n - in.m * in.j;
  
    return in.a * (in.f * t[0] - in.g * t[1] + in.h * t[2])
         - in.b * (in.e * t[0] - in.g * t[3] + in.h * t[4])
         + in.c * (in.e * t[1] - in.f * t[3] + in.h * t[5])
         - in.d * (in.e * t[2] - in.f * t[4] + in.g * t[5]);
}

Mat4 mat4_transp(Mat4 in) {
    Mat4 ret = {0};

    ret.a = in.a;
    ret.b = in.e;
    ret.c = in.i;
    ret.d = in.m;
    ret.e = in.b;
    ret.f = in.f;
    ret.g = in.j;
    ret.h = in.n;
    ret.i = in.c;
    ret.j = in.g;
    ret.k = in.k;
    ret.l = in.o;
    ret.m = in.d;
    ret.n = in.h;
    ret.o = in.l;
    ret.p = in.p;

    return ret;
}

Mat4 mat4_inverse(Mat4 in) {
    float t[6];
    float det;

    Mat4 dest;
    
    t[0] = in.k * in.p - in.o * in.l; t[1] = in.j * in.p - in.n * in.l; t[2] = in.j * in.o - in.n * in.k;
    t[3] = in.i * in.p - in.m * in.l; t[4] = in.i * in.o - in.m * in.k; t[5] = in.i * in.n - in.m * in.j;
    
    dest.mat[0] =  in.f * t[0] - in.g * t[1] + in.h * t[2];
    dest.mat[4] =-(in.e * t[0] - in.g * t[3] + in.h * t[4]);
    dest.mat[8] =  in.e * t[1] - in.f * t[3] + in.h * t[5];
    dest.mat[12] =-(in.e * t[2] - in.f * t[4] + in.g * t[5]);
    
    dest.mat[1] =-(in.b * t[0] - in.c * t[1] + in.d * t[2]);
    dest.mat[5] =  in.a * t[0] - in.c * t[3] + in.d * t[4];
    dest.mat[9] =-(in.a * t[1] - in.b * t[3] + in.d * t[5]);
    dest.mat[13] =  in.a * t[2] - in.b * t[4] + in.c * t[5];
    
    t[0] = in.g * in.p - in.o * in.h; t[1] = in.f * in.p - in.n * in.h; t[2] = in.f * in.o - in.n * in.g;
    t[3] = in.e * in.p - in.m * in.h; t[4] = in.e * in.o - in.m * in.g; t[5] = in.e * in.n - in.m * in.f;
    
    dest.mat[2] =  in.b * t[0] - in.c * t[1] + in.d * t[2];
    dest.mat[6] =-(in.a * t[0] - in.c * t[3] + in.d * t[4]);
    dest.mat[10]=  in.a * t[1] - in.b * t[3] + in.d * t[5];
    dest.mat[14]=-(in.a * t[2] - in.b * t[4] + in.c * t[5]);
    
    t[0] = in.g * in.l - in.k * in.h; t[1] = in.f * in.l - in.j * in.h; t[2] = in.f * in.k - in.j * in.g;
    t[3] = in.e * in.l - in.i * in.h; t[4] = in.e * in.k - in.i * in.g; t[5] = in.e * in.j - in.i * in.f;
    
    dest.mat[3] =-(in.b * t[0] - in.c * t[1] + in.d * t[2]);
    dest.mat[7] =  in.a * t[0] - in.c * t[3] + in.d * t[4];
    dest.mat[11]=-(in.a * t[1] - in.b * t[3] + in.d * t[5]);
    dest.mat[15]=  in.a * t[2] - in.b * t[4] + in.c * t[5];
    
    det = 1.0f / (in.a * dest.mat[0] + in.b * dest.mat[4]
                + in.c * dest.mat[8] + in.d * dest.mat[12]);
    
    return mat4_scalar(dest, det);
}


Mat4 mat4_scale(float s1, float s2, float s3) {
    Mat4 ret = {0};
    ret.a = s1;
    ret.f = s2;
    ret.k = s3;
    ret.p = 1;
    return ret;
}

Mat4 mat4_translation(float t1, float t2, float t3) {
    Mat4 ret = mat4(1);
    ret.d = t1;
    ret.h = t2;
    ret.l = t3;
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
    ret.a = cz * cy;
    ret.b = -(sz * cx) + (cz * sy * sx);
    ret.c = (sz * sx) + (cz * sy * cx);
    ret.e = sz * cy;
    ret.f = (cz * cx) + (sz * sy * sx);
    ret.g = -(cz * sx) + (sz * sy * cx);
    ret.i = -sy;
    ret.j = cy * sx;
    ret.k = cy * cx;
    return ret;
}

Mat4 mat4_look_at(Vec3 eye, Vec3 center, Vec3 up) {
    Mat4 ret = mat4(1);

    Vec3 forward = vec3_sub(center, eye);
    forward = vec3_normalize(forward);

    Vec3 right = vec3_cross(up, forward);
    right = vec3_normalize(right);

    Vec3 new_up = vec3_cross(forward, right);
    ret.a = right.x;
    ret.b = right.y;
    ret.c = right.z;
    ret.d = 0.0f;
    ret.e = new_up.x;
    ret.f = new_up.y;
    ret.g = new_up.z;
    ret.h = 0.0f;
    ret.i = -forward.x;
    ret.j = -forward.y;
    ret.k = -forward.z;
    ret.l = 0.0f;
    ret.m = -vec3_dot(right, eye);
    ret.n = -vec3_dot(new_up, eye);
    ret.o = vec3_dot(forward, eye);
    ret.p = 1.0f;

    return ret;
}

Mat4 mat4_make_model(Vec3 position, Vec3 rotation, Vec3 scale) {
    Mat4 trans = mat4_translation(position.x, position.y, position.z);
    Mat4 rotat = mat4_rotation(rotation.x, rotation.y, rotation.z);
    Mat4 mscal = mat4_scale(scale.x, scale.y, scale.z);
    Mat4 model = mat4_mul(mscal, rotat);
    Mat4 nmodl = mat4_mul(model, trans);
    return nmodl;
}
