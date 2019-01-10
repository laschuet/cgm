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
#ifndef TEST_H_INCLUDE
#define TEST_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef TEST_STATIC
#define TEST_LINKAGE static
#else
#define TEST_LINKAGE
#endif // TEST_STATIC

#include "../cgm/cgm.h"

#define TEST_SCALAR_EQUAL(name, s, t) \
    test_scalar_equal(__FILE__, __LINE__, __func__, name, s, t)

#define TEST_VEC2_EQUAL(name, v, x, y) \
    test_vec2_equal(__FILE__, __LINE__, __func__, name, v, x, y)

#define TEST_VEC3_EQUAL(name, v, x, y, z) \
    test_vec3_equal(__FILE__, __LINE__, __func__, name, v, x, y, z)

#define TEST_VEC4_EQUAL(name, v, x, y, z, w) \
    test_vec4_equal(__FILE__, __LINE__, __func__, name, v, x, y, z, w)


TEST_LINKAGE void test_scalar_equal(const char *file, const int line,
                                    const char *func, const char *name,
                                    float s, float t);
TEST_LINKAGE void test_vec2_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec2 v, float x, float y);
TEST_LINKAGE void test_vec3_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec3 v, float x, float y, float z);
TEST_LINKAGE void test_vec4_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec4 v, float x, float y, float z, float w);

TEST_LINKAGE void __test_print_failed(const char *file, const int line,
                                    const char *func, const char *name);
TEST_LINKAGE void __test_print_passed(const char *name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TEST_H_INCLUDE

#ifdef TEST_IMPLEMENTATION
#undef TEST_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
TEST_LINKAGE void test_scalar_equal(const char *file, const int line,
                                    const char *func, const char *name,
                                    float s, float t)
{
    if (s != t) {
        __test_print_failed(file, line, func, name);
    } else {
        __test_print_passed(name);
    }
}

// -----------------------------------------------------------------------------
TEST_LINKAGE void test_vec2_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec2 v, float x, float y)
{
    if (v.x != x || v.y != y) {
        __test_print_failed(file, line, func, name);
    } else {
        __test_print_passed(name);
    }
}

// -----------------------------------------------------------------------------
TEST_LINKAGE void test_vec3_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec3 v, float x, float y, float z)
{
    if (v.x != x || v.y != y || v.z != z) {
        __test_print_failed(file, line, func, name);
    } else {
        __test_print_passed(name);
    }
}

// -----------------------------------------------------------------------------
TEST_LINKAGE void test_vec4_equal(const char *file, const int line,
                                const char *func, const char *name,
                                vec4 v, float x, float y, float z, float w)
{
    if (v.x != x || v.y != y || v.z != z || v.w != w) {
        __test_print_failed(file, line, func, name);
    } else {
        __test_print_passed(name);
    }
}

// -----------------------------------------------------------------------------
TEST_LINKAGE void __test_print_failed(const char *file, const int line,
                                    const char *func, const char *name)
{
    fprintf(stderr, "Testing %s...Failed\n", name);
    fprintf(stderr, "ERROR: There was an error during testing\n");
    fprintf(stderr, " in %s() at ./%s:%d\n", func, file, line);
}

// -----------------------------------------------------------------------------
TEST_LINKAGE void __test_print_passed(const char *name)
{
    fprintf(stdout, "Testing %s...Passed\n", name);
}

#endif // TEST_IMPLEMENTATION
