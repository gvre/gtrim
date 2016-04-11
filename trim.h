#ifndef TRIM_H
#define TRIM_H

#define TRIM_LEFT 1
#define TRIM_RIGHT 2

char *trim(char *str);
char *ltrim(char *str);
char *rtrim(char *str);
char *trim_chars(char *str, const char *rem);
char *ltrim_chars(char *str, const char *rem);
char *rtrim_chars(char *str, const char *rem);
#endif

