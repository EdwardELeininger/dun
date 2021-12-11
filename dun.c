#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>
#include "src/tools/noise.h"
#include "src/config.h"

unsigned char seed[SEEDSIZE];

int handleCmdArgs(int argc, char** argv, char *rawseed)
{
    if(argc <2)
    {
        char buf[RAWSEEDMAX];
        printf("type a seed\n");
        if (fgets(buf, sizeof buf, stdin)) {
            buf[strcspn(buf, "\n")] = '\0';
            strncpy(rawseed, buf, RAWSEEDMAX);
        }
    }
    else
    {
        strncpy(rawseed, argv[1], RAWSEEDMAX);
    }
    printf("%s\n", rawseed);
    return 0;
}

int loadAndInit()
{
    printf("loading...\n");
}

int main(int argc, char** argv)
{
    char rawseed[RAWSEEDMAX];
    handleCmdArgs(argc, argv, rawseed);
    initSeed(rawseed);
    loadAndInit();
    return 0;
}