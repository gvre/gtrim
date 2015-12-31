#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "trim.h"

static char * _trim(char *str, char *direction);

static char * _trim(char *str, char *direction)
{
    if (str == NULL || direction == NULL)
        return NULL;

    if (str[0] == '\0')
        return str;

    char *start = str;
    if (strstr(direction, "l") != NULL) {
        while (isspace(*str))
            str++;
        size_t len = strlen(str);
        memmove(start, str, len + 1);
        start[len] = '\0';
        str = start;
    }

    if (str[0] == '\0')
        return str;

    if (strstr(direction, "r") != NULL) {
        str += strlen(str) - 1; 
        while (isspace(*str))
            str--;
        *(str + 1) = '\0';
    }

    return start;
}

char *trim(char *str)
{
    return _trim(str, "lr");
}

char *ltrim(char *str)
{
    return _trim(str, "l");
}

char *rtrim(char *str)
{
    return _trim(str, "r");
}

