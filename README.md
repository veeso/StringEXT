# libStringEXT

[![License: MIT](https://img.shields.io/badge/License-MIT-teal.svg)](https://opensource.org/licenses/MIT) [![Stars](https://img.shields.io/github/stars/ChristianVisintin/StringEXT.svg)](https://github.com/ChristianVisintin/StringEXT) [![Issues](https://img.shields.io/github/issues/ChristianVisintin/StringEXT.svg)](https://github.com/ChristianVisintin/StringEXT/issues) [![Build](https://api.travis-ci.org/ChristianVisintin/StringEXT.svg?branch=master)](https://travis-ci.org/ChristianVisintin/StringEXT)

C string enhancement ~ Developed by Christian Visintin

Current Version: 1.0.0 - 2020/08/??

---

- [libStringEXT](#libstringext)
  - [Introduction](#introduction)
  - [Build](#build)
    - [Autotools](#autotools)
    - [CMake](#cmake)
  - [Functions](#functions)
    - [indexOf](#indexof)
    - [lastIndexOf](#lastindexof)
    - [count](#count)
    - [concat](#concat)
    - [endsWith](#endswith)
    - [startsWith](#startswith)
    - [replace](#replace)
    - [replaceAll](#replaceall)
    - [substr](#substr)
    - [substring](#substring)
    - [toLowerCase](#tolowercase)
    - [toUpperCase](#touppercase)
    - [reverse](#reverse)
    - [isPalindrome](#ispalindrome)
    - [strsplit](#strsplit)
    - [strjoin](#strjoin)
    - [ltrim](#ltrim)
    - [rtrim](#rtrim)
    - [trim](#trim)
    - [ljust](#ljust)
    - [cjust](#cjust)
    - [rjust](#rjust)
    - [asciiToHex](#asciitohex)
    - [hexToAscii](#hextoascii)
  - [Contributions](#contributions)
  - [Changelog](#changelog)
  - [License](#license)

---

## Introduction

StringEXT is a library which extends string.h introducing a lot of functions missing in standard string C library.

## Build

It is possible to build libStringext with both autotools and CMake

### Autotools

```sh
./autogen.sh
./configure
make
make install
```

### CMake

```sh
mkdir -p build/ && cd build/
cmake ..
make
make install
```

## Functions

### indexOf

Returns the index of needle in haystack.
Returns -1 if needle is not found.

```C
int indexOf(char* haystack, char* needle);
```

### lastIndexOf

Returns the index of the last occurrence of needle in haystack.  
Returns -1 if needle is not found.

```C
int lastIndexOf(char* haystack, char* needle);
```

### count

Count occurrences of needle in haystack.  
Returns the occurrences of needle in haystack.

```C
int count(char* haystack, char* needle);
```

### concat

Concatenate to destination toConcat.  
Destination will be reallocated.  
The only difference with strcat is the fact that destination gets reallocated inside the function.  
Returns a pointer to destination.

```C
char* concat(char* destination, char* toConcat);
```

### endsWith

Tests whether haystacks ends with needle.  
Returns 0 if haystack ends with needle.

```C
int endsWith(char* haystack, char* needle);
```

### startsWith

Tests whether haystacks starts with needle.  
Returns 0 if haystack starts with needle.

```C
int startsWith(char* haystack, char* needle);
```

### replace

Replace the first occurrence of oldChar with newChar in str  
str will be reallocated if needed.  
Be aware that oldChar and newChar can be a string too  
Returns a pointer to str.

```C
char* replace(char* str, char* oldChar, char* newChar);
```

### replaceAll

Replace all the occurrences of oldChar with newChar in str  
str will be reallocated if needed.  
Be aware that oldChar and newChar can be a string too  
Returns a pointer to str.

```C
char* replaceAll(char* str, char* oldChar, char* newChar);
```

### substr

Returns a new string that is a substring of str. The new string is made up of the character of str from beginIndex for count characters.  

```C
char* substr(char* str, int beginIndex, int count);
```

### substring

Returns a new string that is a substring of str. The new string is made up of the character of str between beginIndex and endIndex.  

```C
char* substring(char* str, int beginIndex, int endIndex);
```

### toLowerCase

Converts all of the characters in this String to lower case using the rules of the default locale.  
Returns a pointer to str

```C
char* toLowerCase(char* str);
```

### toUpperCase

Converts all of the characters in this String to upper case using the rules of the default locale.  
Returns a pointer to str

```C
char* toUpperCase(char* str);
```

### reverse

Reverse the content of a string.  
Returns a pointer to str.

```C
char* reverse(char* str);
```

### isPalindrome

Check if the provided string is a Palindrome.  
Returns 0 if the provided string is a palindrome

```C
int isPalindrome(char* str);
```

### strsplit

Split the provided string into tokens.  
Delimiter is passed as argument.  
Returns a char array of pointers, each position contains a token.

```C
//NOTE: to access token => *(tokens + index)
//NOTE: to free token array => free(*(tokens + index)); for each index, and eventually free(tokens);
//Yes, we all know about strtok; feel free not to use this function indeed
char** strsplit(int* tokenCount, char* haystack, char* delimiter);
```

### strjoin

Joins a series of char tokens into a single string, delimiting them with a value passed to the function.  
Returns a pointer to the joined string.

```C
char* strjoin(char** tokens, int tokenCount, char* delimiter);
```

### ltrim

Removes leading whitespaces omitted from the provided string.  
String will be reallocated to preserve space if needed.  
Returns a pointer to the reallocated string

```C
char* ltrim(char* str);
```

### rtrim

Removes trailing whitespaces omitted from the provided string.  
String will be reallocated to preserve space if needed.  
Returns a pointer to the reallocated string

```C
char* rtrim(char* str);
```

### trim

Removes leading and trailing whitespaces omitted from the provided string.  
String will be reallocated to preserve space if needed.  
Returns a pointer to the reallocated string

```C
char* trim(char* str);
```

### ljust

Justify the text to the left of its box, which size is defined as a parameter (width).  
Empty spaces are filled with the character passed to the function.  
If the length of the string passed to the function is greater or equal to width, the function will just return a pointer to the passed string.  
Returns a pointer to the reallocated string.

```C
char* ljust(char* str, int width, char fillChar);
```

### cjust

Justify the text to the center of its box, which size is defined as a parameter (width).  
Empty spaces are filled with the character passed to the function.  
If the length of the string passed to the function is greater or equal to width, the function will just return a pointer to the passed string.  
If the difference between the width provided and the length of the string is an odd number, left justify is preferred.  
Returns a pointer to the reallocated string.

```C
char* cjust(char* str, int width, char fillChar);
```

### rjust

Justify the text to the right of its box, which size is defined as a parameter (width).  
Empty spaces are filled with the character passed to the function.  
If the length of the string passed to the function is greater or equal to width, the function will just return a pointer to the passed string.  
Returns a pointer to the reallocated string.

```C
char* rjust(char* str, int width, char fillChar);
```

### asciiToHex

Given a string representing a series of hex values in ASCII, it returns real hex values (e.g. if "01ABEF" is provided, the function will return in dest [0x01, 0xAB, 0xEF])  
If a character of str is not an hex representation it will be conveted to 0.  
str must be NULL terminated.  
Returns the destination length

```C
int asciiToHex(uint8_t* dest, char* str);
```

### hexToAscii

Converts a hex buffer to its ASCII representation (e.g. if [0x01, 0xAB, 0xEF] is provided as argument, the function will return "01ABEF").  

```C
char* hexToAscii(char* dest, uint8_t* bytes, size_t len);
```

## Contributions

Everybody can contribute to this library, indeed any improvement will be appreciated.

---

## Changelog

View [CHANGELOG](CHANGELOG.md)

---

## License

View [LICENSE](LICENSE)
