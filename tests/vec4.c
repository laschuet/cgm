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
    vec4 vec4_res;

    printf("vec4_4f(0.0f, 1.0f, 2.0f, 3.0f)\n");
    vec4_res = vec4_4f(0.0f, 1.0f, 2.0f, 3.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_vec2_2f((0.0f, 1.0f)', 2.0f, 3.0f)\n");
    vec4_res = vec4_vec2_2f(vec2_2f(0.0f, 1.0f), 2.0f, 3.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_vec3_f((0.0f, 1.0f, 2.0f)', 3.0f)\n");
    vec4_res = vec4_vec3_f(vec3_3f(0.0f, 1.0f, 2.0f), 3.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_vec4((0.0f, 1.0f, 2.0f, 3.0f)')\n");
    vec4_res = vec4_vec4(vec4_4f(0.0f, 1.0f, 2.0f, 3.0f));
    vec4_print(vec4_res);

    printf("\n\nvec4_add_f((0.0f, 0.0f, 0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec4_res = vec4_add_f(vec4_4f(0.0f, 0.0f, 0.0f, 0.0f), 1.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_add_vec4((0.0f, 0.0f, 0.0f, 0.0f)', (1.0f, 1.0f, 1.0f, 1.0f)')\n");
    vec4_res =
        vec4_add_vec4(vec4_4f(0.0f, 0.0f, 0.0f, 0.0f),
                    vec4_4f(1.0f, 1.0f, 1.0f, 1.0f));
    vec4_print(vec4_res);

    printf("\n\nvec4_div_f((1.0f, 2.0f, 3.0f, 4.0f)', %.4f)\n", 2.0f);
    vec4_res = vec4_div_f(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f), 2.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_div_vec4((1.0f, 1.0f, 1.0f, 1.0f)', (2.0f, 2.0f, 2.0f, 2.0f)')\n");
    vec4_res =
        vec4_div_vec4(vec4_4f(1.0f, 1.0f, 1.0f, 1.0f),
                    vec4_4f(2.0f, 2.0f, 2.0f, 2.0f));
    vec4_print(vec4_res);

    printf("\n\nvec4_mul_f((1.0f, 2.0f, 3.0f, 4.0f)', %.4f)\n", 2.0f);
    vec4_res = vec4_mul_f(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f), 2.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_mul_vec4((0, 0, 0, 0)', (1, 1, 1, 1)')\n");
    vec4_res = vec4_mul_vec4(vec4_4f(0, 0, 0, 0), vec4_4f(1, 1, 1, 1));
    vec4_print(vec4_res);

    printf("\n\nvec4_sub_f((0.0f, 0.0f, 0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec4_res = vec4_sub_f(vec4_4f(0.0f, 0.0f, 0.0f, 0.0f), 1.0f);
    vec4_print(vec4_res);

    printf("\n\nvec4_sub_vec4((0.0f, 0.0f, 0.0f, 0.0f)', (1.0f, 1.0f, 1.0f, 1.0f)')\n");
    vec4_res =
        vec4_sub_vec4(vec4_4f(0.0f, 0.0f, 0.0f, 0.0f),
                    vec4_4f(1.0f, 1.0f, 1.0f, 1.0f));
    vec4_print(vec4_res);

    printf("\n\nvec4_cross_vec4((1.0f, 0.0f, 0.0f, 1.0f)', (0.0f, 1.0f, 0.0f, 1.0f)')\n");
    vec4_res =
        vec4_cross_vec4(vec4_4f(1.0f, 0.0f, 0.0f, 1.0f),
                    vec4_4f(0.0f, 1.0f, 0.0f, 1.0f));
    vec4_print(vec4_res);

    printf("\n\nvec4_dot_vec4((1.0f, 2.0f, 3.0f, 4.0f)', (1.0f, 2.0f, 3.0f, 4.0f)')\n");
    float dot =
        vec4_dot_vec4(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f),
                    vec4_4f(1.0f, 2.0f, 3.0f, 4.0f));
    printf("%f\n", dot);

    printf("\nvec4_length((1.0f, 2.0f, 3.0f, 4.0f)')\n");
    float length = vec4_length(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f));
    printf("%f\n", length);

    printf("\nvec4_sq_length((1.0f, 2.0f, 3.0f, 4.0f)')\n");
    float sq_length = vec4_sq_length(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f));
    printf("%f\n", sq_length);

    printf("\nvec4_normalize((1.0f, 2.0f, 3.0f, 4.0f)')\n");
    vec4_res = vec4_normalize(vec4_4f(1.0f, 2.0f, 3.0f, 4.0f));
    vec4_print(vec4_res);
    printf("\n");

    return 0;
}
