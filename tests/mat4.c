/*******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Lars Schütz
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

#include <stdio.h>

#define CGM_IMPLEMENTATION
#include "../cgm/cgm.h"

int main()
{
    mat4 m;
    m.m[0] = 1.0f;
    m.m[1] = 0.0f;
    m.m[2] = 1.0f;
    m.m[3] = 2.0f;
    m.m[4] = 4.0f;
    m.m[5] = 1.0f;
    m.m[6] = 0.0f;
    m.m[7] = 0.0f;
    m.m[8] = 2.0f;
    m.m[9] = 4.0f;
    m.m[10] = 1.0f;
    m.m[11] = 4.0f;
    m.m[12] = 3.0f;
    m.m[13] = 4.0f;
    m.m[14] = 0.0f;
    m.m[15] = 1.0f;
    float rad = 45.0f * CGM_ONE_DEG_IN_RAD;

    mat4 mat4_res;
    vec4 vec4_res;

    printf("M =\n");
    mat4_print(m);

    printf("\n\nmat4_identity()\n");
    mat4_res = mat4_identity();
    mat4_print(mat4_res);

    printf("\n\nmat4_zero()\n");
    mat4_res = mat4_zero();
    mat4_print(mat4_res);

    printf("\n\nmat4_mat4(M)\n");
    mat4_res = mat4_mat4(m);
    mat4_print(mat4_res);

    printf("\n\nmat4_col(M, 1)\n");
    vec4_res = mat4_col(m, 1);
    vec4_print(vec4_res);

    printf("\n\nmat4_row(M, 1)\n");
    vec4_res = mat4_row(m, 1);
    vec4_print(vec4_res);

    printf("\n\nmat4_entry(M, 1, 2)\n");
    float entry = mat4_entry(m, 1, 2);
    printf("%f", entry);

    printf("\n\nmat4_add_mat4(M, M)\n");
    mat4_res = mat4_add_mat4(m, m);
    mat4_print(mat4_res);

    printf("\n\nmat4_div_f(M, %f)\n", 2.0f);
    mat4_res = mat4_div_f(m, 2.0f);
    mat4_print(mat4_res);

    printf("\n\nmat4_mul_f(M, %f)\n", 2.0f);
    mat4_res = mat4_mul_f(m, 2.0f);
    mat4_print(mat4_res);

    printf("\n\nmat4_mul_mat4(mat4_identity(), mat4_zero())\n");
    mat4_res = mat4_mul_mat4(mat4_identity(), mat4_zero());
    mat4_print(mat4_res);

    printf("\n\nmat4_mul_vec4(M, (1.0f, 1.0f, 1.0f, 2.0f)^T)\n");
    vec4_res = mat4_mul_vec4(m, vec4_4f(1.0f, 1.0f, 1.0f, 2.0f));
    vec4_print(vec4_res);

    printf("\n\nmat4_sub_mat4(M, M)\n");
    mat4_res = mat4_sub_mat4(m, m);
    mat4_print(mat4_res);

    printf("\n\nmat4_det(M)\n");
    float det = mat4_det(m);
    printf("%f", det);

    printf("\n\nmat4_transpose(M)\n");
    mat4_res = mat4_transpose(m);
    mat4_print(mat4_res);

    printf("\n\nmat4_rotate((1.0f, 1.0f, 1.0f)^T, %f)\n", rad);
    mat4_res = mat4_rotate(vec3_3f(1.0f, 1.0f, 1.0f), rad);
    mat4_print(mat4_res);

    printf("\n\nmat4_rotate_x(%f)\n", rad);
    mat4_res = mat4_rotate_x(rad);
    mat4_print(mat4_res);

    printf("\n\nmat4_rotate_y(%f)\n", rad);
    mat4_res = mat4_rotate_y(rad);
    mat4_print(mat4_res);

    printf("\n\nmat4_rotate_z(%f)\n", rad);
    mat4_res = mat4_rotate_z(rad);
    mat4_print(mat4_res);

    printf("\n\nmat4_scale((1.0f, 2.0f, 2.0f)^T)\n");
    mat4_res = mat4_scale(vec3_3f(1.0f, 2.0f, 2.0f));
    mat4_print(mat4_res);

    printf("\n\nmat4_translate((1.0f, 2.0f, 0.0f)^T)\n");
    mat4_res = mat4_translate(vec3_3f(1.0f, 2.0f, 0.0f));
    mat4_print(mat4_res);

    printf("\n\nmat4_frustum(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f)\n");
    mat4_res = mat4_frustum(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);
    mat4_print(mat4_res);

    printf("\n\nmat4_ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f)\n");
    mat4_res = mat4_ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);
    mat4_print(mat4_res);

    printf("\n\nmat4_perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f)\n");
    mat4_res = mat4_perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    mat4_print(mat4_res);
    printf("\n");

    return 0;
}
