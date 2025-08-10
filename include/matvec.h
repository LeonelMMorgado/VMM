#ifndef _MATVEC_H
#define _MATVEC_H


//TODO: Add look_at(), perspective, orthographic

typedef struct _vec2 {
    float x;
    float y;
} Vector2;

typedef struct _vec3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct _vec4 {
    float x;
    float y;
    float z;
    float w;
} Vector4;

Vector2 vec2_scalar_add(Vector2 in, float scalar);
Vector3 vec3_scalar_add(Vector3 in, float scalar);
Vector4 vec4_scalar_add(Vector4 in, float scalar);

Vector2 vec2_scalar_sub(Vector2 in, float scalar);
Vector3 vec3_scalar_sub(Vector3 in, float scalar);
Vector4 vec4_scalar_sub(Vector4 in, float scalar);

Vector2 vec2_scalar_mul(Vector2 in, float scalar);
Vector3 vec3_scalar_mul(Vector3 in, float scalar);
Vector4 vec4_scalar_mul(Vector4 in, float scalar);

Vector2 vec2_scalar_div(Vector2 in, float scalar);
Vector3 vec3_scalar_div(Vector3 in, float scalar);
Vector4 vec4_scalar_div(Vector4 in, float scalar);

Vector2 vec2_negate(Vector2 in);
Vector3 vec3_negate(Vector3 in);
Vector4 vec4_negate(Vector4 in);

Vector2 vec2_add(Vector2 a, Vector2 b);
Vector3 vec3_add(Vector3 a, Vector3 b);
Vector4 vec4_add(Vector4 a, Vector4 b);

Vector2 vec2_sub(Vector2 a, Vector2 b);
Vector3 vec3_sub(Vector3 a, Vector3 b);
Vector4 vec4_sub(Vector4 a, Vector4 b);

float vec2_dot(Vector2 a, Vector2 b);
float vec3_dot(Vector3 a, Vector3 b);
float vec4_dot(Vector4 a, Vector4 b);

float vec2_angle(Vector2 a, Vector2 b);
float vec3_angle(Vector3 a, Vector3 b);
float vec4_angle(Vector4 a, Vector4 b);

Vector3 vec3_cross(Vector3 a, Vector3 b);

float vec2_len(Vector2 in);
float vec3_len(Vector3 in);
float vec4_len(Vector4 in);

Vector2 vec2_normalize(Vector2 in);
Vector3 vec3_normalize(Vector3 in);
Vector4 vec4_normalize(Vector4 in);


typedef struct _mat3 {
    float m[9];
} Mat3;

typedef struct _mat4 {
    float m[16];
} Mat4;

Mat3 mat3(float val);
Mat4 mat4(float val);

Mat3 mat3_scalar(Mat3 in, float scalar);
Mat4 mat4_scalar(Mat4 in, float scalar);

Mat3 mat3_add(Mat3 a, Mat3 b);
Mat4 mat4_add(Mat4 a, Mat4 b);

Mat3 mat3_sub(Mat3 a, Mat3 b);
Mat4 mat4_sub(Mat4 a, Mat4 b);

Mat3 mat3_mul(Mat3 a, Mat3 b);
Mat4 mat4_mul(Mat4 a, Mat4 b);

Vector3 mat3_vec3(Mat3 a, Vector3 b);
Vector4 mat4_vec4(Mat4 a, Vector4 b);

Mat3 mat3_scale(float s1, float s2);
Mat4 mat4_scale(float s1, float s2, float s3);

Mat3 mat3_translation(float t1, float t2);
Mat4 mat4_translation(float t1, float t2, float t3);

Mat3 mat3_rotation(float r1);
Mat4 mat4_rotation(float r1, float r2, float r3);

Mat4 mat4_orthogonal(float left, float right, float bottom, float top, float zNear, float zFar);
Mat4 mat4_perspective(float fov, float aspect, float zNear, float zFar);

#endif