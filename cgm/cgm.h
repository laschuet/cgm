/*******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-present Lars Schütz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/
#ifndef CGM_H_INCLUDE
#define CGM_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef CGM_STATIC
#define CGM_LINKAGE static
#else
#define CGM_LINKAGE
#endif // CGM_STATIC

#define CGM_ALMOST_ZERO 10e-7f
#define CGM_ONE_DEG_IN_RAD 0.017453f
#define CGM_ONE_RAD_IN_DEG 57.295779f
#define CGM_PI 3.141592f
#define CGM_2_PI 6.283184f

#ifdef _WIN32
#ifdef far
#undef far
#endif // far
#ifdef near
#undef near
#endif // near
#endif // _WIN32

typedef struct vec2 {
    float x;
    float y;
} vec2;

typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

// Stored in column-major order
typedef struct mat4 {
    float m[16];
} mat4;

// -----------------------------------------------------------------------------
// Vector functions
// -----------------------------------------------------------------------------
// Constructors
CGM_LINKAGE vec2 vec2_2f(float x, float y);
CGM_LINKAGE vec2 vec2_vec2(vec2 v);
CGM_LINKAGE vec2 vec2_vec3(vec3 v);
CGM_LINKAGE vec2 vec2_vec4(vec4 v);

CGM_LINKAGE vec3 vec3_3f(float x, float y, float z);
CGM_LINKAGE vec3 vec3_vec2_f(vec2 v, float z);
CGM_LINKAGE vec3 vec3_vec3(vec3 v);
CGM_LINKAGE vec3 vec3_vec4(vec4 v);

CGM_LINKAGE vec4 vec4_4f(float x, float y, float z, float w);
CGM_LINKAGE vec4 vec4_vec2_2f(vec2 v, float z, float w);
CGM_LINKAGE vec4 vec4_vec3_f(vec3 v, float w);
CGM_LINKAGE vec4 vec4_vec4(vec4 v);

// Basic mathematical operators
CGM_LINKAGE vec2 vec2_add_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_add_vec2(vec2 a, vec2 b);
CGM_LINKAGE vec2 vec2_div_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_div_vec2(vec2 a, vec2 b);
CGM_LINKAGE vec2 vec2_mul_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_mul_vec2(vec2 a, vec2 c);
CGM_LINKAGE vec2 vec2_sub_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_sub_vec2(vec2 a, vec2 d);

CGM_LINKAGE vec3 vec3_add_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_add_vec3(vec3 a, vec3 b);
CGM_LINKAGE vec3 vec3_div_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_div_vec3(vec3 a, vec3 b);
CGM_LINKAGE vec3 vec3_mul_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_mul_vec3(vec3 a, vec3 b);
CGM_LINKAGE vec3 vec3_sub_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_sub_vec3(vec3 a, vec3 b);

CGM_LINKAGE vec4 vec4_add_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_add_vec4(vec4 a, vec4 b);
CGM_LINKAGE vec4 vec4_div_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_div_vec4(vec4 a, vec4 b);
CGM_LINKAGE vec4 vec4_mul_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_mul_vec4(vec4 a, vec4 b);
CGM_LINKAGE vec4 vec4_sub_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_sub_vec4(vec4 a, vec4 b);

// Vector specific operators
CGM_LINKAGE float vec2_dot_vec2(vec2 a, vec2 b);
CGM_LINKAGE float vec2_length(vec2 v);
CGM_LINKAGE float vec2_sq_length(vec2 v);
CGM_LINKAGE vec2 vec2_normalize(vec2 v);

CGM_LINKAGE vec3 vec3_cross_vec3(vec3 a, vec3 b);
CGM_LINKAGE float vec3_dot_vec3(vec3 a, vec3 b);
CGM_LINKAGE float vec3_length(vec3 v);
CGM_LINKAGE float vec3_sq_length(vec3 v);
CGM_LINKAGE vec3 vec3_normalize(vec3 v);

CGM_LINKAGE vec4 vec4_cross_vec4(vec4 a, vec4 b);
CGM_LINKAGE float vec4_dot_vec4(vec4 a, vec4 b);
CGM_LINKAGE float vec4_length(vec4 v);
CGM_LINKAGE float vec4_sq_length(vec4 v);
CGM_LINKAGE vec4 vec4_normalize(vec4 v);

// Output
CGM_LINKAGE void vec2_print(vec2 v);
CGM_LINKAGE void vec3_print(vec3 v);
CGM_LINKAGE void vec4_print(vec4 v);

// -----------------------------------------------------------------------------
// Matrix functions
// -----------------------------------------------------------------------------
// Constructors
CGM_LINKAGE mat4 mat4_identity();
CGM_LINKAGE mat4 mat4_zero();
CGM_LINKAGE mat4 mat4_mat4(mat4 M);

// Value access
CGM_LINKAGE vec4 mat4_col(mat4 M, int col);
CGM_LINKAGE vec4 mat4_row(mat4 M, int row);
CGM_LINKAGE float mat4_entry(mat4 M, int col, int row);

// Basic mathematical operators
CGM_LINKAGE mat4 mat4_add_mat4(mat4 M, mat4 N);
CGM_LINKAGE mat4 mat4_div_f(mat4 M, float s);
CGM_LINKAGE mat4 mat4_mul_f(mat4 M, float s);
CGM_LINKAGE mat4 mat4_mul_mat4(mat4 M, mat4 N);
CGM_LINKAGE vec4 mat4_mul_vec4(mat4 M, vec4 v);
CGM_LINKAGE mat4 mat4_sub_mat4(mat4 M, mat4 N);

// Matrix specific operators
CGM_LINKAGE float mat4_determinant(mat4 M);
CGM_LINKAGE mat4 mat4_invert(mat4 M);
CGM_LINKAGE mat4 mat4_transpose(mat4 M);

// Transformation operators
CGM_LINKAGE mat4 mat4_rotate(vec3 axis, float rad);
CGM_LINKAGE mat4 mat4_rotate_x(float rad);
CGM_LINKAGE mat4 mat4_rotate_y(float rad);
CGM_LINKAGE mat4 mat4_rotate_z(float rad);
CGM_LINKAGE mat4 mat4_scale(vec3 v);
CGM_LINKAGE mat4 mat4_translate(vec3 v);

// Virtual camera functions
CGM_LINKAGE mat4 mat4_frustum(float left, float right, float bottom, float top,
                            float near, float far);
CGM_LINKAGE mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up);
CGM_LINKAGE mat4 mat4_ortho(float left, float right, float bottom, float top,
                            float near, float far);
CGM_LINKAGE mat4 mat4_perspective(float fovy, float aspect, float near,
                                float far);

// Output
CGM_LINKAGE void mat4_print(mat4 M);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CGM_H_INCLUDE

#ifdef CGM_IMPLEMENTATION
#undef CGM_IMPLEMENTATION

#include <math.h>
#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Vector functions
// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_2f(float x, float y)
{
    vec2 r;
    r.x = x;
    r.y = y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec2(vec2 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec3(vec3 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec4(vec4 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_3f(float x, float y, float z)
{
    vec3 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec2_f(vec2 v, float z)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec3(vec3 v)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec4(vec4 v)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_4f(float x, float y, float z, float w)
{
    vec4 r;
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec2_2f(vec2 v, float z, float w)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec3_f(vec3 v, float w)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec4(vec4 v)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = v.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_add_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x + s;
    r.y = v.y + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_add_vec2(vec2 a, vec2 b)
{
    vec2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_div_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x / s;
    r.y = v.y / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_div_vec2(vec2 a, vec2 b)
{
    vec2 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_mul_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_mul_vec2(vec2 a, vec2 b)
{
    vec2 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_sub_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x - s;
    r.y = v.y - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_sub_vec2(vec2 a, vec2 b)
{
    vec2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_add_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x + s;
    r.y = v.y + s;
    r.z = v.z + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_add_vec3(vec3 a, vec3 b)
{
    vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_div_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x / s;
    r.y = v.y / s;
    r.z = v.z / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_div_vec3(vec3 a, vec3 b)
{
    vec3 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_mul_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_mul_vec3(vec3 a, vec3 b)
{
    vec3 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_sub_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x - s;
    r.y = v.y - s;
    r.z = v.z - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_sub_vec3(vec3 a, vec3 b)
{
    vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_add_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x + s;
    r.y = v.y + s;
    r.z = v.z + s;
    r.w = v.w + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_add_vec4(vec4 a, vec4 b)
{
    vec4 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_mul_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    r.w = v.w * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_mul_vec4(vec4 a, vec4 b)
{
    vec4 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_div_vec4(vec4 a, vec4 b)
{
    vec4 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    r.w = a.w / b.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_div_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x / s;
    r.y = v.y / s;
    r.z = v.z / s;
    r.w = v.w / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_sub_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x - s;
    r.y = v.y - s;
    r.z = v.z - s;
    r.w = v.w - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_sub_vec4(vec4 a, vec4 b)
{
    vec4 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_dot_vec2(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_length(vec2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_sq_length(vec2 v)
{
    return v.x * v.x + v.y * v.y;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_normalize(vec2 v)
{
    vec2 r;
    float length = vec2_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec2_2f(0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_cross_vec3(vec3 a, vec3 b)
{
    float x = a.y * b.z - a.z * b.y;
    float y = a.z * b.x - a.x * b.z;
    float z = a.x * b.y - a.y * b.x;
    return vec3_3f(x, y, z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_dot_vec3(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_sq_length(vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_normalize(vec3 v)
{
    vec3 r;
    float length = vec3_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec3_3f(0.0f, 0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    r.z = v.z / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_cross_vec4(vec4 a, vec4 b)
{
    float x = a.y * b.z - a.z * b.y;
    float y = a.z * b.x - a.x * b.z;
    float z = a.x * b.y - a.y * b.x;
    return vec4_4f(x, y, z, 1.0f);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_dot_vec4(vec4 a, vec4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_length(vec4 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_sq_length(vec4 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_normalize(vec4 v)
{
    vec4 r;
    float length = vec4_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec4_4f(0.0f, 0.0f, 0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    r.z = v.z / length;
    r.w = v.w / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec2_print(vec2 v)
{
    printf("(%.4f, %.4f)'", v.x, v.y);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec3_print(vec3 v)
{
    printf("(%.4f, %.4f, %.4f)'", v.x, v.y, v.z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec4_print(vec4 v)
{
    printf("(%.4f, %.4f, %.4f, %.4f)'", v.x, v.y, v.z, v.w);
}

// -----------------------------------------------------------------------------
// Matrix functions
// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_identity()
{
    mat4 R = mat4_zero();
    R.m[0] = 1.0f;
    R.m[5] = 1.0f;
    R.m[10] = 1.0f;
    R.m[15] = 1.0f;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_zero(){
    mat4 R;
    memset(R.m, 0, 16 * sizeof(float));
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mat4(mat4 M)
{
    mat4 R;
    memcpy(R.m, M.m, 16 * sizeof(float));
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_col(mat4 M, int col)
{
    vec4 r;
    r.x = M.m[4 * col];
    r.y = M.m[1 + 4 * col];
    r.z = M.m[2 + 4 * col];
    r.w = M.m[3 + 4 * col];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_row(mat4 M, int row)
{
    vec4 r;
    r.x = M.m[row];
    r.y = M.m[row + 4];
    r.z = M.m[row + 8];
    r.w = M.m[row + 12];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float mat4_entry(mat4 M, int col, int row)
{
    return M.m[row + 4 * col];
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_add_mat4(mat4 M, mat4 N)
{
    mat4 R = mat4_mat4(M);
    R.m[0] += N.m[0];
    R.m[1] += N.m[1];
    R.m[2] += N.m[2];
    R.m[3] += N.m[3];
    R.m[4] += N.m[4];
    R.m[5] += N.m[5];
    R.m[6] += N.m[6];
    R.m[7] += N.m[7];
    R.m[8] += N.m[8];
    R.m[9] += N.m[9];
    R.m[10] += N.m[10];
    R.m[11] += N.m[11];
    R.m[12] += N.m[12];
    R.m[13] += N.m[13];
    R.m[14] += N.m[14];
    R.m[15] += N.m[15];
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_div_f(mat4 M, float s)
{
    mat4 R = mat4_mat4(M);
    R.m[0] /= s;
    R.m[1] /= s;
    R.m[2] /= s;
    R.m[3] /= s;
    R.m[4] /= s;
    R.m[5] /= s;
    R.m[6] /= s;
    R.m[7] /= s;
    R.m[8] /= s;
    R.m[9] /= s;
    R.m[10] /= s;
    R.m[11] /= s;
    R.m[12] /= s;
    R.m[13] /= s;
    R.m[14] /= s;
    R.m[15] /= s;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mul_f(mat4 M, float s)
{
    mat4 R = mat4_mat4(M);
    R.m[0] *= s;
    R.m[1] *= s;
    R.m[2] *= s;
    R.m[3] *= s;
    R.m[4] *= s;
    R.m[5] *= s;
    R.m[6] *= s;
    R.m[7] *= s;
    R.m[8] *= s;
    R.m[9] *= s;
    R.m[10] *= s;
    R.m[11] *= s;
    R.m[12] *= s;
    R.m[13] *= s;
    R.m[14] *= s;
    R.m[15] *= s;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mul_mat4(mat4 M, mat4 N)
{
    mat4 R;
    int r_entry_pos = 0;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (int i = 0; i < 4; i++) {
                sum += N.m[i + 4 * col] * M.m[row + 4 * i];
            }
            R.m[r_entry_pos] = sum;
            r_entry_pos++;
        }
    }
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_mul_vec4(mat4 M, vec4 v)
{
    vec4 r;
    r.x = M.m[0] * v.x + M.m[4] * v.y + M.m[8] * v.z + M.m[12] * v.w;
    r.y = M.m[1] * v.x + M.m[5] * v.y + M.m[9] * v.z + M.m[13] * v.w;
    r.z = M.m[2] * v.x + M.m[6] * v.y + M.m[10] * v.z + M.m[14] * v.w;
    r.w = M.m[3] * v.x + M.m[7] * v.y + M.m[11] * v.z + M.m[15] * v.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_sub_mat4(mat4 M, mat4 N)
{
    mat4 R = mat4_mat4(M);
    R.m[0] -= N.m[0];
    R.m[1] -= N.m[1];
    R.m[2] -= N.m[2];
    R.m[3] -= N.m[3];
    R.m[4] -= N.m[4];
    R.m[5] -= N.m[5];
    R.m[6] -= N.m[6];
    R.m[7] -= N.m[7];
    R.m[8] -= N.m[8];
    R.m[9] -= N.m[9];
    R.m[10] -= N.m[10];
    R.m[11] -= N.m[11];
    R.m[12] -= N.m[12];
    R.m[13] -= N.m[13];
    R.m[14] -= N.m[14];
    R.m[15] -= N.m[15];
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float mat4_determinant(mat4 M)
{
    /*
    00 04 08 12
    01 05 09 13
    02 06 10 14
    03 07 11 15
    */
    return
        M.m[0] * M.m[5] * M.m[10] * M.m[15] +
        M.m[0] * M.m[9] * M.m[14] * M.m[7] +
        M.m[0] * M.m[13] * M.m[6] * M.m[11] -
        M.m[0] * M.m[13] * M.m[10] * M.m[7] -
        M.m[0] * M.m[9] * M.m[6] * M.m[15] -
        M.m[0] * M.m[5] * M.m[14] * M.m[11] -
        M.m[4] * M.m[9] * M.m[14] * M.m[3] -
        M.m[4] * M.m[13] * M.m[2] * M.m[11] -
        M.m[4] * M.m[1] * M.m[10] * M.m[15] +
        M.m[4] * M.m[1] * M.m[14] * M.m[11] +
        M.m[4] * M.m[13] * M.m[10] * M.m[3] +
        M.m[4] * M.m[9] * M.m[2] * M.m[15] +
        M.m[8] * M.m[13] * M.m[2] * M.m[7] +
        M.m[8] * M.m[1] * M.m[6] * M.m[15] +
        M.m[8] * M.m[5] * M.m[14] * M.m[3] -
        M.m[8] * M.m[5] * M.m[2] * M.m[15] -
        M.m[8] * M.m[1] * M.m[14] * M.m[7] -
        M.m[8] * M.m[13] * M.m[6] * M.m[3] -
        M.m[12] * M.m[1] * M.m[6] * M.m[11] -
        M.m[12] * M.m[5] * M.m[10] * M.m[3] -
        M.m[12] * M.m[9] * M.m[2] * M.m[7] +
        M.m[12] * M.m[9] * M.m[6] * M.m[3] +
        M.m[12] * M.m[5] * M.m[2] * M.m[11] +
        M.m[12] * M.m[1] * M.m[10] * M.m[7];
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_invert(mat4 M)
{
    float det = mat4_determinant(M);
    if (fabsf(det) < CGM_ALMOST_ZERO) {
        return M;
    }

    /*
    00 04 08 12
    01 05 09 13
    02 06 10 14
    03 07 11 15
    */
    mat4 R;
    R.m[0] =
        M.m[9] * M.m[14] * M.m[7] - M.m[13] * M.m[10] * M.m[7] +
        M.m[13] * M.m[6] * M.m[11] - M.m[5] * M.m[14] * M.m[11] -
        M.m[9] * M.m[6] * M.m[15] + M.m[5] * M.m[10] * M.m[15];
    R.m[1] =
        M.m[13] * M.m[10] * M.m[3] - M.m[9] * M.m[14] * M.m[3] -
        M.m[13] * M.m[2] * M.m[11] + M.m[1] * M.m[14] * M.m[11] +
        M.m[9] * M.m[2] * M.m[15] - M.m[1] * M.m[10] * M.m[15];
    R.m[2] =
        M.m[5] * M.m[14] * M.m[3] - M.m[13] * M.m[6] * M.m[3] +
        M.m[13] * M.m[2] * M.m[7] - M.m[1] * M.m[14] * M.m[7] -
        M.m[5] * M.m[2] * M.m[15] + M.m[1] * M.m[6] * M.m[15];
    R.m[3] =
        M.m[9] * M.m[6] * M.m[3] - M.m[5] * M.m[10] * M.m[3] -
        M.m[9] * M.m[2] * M.m[7] + M.m[1] * M.m[10] * M.m[7] +
        M.m[5] * M.m[2] * M.m[11] - M.m[1] * M.m[6] * M.m[11];
    R.m[4] =
        M.m[12] * M.m[10] * M.m[7] - M.m[8] * M.m[14] * M.m[7] -
        M.m[12] * M.m[6] * M.m[11] + M.m[4] * M.m[14] * M.m[11] +
        M.m[8] * M.m[6] * M.m[15] - M.m[4] * M.m[10] * M.m[15];
    R.m[5] =
        M.m[8] * M.m[14] * M.m[3] - M.m[12] * M.m[10] * M.m[3] +
        M.m[12] * M.m[2] * M.m[11] - M.m[0] * M.m[14] * M.m[11] -
        M.m[8] * M.m[2] * M.m[15] + M.m[0] * M.m[10] * M.m[15];
    R.m[6] =
        M.m[12] * M.m[6] * M.m[3] - M.m[4] * M.m[14] * M.m[3] -
        M.m[12] * M.m[2] * M.m[7] + M.m[0] * M.m[14] * M.m[7] +
        M.m[4] * M.m[2] * M.m[15] - M.m[0] * M.m[6] * M.m[15];
    R.m[7] =
        M.m[4] * M.m[10] * M.m[3] - M.m[8] * M.m[6] * M.m[3] +
        M.m[8] * M.m[2] * M.m[7] - M.m[0] * M.m[10] * M.m[7] -
        M.m[4] * M.m[2] * M.m[11] + M.m[0] * M.m[6] * M.m[11];
    R.m[8] =
        M.m[8] * M.m[13] * M.m[7] - M.m[12] * M.m[9] * M.m[7] +
        M.m[12] * M.m[5] * M.m[11] - M.m[4] * M.m[13] * M.m[11] -
        M.m[8] * M.m[5] * M.m[15] + M.m[4] * M.m[9] * M.m[15];
    R.m[9] =
        M.m[12] * M.m[9] * M.m[3] - M.m[8] * M.m[13] * M.m[3] -
        M.m[12] * M.m[1] * M.m[11] + M.m[0] * M.m[13] * M.m[11] +
        M.m[8] * M.m[1] * M.m[15] - M.m[0] * M.m[9] * M.m[15];
    R.m[10] =
        M.m[4] * M.m[13] * M.m[3] - M.m[12] * M.m[5] * M.m[3] +
        M.m[12] * M.m[1] * M.m[7] - M.m[0] * M.m[13] * M.m[7] -
        M.m[4] * M.m[1] * M.m[15] + M.m[0] * M.m[5] * M.m[15];
    R.m[11] =
        M.m[8] * M.m[5] * M.m[3] - M.m[4] * M.m[9] * M.m[3] -
        M.m[8] * M.m[1] * M.m[7] + M.m[0] * M.m[9] * M.m[7] +
        M.m[4] * M.m[1] * M.m[11] - M.m[0] * M.m[5] * M.m[11];
    R.m[12] =
        M.m[12] * M.m[9] * M.m[6] - M.m[8] * M.m[13] * M.m[6] -
        M.m[12] * M.m[5] * M.m[10] + M.m[4] * M.m[13] * M.m[10] +
        M.m[8] * M.m[5] * M.m[14] - M.m[4] * M.m[9] * M.m[14];
    R.m[13] =
        M.m[8] * M.m[13] * M.m[2] - M.m[12] * M.m[9] * M.m[2] +
        M.m[12] * M.m[1] * M.m[10] - M.m[0] * M.m[13] * M.m[10] -
        M.m[8] * M.m[1] * M.m[14] + M.m[0] * M.m[9] * M.m[14];
    R.m[14] =
        M.m[12] * M.m[5] * M.m[2] - M.m[4] * M.m[13] * M.m[2] -
        M.m[12] * M.m[1] * M.m[6] + M.m[0] * M.m[13] * M.m[6] +
        M.m[4] * M.m[1] * M.m[14] - M.m[0] * M.m[5] * M.m[14];
    R.m[15] =
        M.m[4] * M.m[9] * M.m[2] - M.m[8] * M.m[5] * M.m[2] +
        M.m[8] * M.m[1] * M.m[6] - M.m[0] * M.m[9] * M.m[6] -
        M.m[4] * M.m[1] * M.m[10] + M.m[0] * M.m[5] * M.m[10];

    return mat4_mul_f(R, 1.0f / det);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_transpose(mat4 M)
{
    mat4 R;
    R.m[0] = M.m[0];
    R.m[1] = M.m[4];
    R.m[2] = M.m[8];
    R.m[3] = M.m[12];
    R.m[4] = M.m[1];
    R.m[5] = M.m[5];
    R.m[6] = M.m[9];
    R.m[7] = M.m[13];
    R.m[8] = M.m[2];
    R.m[9] = M.m[6];
    R.m[10] = M.m[10];
    R.m[11] = M.m[14];
    R.m[12] = M.m[3];
    R.m[13] = M.m[7];
    R.m[14] = M.m[11];
    R.m[15] = M.m[15];
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate(vec3 axis, float rad)
{
    if (vec3_length(axis) != 1.0f) {
        axis = vec3_normalize(axis);
    }
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    // Rodrigues rotation formula
    float c = cosf(rad);
    float s = sinf(rad);
    float tmp = sinf(rad / 2.0f);
    float t = 2.0f * tmp * tmp; // 1.0f - cosf(rad);
    mat4 R;
    R.m[0] = t * x * x + c;
    R.m[1] = t * x * y + s * z;
    R.m[2] = t * x * z - s * y;
    R.m[3] = 0.0f;
    R.m[4] = t * x * y - s * z;
    R.m[5] = t * y * y + c;
    R.m[6] = t * y * z + s * x;
    R.m[7] = 0.0f;
    R.m[8] = t * x * z + s * y;
    R.m[9] = t * y * z - s * x;
    R.m[10] = t * z * z + c;
    R.m[11] = 0.0f;
    R.m[12] = 0.0f;
    R.m[13] = 0.0f;
    R.m[14] = 0.0f;
    R.m[15] = 1.0f;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_x(float rad)
{
    mat4 R = mat4_identity();
    R.m[5] = cosf(rad);
    R.m[6] = sinf(rad);
    R.m[9] = -sinf(rad);
    R.m[10] = cosf(rad);
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_y(float rad)
{
    mat4 R = mat4_identity();
    R.m[0] = cosf(rad);
    R.m[2] = -sinf(rad);
    R.m[8] = sinf(rad);
    R.m[10] = cosf(rad);
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_z(float rad)
{
    mat4 R = mat4_identity();
    R.m[0] = cosf(rad);
    R.m[1] = sinf(rad);
    R.m[4] = -sinf(rad);
    R.m[5] = cosf(rad);
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_scale(vec3 v)
{
    mat4 R = mat4_identity();
    R.m[0] = v.x;
    R.m[5] = v.y;
    R.m[10] = v.z;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_translate(vec3 v)
{
    mat4 R = mat4_identity();
    R.m[12] = v.x;
    R.m[13] = v.y;
    R.m[14] = v.z;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_frustum(float left, float right, float bottom, float top,
                            float near, float far)
{
    mat4 R = mat4_zero();
    R.m[0] = 2.0f * near / (right - left);
    R.m[5] = 2.0f * near / (top - bottom);
    R.m[8] = (right + left) / (right - left);
    R.m[9] = (top + bottom) / (top - bottom);
    R.m[10] = -(far + near) / (far - near);
    R.m[11] = -1.0f;
    R.m[14] = -2.0f * (far * near) / (far - near);
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up)
{
    vec3 f = vec3_sub_vec3(center, eye);
    f = vec3_normalize(f);
    vec3 up_normalized = vec3_normalize(up);
    vec3 s = vec3_cross_vec3(f, up_normalized);
    vec3 s_normalized = vec3_normalize(s);
    vec3 u = vec3_cross_vec3(s_normalized, f);

    mat4 M = mat4_zero();
    M.m[0] = s.x;
    M.m[1] = u.x;
    M.m[2] = -f.x;
    M.m[4] = s.y;
    M.m[5] = u.y;
    M.m[6] = -f.y;
    M.m[8] = s.z;
    M.m[9] = u.z;
    M.m[10] = -f.z;
    M.m[15] = 1.0f;
    mat4 T = mat4_translate(vec3_3f(-eye.x, -eye.y, -eye.z));
    return mat4_mul_mat4(M, T);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_ortho(float left, float right, float bottom, float top,
                            float near, float far)
{
    mat4 R = mat4_zero();
    R.m[0] = 2.0f / (right - left);
    R.m[5] = 2.0f / (top - bottom);
    R.m[10] = -2.0f / (far - near);
    R.m[12] = -(right + left) / (right - left);
    R.m[13] = -(top + bottom) / (top - bottom);
    R.m[14] = -(far + near) / (far - near);
    R.m[15] = 1.0f;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_perspective(float fovy, float aspect, float near,
                                float far)
{
    float fovy_rad = CGM_ONE_DEG_IN_RAD * fovy;
    float range = tanf(fovy_rad / 2.0f) * near;
    float s_x = (2.0f * near) / (range * aspect + range * aspect);
    float s_y = near / range;
    float s_z = -(far + near) / (far - near);
    float p_z = -(2.0f * far * near) / (far - near);

    mat4 R = mat4_zero();
    R.m[0] = s_x;
    R.m[5] = s_y;
    R.m[10] = s_z;
    R.m[11] = -1.0f;
    R.m[14] = p_z;
    return R;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void mat4_print(mat4 M)
{
    printf("(%.4f %.4f %.4f %.4f)\n", M.m[0], M.m[4], M.m[8], M.m[12]);
    printf("(%.4f %.4f %.4f %.4f)\n", M.m[1], M.m[5], M.m[9], M.m[13]);
    printf("(%.4f %.4f %.4f %.4f)\n", M.m[2], M.m[6], M.m[10], M.m[14]);
    printf("(%.4f %.4f %.4f %.4f)", M.m[3], M.m[7], M.m[11], M.m[15]);
}

#endif // CGM_IMPLEMENTATION
