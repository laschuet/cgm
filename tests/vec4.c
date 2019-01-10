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
    vec4 v;

    v = vec4_4f(0.0f, 1.0f, 2.0f, 3.0f);
    TEST_VEC4_EQUAL("vec4_4f", v, 0.0f, 1.0f, 2.0f, 3.0f);

    v = vec4_vec2_2f(vec2_2f(0.0f, 1.0f), 2.0f, 3.0f);
    TEST_VEC4_EQUAL("vec4_vec2_2f", v, 0.0f, 1.0f, 2.0f, 3.0f);

    v = vec4_vec3_f(vec3_3f(0.0f, 1.0f, 2.0f), 3.0f);
    TEST_VEC4_EQUAL("vev4_vec3_f", v, 0.0f, 1.0f, 2.0f, 3.0f);

    v = vec4_vec4(vec4_4f(0.0f, 1.0f, 2.0f, 3.0f));
    TEST_VEC4_EQUAL("vec4_vec4", v, 0.0f, 1.0f, 2.0f, 3.0f);

    vec4 a = vec4_4f(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b = vec4_4f(4.0f, 4.0f, 4.0f, 4.0f);
    vec4 c = vec4_4f(0.0f, 0.0f, 0.0f, 1.0f);

    v = vec4_add_f(a, 1.0f);
    TEST_VEC4_EQUAL("vec4_add_f", v, 2.0f, 3.0f, 4.0f, 5.0f);

    v = vec4_add_vec4(a, b);
    TEST_VEC4_EQUAL("vec4_add_vec4", v, 5.0f, 6.0f, 7.0f, 8.0f);

    v = vec4_div_f(a, 2.0f);
    TEST_VEC4_EQUAL("vec4_div_f", v, 0.5f, 1.0f, 1.5f, 2.0f);

    v = vec4_div_vec4(a, b);
    TEST_VEC4_EQUAL("vec4_div_vec4", v, 0.25f, 0.5f, 0.75f, 1.0f);

    v = vec4_mul_f(a, 2.0f);
    TEST_VEC4_EQUAL("vec4_mul_f", v, 2.0f, 4.0f, 6.0f, 8.0f);

    v = vec4_mul_vec4(a, b);
    TEST_VEC4_EQUAL("vec4_mul_vec4", v, 4.0f, 8.0f, 12.0f, 16.0f);

    v = vec4_sub_f(a, 1.0f);
    TEST_VEC4_EQUAL("vec4_sub_f", v, 0.0f, 1.0f, 2.0f, 3.0f);

    v = vec4_sub_vec4(a, b);
    TEST_VEC4_EQUAL("vec4_sub_vec4", v, -3.0f, -2.0f, -1.0f, 0.0f);

    float dot = vec4_dot_vec4(a, b);
    TEST_SCALAR_EQUAL("vec4_dot_vec4", dot, 40.0f);

    float length = vec4_length(c);
    TEST_SCALAR_EQUAL("vec4_length", length, 1.0f);

    float sq_length = vec4_sq_length(a);
    TEST_SCALAR_EQUAL("vec4_sq_length", sq_length, 30.0f);

    v = vec4_normalize(c);
    TEST_SCALAR_EQUAL("vec4_normalize", vec4_length(v), 1.0f);
    TEST_VEC4_EQUAL("vec4_normalize", v, 0.0f, 0.0f, 0.0f, 1.0f);

    return 0;
}
