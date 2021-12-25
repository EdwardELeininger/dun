#include "clitools.h"

int getstring(char* target, int size)
{
    char buf[size];
    if (fgets(buf, sizeof buf, stdin)) 
    {
        buf[strcspn(buf, "\n")] = '\0';
        strncpy(target, buf, size);
        return 0;
    }
    else
    {
        printf("something is wrong with your string input, dolt");
        return -1;
    }
}


