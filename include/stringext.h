/**
 *   stringEXT - string.h extended
 *   Developed by Christian Visintin
 * 
 * MIT License
 * Copyright (c) 2018 Christian Visintin
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef STRINGEXT_H
#define STRINGEXT_H

#include <inttypes.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t strext_index_of(const char* haystack, const char* needle);
size_t strext_last_index_of(const char* haystack, const char* needle);

size_t strext_count(const char* haystack, const char* needle);

int strext_ends_with(const char* haystack, const char* needle);
int strext_starts_with(const char* haystack, const char* needle);

char* strext_replace(const char* str, const char* old_char, const char* new_char, size_t* str_size);
char* strext_replace_all(const char* str, const char* old_char, const char* new_char, size_t* str_size);

char* strext_substr(const char* str, const size_t s_index, const size_t count, size_t* str_size);
char* strext_substring(const char* str, const size_t s_index, const size_t e_index, size_t* str_size);

char* strext_to_lower_case(const char* str, size_t* str_size);
char* strext_to_upper_case(const char* str, size_t* str_size);

char* strext_reverse(const char* str, size_t* str_size);
int strext_is_palindrome(const char* str);

char** strext_strsplit(int* tokenCount, char* haystack, char* delimiter);
char* strext_strjoin(char** tokens, int tokenCount, char* delimiter);

char* strext_ltrim(char* str);
char* strext_rtrim(char* str);
char* strext_trim(char* str);

char* strext_justify_left(char* str, int width, char fillChar);
char* strext_justify_center(char* str, int width, char fillChar);
char* strext_justify_right(char* str, int width, char fillChar);

uint8_t* strext_hexlify(const char* str, size_t* length);
char* strext_unhexlify(const uint8_t* data, size_t* length);

#ifdef __cplusplus
}
#endif

#endif // STRINGEXT_H
