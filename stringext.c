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

#include "stringext.h"

#include <ctype.h>
#include <stdlib.h>

/**
 * Returns the index of needle in haystack
 * @param char*: string to search in
 * @param char*: string to search for
 * @return: index of the first letter of needle in haystack. -1 if not found
**/

int indexOf(char* haystack, char* needle) {
  const char* ptr = strstr(haystack, needle);
  if (ptr == NULL)
    return -1;
  else
    return ptr - haystack;
}

/**
 * Returns the index of the last occurrence of needle in haystack
 * @param char*: string to search in
 * @param char*: string to search for
 * @return: index of the first letter of the last occurrence of needle in haystack. -1 if not found
**/

int lastIndexOf(char* haystack, char* needle) {
  int lastIndex = -1;
  int tmpIndex = -1;
  do {
    tmpIndex = indexOf(haystack + tmpIndex + 1, needle);
    if (tmpIndex != -1) {
      lastIndex += tmpIndex + 1;
      tmpIndex = lastIndex;
    }
  } while (tmpIndex != -1);
  return lastIndex;
}

/**
 * Count occurrences of needle in haystack
 * @param char*: char array to count occurrences in
 * @param char*: char array to find in haystack
 * @return int: amount of occurrences of haystack in needle
 **/

int count(char* haystack, char* needle) {

  int occurrences = 0;
  int index = 0;
  int pos = 0;
  while ((index = indexOf(haystack + pos, needle)) != -1) {
    occurrences++; //Increment occurrences
    index++;       //Increment index, otherwise will loops on the same index
    pos += index;  //Increment pos of index
  }

  return occurrences;
}

/**
 * Concatenate to destination toConcat. NOTE: destination will be reallocated
 * @param char* destination: string where all strings will be stored
 * @param size_t: current destination length
 * @param char*: string to concatenate to destination
 * @param size_t: length of string to concatenate
 * @return char*: pointer to destination
**/

char* concat(char* destination, char* toConcat) {

  size_t destLength = strlen(destination);
  size_t toConcatLength = strlen(toConcat);

  destination = (char*)realloc(destination, sizeof(char) * (destLength + toConcatLength + 1));
  if (destination == NULL) {
    return NULL;
  }
  memcpy(destination + destLength, toConcat, toConcatLength);
  destination[destLength + toConcatLength] = 0x00;
  return destination;
}

/**
 * Tests whether haystacks ends with needle
 * @param char*: string to check if ends with needle
 * @param char*: string to check if is at the end of needle
 * @return int: 0 if haystack ends with needle
**/

int endsWith(char* haystack, char* needle) {
  return strcmp(haystack + (strlen(haystack) - strlen(needle)), needle);
}

/**
 * Tests whether haystacks starts with needle
 * @param char*: string to check if starts with needle
 * @param char*: string to check if is at the begin of needle
 * @return int: 0 if haystack starts with needle
**/

int startsWith(char* haystack, char* needle) {
  return strncmp(haystack, needle, strlen(needle));
}

/**
 * Replace once oldChar with newChar in str NOTE: str will be reallocated
 * @param char*: string to apply the replacement
 * @param char*: string to replace
 * @param char*: string that will replace oldChar
 * @return char*: pointer to destination string
**/

char* replace(char* str, char* oldChar, char* newChar) {

  size_t newSize = strlen(str);
  //Calc new size for reallocation
  if (strlen(newChar) > strlen(oldChar)) {
    newSize = strlen(str) + (strlen(newChar) - strlen(oldChar));
  } else if (strlen(newChar) < strlen(oldChar)) {
    newSize = strlen(str) - (strlen(oldChar) - strlen(newChar));
  }
  //Check if str has to be reallocated
  if (newSize > 0) {
    str = (char*)realloc(str, newSize + 1);
    if (str == NULL) {
      return NULL;
    }
  }
  //Get index of old char
  int indexOldChar = indexOf(str, oldChar);
  if (indexOldChar != -1) {
    //Move content forward of n positions
    memcpy(str + indexOldChar + strlen(newChar), str + indexOldChar + strlen(oldChar), strlen(str) - (indexOldChar + strlen(oldChar)));
    memcpy(str + indexOldChar, newChar, strlen(newChar));
  }
  //NULL terminator
  str[newSize] = 0x00;
  return str;
}

/**
 * Replace all occurrence of oldChar with newChar in str
 * @param char*: string replacement will be applied to
 * @param char*: string to replace
 * @param char*: string that will replace oldChar
 * @return char*: pointer to destination string
**/

char* replaceAll(char* str, char* oldChar, char* newChar) {

  while (indexOf(str, oldChar) != -1 && str != NULL)
    str = replace(str, oldChar, newChar);
  return str;
}

/**
 * Returns a new string that is a substring of str. The new string is made up of the character of str from beginIndex for count characters
 * @param char*: string to take the substring from
 * @param int: The position where to start the extraction. First character is at index 0
 * @param int: Amount of characters to get starting from beginIndex
 * @return char*: pointer to new allocated string
**/

char* substr(char* str, int beginIndex, int count) {
  char* tmp = (char*)malloc(sizeof(char) * count + 1);
  if (tmp == NULL) {
    return NULL;
  }
  memcpy(tmp, str + beginIndex, count);
  tmp[count] = 0x00; //Null terminate the string
  return tmp;
}

/**
 * Returns a new string that is a substring of str. The new string is made up of the character of str between beginIndex and endIndex
 * @param char*: string to take the substring from
 * @param int: The position where to start the extraction. First character is at index 0
 * @param int: The position (up to, but not including) where to end the extraction.
 * @return char*: pointer to new allocated string
**/

char* substring(char* str, int beginIndex, int endIndex) {
  return substr(str, beginIndex, endIndex - beginIndex);
}

/**
 * Converts all of the characters in this String to lower case using the rules of the default locale.
 * @param char*: string to convert
 * @return pointer to str
**/

char* toLowerCase(char* str) {
  for (int i = 0; i < strlen(str); i++)
    str[i] = tolower(str[i]);
  return str;
}

/**
 * Converts all of the characters in this String to upper case using the rules of the default locale.
 * @param char*: string to convert
 * @return pointer to str
**/

char* toUpperCase(char* str) {
  for (int i = 0; i < strlen(str); i++)
    str[i] = toupper(str[i]);
  return str;
}

/**
 * Reverse a string
 * @param char*: string to reverse
 * @return char*: pointer to str
**/

char* reverse(char* str) {

  size_t strLength = strlen(str);
  char* wrkStr = (char*)malloc(sizeof(char) * strLength);
  if (wrkStr == NULL) {
    return NULL;
  }
  memcpy(wrkStr, str, strLength);
  for (int i = 0; i < strLength; i++) {
    str[i] = wrkStr[strLength - i - 1];
  }
  str[strLength] = 0x00;
  free(wrkStr);
  return str;
}

/**
 * Check if the provided string is a Palindrome
 * @param char*: string to check
 * @return int: 0 if it is a Palindrome
**/

int isPalindrome(char* str) {

  size_t strLength = strlen(str);
  int res;
  //Base case
  if (strLength < 2) {
    return 0;
  }
  //Recursive call
  if (str[0] == str[strLength - 1]) {
    char* wrkStr = (char*)malloc(sizeof(char) * strLength - 1);
    if (wrkStr == NULL) {
      return 1;
    }
    memcpy(wrkStr, str + 1, strLength - 2); //Copy str except first and last character
    wrkStr[strLength - 2] = 0x00; //Null terminate wrkStr
    res = isPalindrome(wrkStr);
    free(wrkStr);
  } else {
    res = 1;
  }

  return res;
}

/**
 * Split haystack into tokens
 * @param int*: will store number of tokens created
 * @param char*: the string to create tokens from, must be NULL terminated
 * @param char*: delimiter used to create tokens, delimiter won't be stored into tokens
 * @return char**: tokens, char array of pointers, each position contains a token
 * NOTE: to access token => *(tokens + index)
 * NOTE: to free token array => free(*(tokens + index)); for each index, and eventually free(tokens);
**/

char** strsplit(int* tokenCount, char* haystack, char* delimiter) {

  //Count occurrences of delimiter in str
  int occurrences = count(haystack, delimiter);
  *tokenCount = occurrences;
  //If haystack ends with delimiter tokens = occurrences, otherwise is occurrences + 1
  if (endsWith(haystack, delimiter) != 0) {
    (*tokenCount)++;
  }
  //Allocate tokens
  char** tokens = malloc(sizeof(char*) * *tokenCount);
  int indexPtr = 0;
  int currIndex = 0;
  for (int i = 0; i < occurrences; i++) {
    //Get token
    currIndex += indexPtr;
    indexPtr = indexOf(haystack + currIndex, delimiter);
    char* tok = substr(haystack + currIndex, 0, indexPtr);
    indexPtr++; //Ignore delimiter position
    //Store in ith position tok
    size_t tokLength = strlen(tok);
    *(tokens + i) = (char*)calloc(1, sizeof(char) * (tokLength + 1));
    if ((tokens + occurrences) == NULL) {
      return NULL;
    }
    memcpy(*(tokens + i), tok, tokLength);
    free(tok);
  }

  //Get last token if tokenCount > occurrences
  if (*tokenCount > occurrences) {
    //Last token is from lastIndexOf(delimiter) + 1 to its end; works also if string has no occurrences of delimiter in it
    char* tok = substring(haystack, lastIndexOf(haystack, delimiter) + 1, strlen(haystack));
    size_t tokLength = strlen(tok);
    *(tokens + occurrences) = (char*)calloc(1, sizeof(char) * (tokLength + 1));
    if ((tokens + occurrences) == NULL) {
      return NULL;
    }
    memcpy(*(tokens + occurrences), tok, tokLength);
    free(tok);
  }
  return tokens;
}

/**
 * Join into a single string a series of tokens, with a delimiter between each token
 * @param char** tokens: pointer to char pointers, where each pointer in tokens is a token
 * @param int: number of tokens in the array
 * @param char*: delimiter used to join all tokens
 * @return char*: pointer to char array which contains the joined tokens
**/

char* strjoin(char** tokens, int tokenCount, char* delimiter) {

  char* joined = NULL;
  size_t delimiterLength = strlen(delimiter);
  int ptrIndex = 0;

  //Iterate over all tokens (except the last)
  for (int i = 0; i < tokenCount - 1; i++) {
    //For each token get its content
    char* tokenStr = *(tokens + i);
    size_t tokenLength = strlen(tokenStr);
    joined = realloc(joined, sizeof(char) * (ptrIndex + tokenLength + delimiterLength + 1));
    if (joined == NULL) {
      return NULL;
    }
    memcpy(joined + ptrIndex, tokenStr, tokenLength);
    memcpy(joined + ptrIndex + tokenLength, delimiter, delimiterLength);
    ptrIndex += tokenLength + delimiterLength;
  }

  //Add last element, but without delimiter
  char* tokenStr = *(tokens + (tokenCount - 1));
  size_t tokenLength = strlen(tokenStr);
  joined = realloc(joined, sizeof(char) * (ptrIndex + tokenLength + 1));
  if (joined == NULL) {
    return NULL;
  }
  memcpy(joined + ptrIndex, tokenStr, tokenLength);
  ptrIndex += tokenLength;

  joined[ptrIndex] = 0x00;
  return joined;
}

/**
 * Removes leading whitespaces omitted from string.
 * @param char*: string to remove whitespaces from
 * @return char*: pointer to str
**/

char* ltrim(char* str) {
  //Count whitespaces at the left of the string
  int ptri = 0;
  while (str[ptri] == 0x20 && ptri < strlen(str))
    ptri++;
  size_t newSize = strlen(str) - ptri;
  char* tmpSrc = (char*)malloc(sizeof(char) * newSize);
  memcpy(tmpSrc, str + ptri, newSize);
  str = (char*)realloc(str, sizeof(char) * newSize + 1);
  if (str == NULL) {
    return NULL;
  }
  memcpy(str, tmpSrc, newSize);
  str[newSize] = 0x00;
  free(tmpSrc);
  return str;
}

/**
 * Removes trailing whitespaces omitted from string.
 * @param char*: string to remove whitespaces from
 * @return char*: pointer to str
**/

char* rtrim(char* str) {
  //Count whitespaces at the right of the string
  int ptri = strlen(str) - 1;
  int wCount = 0;
  while (str[ptri] == 0x20 && ptri >= 0) {
    ptri--;
    wCount++;
  }
  size_t newSize = strlen(str) - wCount;
  str = (char*)realloc(str, sizeof(char) * newSize + 1);
  if (str == NULL) {
    return NULL;
  }
  str[newSize] = 0x00;
  return str;
}

/**
 * Removes leading and trailing whitespaces omitted from string.
 * @param char*: string to remove whitespaces from
 * @return char*: pointer to str
**/

char* trim(char* str) {
  str = ltrim(str);
  str = rtrim(str);
  return str;
}

/**
 * Justify the text to the left of its box, which size is defined as width. 
 * Empty space is filled with the character passed to the function
 * NOTE: if the length of the string passed to the function is greater or equal to width,
 * the function will just return the passed string
 * @param char*: str to Justify
 * @param int: width
 * @param char: the character used to fill the empty space
 * @return char*: pointer to reallocated string. Check if NULL
**/

char* ljust(char* str, int width, char fillChar) {

  //If strLength is greater or equal to width, do nothing
  size_t strLength = strlen(str);
  if (strLength >= width) {
    return str;
  }

  //Realloc str with new size
  str = realloc(str, sizeof(char) * (width + 1));
  if (str == NULL) {
    return NULL;
  }
  //Add traling spaces
  memset(str + strLength, fillChar, width - strLength);
  str[width] = 0x00;

  return str;
}

/**
 * Justify the text to the center of its box, which size is defined as width. 
 * Empty space is filled with the character passed to the function
 * NOTE: if the length of the string passed to the function is greater or equal to width,
 * the function will just return the passed string
 * @param char*: str to Justify
 * @param int: width
 * @param char: the character used to fill the empty space
 * @return char*: pointer to reallocated string check if NULL
**/

char* cjust(char* str, int width, char fillChar) {

  //If strLength is greater or equal to width, do nothing
  size_t strLength = strlen(str);
  if (strLength >= width) {
    return str;
  }

  //Calc lwidth and then rwidth; if width - strLength is ODD, prefer ljust
  int lwidth, rwidth;
  if ((width - strLength) % 2 == 0) {
    lwidth = rwidth = (width - strLength) / 2;
  } else {
    lwidth = rwidth = (width - strLength) / 2;
    lwidth++; //Increment rwidth, which is the width at the left of str
  }

  /** 
   * Call ljust and rjust with their opposite width (wait what???)
   * No, it's not a mistake, think about it, when you justify a text to right,
   * you add space to the left and viceversa
  **/
  str = ljust(str, rwidth + strLength, fillChar);
  if (str == NULL)
    return NULL;
  strLength = strlen(str);
  str = rjust(str, lwidth + strLength, fillChar);

  return str;
}

/**
 * Justify the text to the right of its box, which size is defined as width. 
 * Empty space is filled with the character passed to the function
 * NOTE: if the length of the string passed to the function is greater or equal to width,
 * the function will just return the passed string
 * @param char*: str to Justify
 * @param int: width
 * @param char: the character used to fill the empty space
 * @return char*: pointer to reallocated string; check if NULL
**/

char* rjust(char* str, int width, char fillChar) {

  //If strLength is greater or equal to width, do nothing
  size_t strLength = strlen(str);
  if (strLength >= width) {
    return str;
  }

  str = realloc(str, sizeof(char) * (width + 1));
  if (str == NULL) {
    return NULL;
  }
  //Move str ahead of width - strLength positions
  memcpy(str + (width - strLength), str, strLength);
  memset(str, fillChar, (width - strLength));
  str[width] = 0x00;

  return str;
}

/**
 * Given a string representing a series of hex values in ASCII, it returns real hex values (e.g. "01ABEF" becomes => [0x01, 0xAB, 0xEF])
 * If a character of str is not an hex representation it will be conveted to 0
 * @param uint8_t* dest: buffer that will contain the hex values
 * @param char* str: buffer which contains the ASCII representation
 * @return int: the length of the destination
**/

int asciiToHex(uint8_t* dest, char* str) {

  int destLength = strlen(str) / 2; //Get length of dest
  for (int i = 0; i < destLength; i++) {
    char digit[3];
    digit[0] = *(str++);
    digit[1] = *(str++);
    digit[2] = 0x00; //Null terminate
    dest[i] = (uint8_t)(strtol(digit, NULL, 16));
  }

  return destLength;
}

/**
 * Converts a hex buffer to its ASCII representation (e.g. [0x01, 0xAB, 0xEF] becomes => "01ABEF")
 * @param char*: destination buffer, its size must be bytes size * 2
 * @param uint8_t*: hex buffer
 * @param size_t: length of buffer
 * @return char*: pointer to dest
**/

char* hexToAscii(char* dest, uint8_t* bytes, size_t len) {
  char hexmap[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
  for (size_t i = 0; i < len; ++i) {
    dest[2 * i] = hexmap[(bytes[i] & 0xF0) >> 4];
    dest[2 * i + 1] = hexmap[bytes[i] & 0x0F];
  }
  return dest;
}
