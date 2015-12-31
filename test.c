#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trim.h"

int main(void)
{
    char *msg = malloc(20);
    strcpy(msg, "		       hello ");
    msg = trim(msg);
    assert(strcmp(msg, "hello") == 0 && strlen(msg) == 5);
    free(msg);

    char msg2[] = "  world  ";
    trim(msg2);
    assert(strcmp(msg2, "world") == 0 && strlen(msg2) == 5); 

    char msg3[] = "  hello world  ";
    trim(msg3);
    assert(strcmp(msg3, "hello world") == 0 && strlen(msg3) == 11); 

    char msg4[] = "  world  ";
    ltrim(msg4);
    assert(strcmp(msg4, "world  ") == 0 && strlen(msg4) == 7); 

    char msg5[] = "  world  ";
    rtrim(msg5);
    assert(strcmp(msg5, "  world") == 0 && strlen(msg5) == 7); 

    char *msg6 = "";
    msg6 = trim(msg6);
    assert(strlen(msg6) == 0);

    char *msg7 = NULL;
    assert(trim(msg7) == NULL);

    return EXIT_SUCCESS;
}
