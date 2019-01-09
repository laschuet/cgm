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
#include <stdio.h>

#define CGM_IMPLEMENTATION
#include "../cgm/cgm.h"

int main()
{
    vec3 vec3_res;

    printf("vec3_3f(0.0f, 1.0f, 2.0f)\n");
    vec3_res = vec3_3f(0.0f, 1.0f, 2.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_vec2_f((0.0f, 1.0f)', 2.0f)\n");
    vec3_res = vec3_vec2_f(vec2_2f(0.0f, 1.0f), 2.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_vec3((0.0f, 1.0f, 2.0f)')\n");
    vec3_res = vec3_vec3(vec3_3f(0.0f, 1.0f, 2.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_vec4((0.0f, 1.0f, 2.0f, 3.0f)')\n");
    vec3_res = vec3_vec4(vec4_4f(0.0f, 1.0f, 2.0f, 3.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_add_f((0.0f, 0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec3_res = vec3_add_f(vec3_3f(0.0f, 0.0f, 0.0f), 1.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_add_vec3((0.0f, 0.0f, 0.0f)', (1.0f, 1.0f, 1.0f)')\n");
    vec3_res =
        vec3_add_vec3(vec3_3f(0.0f, 0.0f, 0.0f), vec3_3f(1.0f, 1.0f, 1.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_div_f((1.0f, 2.0f, 3.0f)', %.4f)\n", 2.0f);
    vec3_res = vec3_div_f(vec3_3f(1.0f, 2.0f, 3.0f), 2.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_div_vec3((1.0f, 1.0f, 1.0f)', (2.0f, 2.0f, 2.0f)')\n");
    vec3_res =
        vec3_div_vec3(vec3_3f(1.0f, 1.0f, 1.0f), vec3_3f(2.0f, 2.0f, 2.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_mul_f((1.0f, 2.0f, 3.0f)', %.4f)\n", 2.0f);
    vec3_res = vec3_mul_f(vec3_3f(1.0f, 2.0f, 3.0f), 2.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_mul_vec3((0.0f, 0.0f, 0.0f)', (1.0f, 1.0f, 1.0f)')\n");
    vec3_res =
        vec3_mul_vec3(vec3_3f(0.0f, 0.0f, 0.0f), vec3_3f(1.0f, 1.0f, 1.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_sub_f((0.0f, 0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec3_res = vec3_sub_f(vec3_3f(0.0f, 0.0f, 0.0f), 1.0f);
    vec3_print(vec3_res);

    printf("\n\nvec3_sub_vec3((0.0f, 0.0f, 0.0f)', (1.0f, 1.0f, 1.0f)')\n");
    vec3_res =
        vec3_sub_vec3(vec3_3f(0.0f, 0.0f, 0.0f), vec3_3f(1.0f, 1.0f, 1.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_cross_vec3((1.0f, 0.0f, 0.0f)', (0.0f, 1.0f, 0.0f)')\n");
    vec3_res =
        vec3_cross_vec3(vec3_3f(1.0f, 0.0f, 0.0f), vec3_3f(0.0f, 1.0f, 0.0f));
    vec3_print(vec3_res);

    printf("\n\nvec3_dot_vec3((1.0f, 2.0f, 3.0f)', (1.0f, 2.0f, 3.0f)')\n");
    float dot =
        vec3_dot_vec3(vec3_3f(1.0f, 2.0f, 3.0f), vec3_3f(1.0f, 2.0f, 3.0f));
    printf("%f\n", dot);

    printf("\nvec3_length((1.0f, 2.0f, 3.0f)')\n");
    float length = vec3_length(vec3_3f(1.0f, 2.0f, 3.0f));
    printf("%f\n", length);

    printf("\nvec3_sq_length((1.0f, 2.0f, 3.0f)')\n");
    float sq_length = vec3_sq_length(vec3_3f(1.0f, 2.0f, 3.0f));
    printf("%f\n", sq_length);

    printf("\nvec3_normalize((1.0f, 2.0f, 3.0f)')\n");
    vec3_res = vec3_normalize(vec3_3f(1.0f, 2.0f, 3.0f));
    vec3_print(vec3_res);
    printf("\n");

    return 0;
}
