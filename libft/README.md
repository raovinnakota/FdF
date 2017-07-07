# libft

Introduction
------------

Libft is the first project that new cadets are asked to complete at 42. Part of the 42 philosophy is understanding through recreation. So, rather than use libc and stdlib functions, we recreate them. It's also intended to be continually expanded as we attempt more projects. As the library gets expanded this repo will updated to reflect that.

Usage
-----

Clone the repo and use `make all` to create the library. To keep the library and remove the object files, use `make clean`. To reset the repo to it's previous state entirely use `make fclean`.

Using the library involves several steps. First, you must add `#include "libft.h"` either to your header file, or all files which call a libft function. When compiling, use the format `gcc <filename.c> <path>/libft.a`.

Functions
---------

Name | Prototype | Library/Header | Purpose
---- | --------- | -------------- | -------
`ft_bzero` | `void ft_bzero(char *str, size_t size)` | `libc/string.h` | Replaces a `size_t` number of bytes in `str` with the `'\0'` byte.
`ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | `libc/string.h` | Fills `len` bytes in the `b` with `c`.
`ft_memcpy` | `void *ft_memcpy(void *dst, void *src, size_t len)` | `libc/string.h` | Copies `len` bytes of memory from the `src` to `dst`. Assumes that `dst` has memory already allocated.
`ft_memccpy` | `void *ft_memccpy(void *dst, const void *src, int c, size_t len)` | `libc/string.h` | Coplies `len` bytes of memory from `src` to `dst`. The function returns a pointer to the first character after `c` in `dst` or null if `c` doesn't exist in `dst`.
`ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | `libc/string.h` | Copies `len` bytes from `src` to `dst` while making sure that they don't overlap.
`ft_memchr` | `void *ft_memchr(void *s, int c, size_t len)` | `libc/string.h` | Scans the first `len` bytes of `s` for the first occurrence of `c`. Returns a pointer a pointer to that first occurrence. 
`ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t len)` | `libc/string.h` | Compares the first `len` bytes of both `s1` and `s2`. If `s1 < s2`, returns a negative integer. If `s1 > s2`, returns a positive integer. If `s1 == s2`, returns zero.
`ft_strlen` | `size_t    ft_strlen(char *str);` | `libc/string.h` | Returns an unsigned integer that contains the size of a string | Iterate through the string and increment a counter. Return the counter, will need to include `string.h` to use `size_t`
`ft_strcpy` | `char *ft_strcpy(char *dest, const char *src);` | `libc/string.h` | Copies the entirety of src, including the null-terminating byte to the buffer pointed to by dest. The buffer should have the correct amount of memory allocated
`ft_strdup` | `char *ft_strdup(const char *str);` | `libc/string.h` | Allocates enough memory to hold the input string, and copies the contents of input string to newly allocated string. Returns the allocated string.
`ft_strndup` | `char *ft_strndup(const char *str, size_t size)` | `libc/string.h` | Allocates size bytes of memory and copies size number of characters into a new string, and returns the string. 
`ft_strcat` | `char *ft_strcat(char *dest, char *src);` | `libc/string.h` | Copies the contents of the source string to the destination string, starting at the first instance of a null terminated byte. Assumes that the destination string has enough memory allocated to hold the source string.
`ft_strncat` | `char *ft_strncat(char *dest, char *src, size_t size);` | `libc/string.h` | Concatenates a finite number of bytes, determined by the input size from the source string to the destination string. If the size > string length, the extra bytes are filled with `'\0'` bytes. 
`ft_strchr` | `char *ft_strchr(const char *str, int c)` | `libc/string.h` | Returns a pointer that points towards the first occurrence of `int c`(ascii) in input string `str`. If `c` doesn't occur in `str`, `ft_strchr` will return a null pointer
`ft_strrchr` | `char *ft_strrchr(const char *str)` | `libc/string.h` | Returns a pointer that points towards the last occurrence of `char c`(ascii) in input string `str`. If `c` doesn't occur in `str`, a null pointer is returned.
`ft_strstr` | `char *ft_strstr(const char *haystack, const char *needle)` | `libc/string.h` | Returns a pointer to the first occurrence of the entire sequence of characters of needle in haystack. If that doesn't exist, `ft_strstr` returns a null pointer.
`ft_strnstr`| `char *ft_strnstr(const char *big, const char *little, size_t len)` | `libc/string.h` | Returns a pointer to the first occurence of the string `little` in `big` where only the first `len` bytes are searched.
`ft_strcmp` | `int ft_strcmp(const char *s1, const char *s2)` | `libc/string.h` | Compares the strings `s1` and `s2`. If `s1 < s2`, returns a value less than 0. If `s1 > s2`, will return a value greater than 0. If `s1 == s2`, will return 0. 
`ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t len)` | `libc/string.h` | Compares only the first `len` bytes of both strings. The return values are the same as `ft_strcmp`
`ft_atoi` | `int ft_atoi(char *str)` | `libc/string.h` | Converts the input string to an integer, and returns the integer. 
`isalpha` | `int ft_isalpha(int c)` | `libc/string.h` | Returns `1` if input is a character in the alphabet (both cases), else will retun `0`
`ft_isdigit` | `int ft_isdigit(int c)` | `libc/string.h` | Returns `1` if input is a digit between `0-9`, else returns `0`.
`ft_isalnum` | `int ft_isalnum(int c)` | `libc/string.h` | Returns `1` if and only if `((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))`, else returns `0`.
`ft_isascii` | `int ft_isascii(int c)` | `libc/string.h` | Returns `1` if `c` has a corresponding ascii character, else returns `0`.
`ft_isprint` | `int ft_isprint(int c)` | `libc/string.h` | Returns `1` if `c` is a printable ascii character, else returns `0`
