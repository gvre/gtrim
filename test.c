#define _POSIX_C_SOURCE 200809L /* strdup */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trim.h"

int main(void)
{
    char *msg = strdup("\t\n\r test \x0B\x0C");
    msg = trim(msg);
    assert(strcmp(msg, "test") == 0);
    free(msg);

    char msg2[] = "\ntest\n";
    trim_chars(msg2, "\n");
    assert(strcmp(msg2, "test") == 0);

    char msg3[] = "  test test";
    trim(msg3);
    assert(strcmp(msg3, "test test") == 0);

    char msg4[] = "  test  ";
    ltrim(msg4);
    assert(strcmp(msg4, "test  ") == 0);

    char msg5[] = "  test  ";
    rtrim(msg5);
    assert(strcmp(msg5, "  test") == 0);

    char *msg6 = strdup(" ");
    msg6 = trim(msg6);
    assert(strlen(msg6) == 0);

    char *msg7 = NULL;
    assert(trim(msg7) == NULL);

    char *msg8 = strdup("...test...");
    msg8 = trim_chars(msg8, ".");
    assert(strcmp(msg8, "test") == 0);
    free(msg8);

    char *msg9 = strdup("...test...");
    msg9 = ltrim_chars(msg9, ".");
    assert(strcmp(msg9, "test...") == 0);
    free(msg9);

    char *msg10 = strdup("...test...");
    msg10 = rtrim_chars(msg10, ".");
    assert(strcmp(msg10, "...test") == 0);
    free(msg10);

    printf("OK\n");

    return EXIT_SUCCESS;
}
