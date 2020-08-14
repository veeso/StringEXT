#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libstringext], [1.0.0], [https://github.com/ChristianVisintin/StringEXT])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([include/stringext.h])
AC_CONFIG_HEADERS([config.h])
AC_LANG(C)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_AR

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([inttypes.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strstr strtol])

#Initialize LT for shared objects
LT_INIT

AC_OUTPUT(Makefile src/Makefile)
