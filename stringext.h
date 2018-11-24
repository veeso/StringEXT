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

int indexOf(char* haystack, char* needle);
int lastIndexOf(char* haystack, char* needle);

int count(char* haystack, char* needle);

char* concat(char* destination, char* toConcat);

int endsWith(char* haystack, char* needle);
int startsWith(char* haystack, char* needle);

char* replace(char* str, char* oldChar, char* newChar);
char* replaceAll(char* str, char* oldChar, char* newChar);

char* substr(char* str, int beginIndex, int count);
char* substring(char* str, int beginIndex, int endIndex);

char* toLowerCase(char* str);
char* toUpperCase(char* str);

char* reverse(char* str);
int isPalindrome(char* str);

char** strsplit(int* tokenCount, char* haystack, char* delimiter);
char* strjoin(char** tokens, int tokenCount, char* delimiter);

char* ltrim(char* str);
char* rtrim(char* str);
char* trim(char* str);

char* ljust(char* str, int width, char fillChar);
char* cjust(char* str, int width, char fillChar);
char* rjust(char* str, int width, char fillChar);

int asciiToHex(uint8_t* dest, char* str);
char* hexToAscii(char* dest, uint8_t* bytes, size_t len);

#ifdef __cplusplus
}
#endif

#endif
