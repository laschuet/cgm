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
    vec2 vec2_res;

    printf("vec2_2f(0.0f, 1.0f)\n");
    vec2_res = vec2_2f(0.0f, 1.0f);
    vec2_print(vec2_res);

    printf("\n\nvec2_vec2((0.0f, 1.0f)')\n");
    vec2_res = vec2_vec2(vec2_2f(0.0f, 1.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_vec3((0.0f, 1.0f, 2.0f)')\n");
    vec2_res = vec2_vec3(vec3_3f(0.0f, 1.0f, 2.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_vec4((0.0f, 1.0f, 2.0f, 3.0f)')\n");
    vec2_res = vec2_vec4(vec4_4f(0.0f, 1.0f, 2.0f, 3.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_add_f((0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec2_res = vec2_add_f(vec2_2f(0.0f, 0.0f), 1.0f);
    vec2_print(vec2_res);

    printf("\n\nvec2_add_vec2((0.0f, 0.0f)', (1.0f, 1.0f)')\n");
    vec2_res = vec2_add_vec2(vec2_2f(0.0f, 0.0f), vec2_2f(1.0f, 1.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_div_f((1.0f, 2.0f)', %.4f)\n", 2.0f);
    vec2_res = vec2_div_f(vec2_2f(1.0f, 2.0f), 2.0f);
    vec2_print(vec2_res);

    printf("\n\nvec2_div_vec2((1.0f, 1.0f)', (2.0f, 2.0f)')\n");
    vec2_res = vec2_div_vec2(vec2_2f(1.0f, 1.0f), vec2_2f(2.0f, 2.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_mul_f((1.0f, 2.0f)', %.4f)\n", 2.0f);
    vec2_res = vec2_mul_f(vec2_2f(1.0f, 2.0f), 2.0f);
    vec2_print(vec2_res);

    printf("\n\nvec2_mul_vec2((0.0f, 0.0f)', (1.0f, 1.0f)')\n");
    vec2_res = vec2_mul_vec2(vec2_2f(0.0f, 0.0f), vec2_2f(1.0f, 1.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_sub_f((0.0f, 0.0f)', %.4f)\n", 1.0f);
    vec2_res = vec2_sub_f(vec2_2f(0.0f, 0.0f), 1.0f);
    vec2_print(vec2_res);

    printf("\n\nvec2_sub_vec2((0.0f, 0.0f)', (1.0f, 1.0f)')\n");
    vec2_res = vec2_sub_vec2(vec2_2f(0.0f, 0.0f), vec2_2f(1.0f, 1.0f));
    vec2_print(vec2_res);

    printf("\n\nvec2_dot_vec2((1.0f, 2.0f)', (1.0f, 2.0f)')\n");
    float dot = vec2_dot_vec2(vec2_2f(1.0f, 2.0f), vec2_2f(1.0f, 2.0f));
    printf("%f\n", dot);

    printf("\nvec2_length((1.0f, 2.0f)')\n");
    float length = vec2_length(vec2_2f(1.0f, 2.0f));
    printf("%f\n", length);

    printf("\nvec2_sq_length((1.0f, 2.0f)')\n");
    float sq_length = vec2_sq_length(vec2_2f(1.0f, 2.0f));
    printf("%f\n", sq_length);

    printf("\nvec2_normalize((1.0f, 2.0f)')\n");
    vec2_res = vec2_normalize(vec2_2f(1.0f, 2.0f));
    vec2_print(vec2_res);
    printf("\n");

    return 0;
}
