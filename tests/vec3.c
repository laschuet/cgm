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
#define CGM_IMPLEMENTATION
#include "../cgm/cgm.h"

#define TEST_IMPLEMENTATION
#include "test.h"

int main()
{
    vec3 v;

    v = vec3_3f(0.0f, 1.0f, 2.0f);
    TEST_VEC3_EQUAL("vec3_3f", v, 0.0f, 1.0f, 2.0f);

    v = vec3_vec2_f(vec2_2f(0.0f, 1.0f), 2.0f);
    TEST_VEC3_EQUAL("vec3_vec2_f", v, 0.0f, 1.0f, 2.0f);

    v = vec3_vec3(vec3_3f(0.0f, 1.0f, 2.0f));
    TEST_VEC3_EQUAL("vec3_vec3", v, 0.0f, 1.0f, 2.0f);

    v = vec3_vec4(vec4_4f(0.0f, 1.0f, 2.0f, 3.0f));
    TEST_VEC3_EQUAL("vec3_vec4", v, 0.0f, 1.0f, 2.0f);

    vec3 a = vec3_3f(1.0f, 2.0f, 3.0f);
    vec3 b = vec3_3f(4.0f, 4.0f, 4.0f);
    vec3 c = vec3_3f(0.0f, 0.0f, 1.0f);

    v = vec3_add_f(a, 1.0f);
    TEST_VEC3_EQUAL("vec3_add_f", v, 2.0f, 3.0f, 4.0f);

    v = vec3_add_vec3(a, b);
    TEST_VEC3_EQUAL("vec3_add_vec3", v, 5.0f, 6.0f, 7.0f);

    v = vec3_div_f(a, 2.0f);
    TEST_VEC3_EQUAL("vec3_div_f", v, 0.5f, 1.0f, 1.5f);

    v = vec3_div_vec3(a, b);
    TEST_VEC3_EQUAL("vec3_div_vec3", v, 0.25f, 0.5f, 0.75f);

    v = vec3_mul_f(a, 2.0f);
    TEST_VEC3_EQUAL("vec3_mul_f", v, 2.0f, 4.0f, 6.0f);

    v = vec3_mul_vec3(a, b);
    TEST_VEC3_EQUAL("vec3_mul_vec3", v, 4.0f, 8.0f, 12.0f);

    v = vec3_sub_f(a, 1.0f);
    TEST_VEC3_EQUAL("vec3_sub_f", v, 0.0f, 1.0f, 2.0f);

    v = vec3_sub_vec3(a, b);
    TEST_VEC3_EQUAL("vec3_sub_vec3", v, -3.0f, -2.0f, -1.0f);

    v = vec3_cross_vec3(a, b);
    TEST_VEC3_EQUAL("vec3_cross_vec3", v, -4.0f, 8.0f, -4.0f);

    float dot = vec3_dot_vec3(a, b);
    TEST_SCALAR_EQUAL("vec3_dot_vec3", dot, 24.0f);

    float length = vec3_length(c);
    TEST_SCALAR_EQUAL("vec3_length", length, 1.0f);

    float sq_length = vec3_sq_length(a);
    TEST_SCALAR_EQUAL("vec3_sq_length", sq_length, 14.0f);

    v = vec3_normalize(c);
    TEST_SCALAR_EQUAL("vec3_normalize", vec3_length(v), 1.0f);
    TEST_VEC3_EQUAL("vec3_normalize", v, 0.0f, 0.0f, 1.0f);

    return 0;
}
