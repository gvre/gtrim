/**
The MIT License (MIT)
Copyright (c) 2015 Giannis Vrentzos <gvre@gvre.gr>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "trim.h"

static char *_trim(char *str, const char *rem, int mode);

static char *_trim(char *str, const char *rem, int mode)
{
    if (str == NULL || rem == NULL)
        return NULL;

    if (str[0] == '\0')
        return str;

    char *start = str;
    if (mode & TRIM_LEFT) {
        while (*str && strchr(rem, *str) != NULL) 
            str++;

        if (str != start) {
            size_t len = strlen(str);
            memmove(start, str, len + 1);
            str = start;
        }
    }

    if (str[0] == '\0')
        return str;

    if (mode & TRIM_RIGHT) {
        str += strlen(str) - 1; 

        while (*str && strchr(rem, *str) != NULL) 
            str--;
        *(str + 1) = '\0';
    }

    return start;
}

char *trim(char *str)
{
    return _trim(str, " \t\n\r\x0B\x0C", TRIM_LEFT | TRIM_RIGHT);
}

char *ltrim(char *str)
{
    return _trim(str, " \t\n\r\x0B\x0C", TRIM_LEFT);
}

char *rtrim(char *str)
{
    return _trim(str, " \t\n\r\x0B\x0C", TRIM_RIGHT);
}

char *trim_chars(char *str, const char *rem)
{
    return _trim(str, rem, TRIM_LEFT | TRIM_RIGHT);
}

char *ltrim_chars(char *str, const char *rem)
{
    return _trim(str, rem, TRIM_LEFT);
}

char *rtrim_chars(char *str, const char *rem)
{
    return _trim(str, rem, TRIM_RIGHT);
}

