#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>
#include "src/tools/clitools.h"
#include "src/tools/noise.h"
#include "src/config.h"
#include "src/combat_stats.h"
#include "src/tools/webui.h"

unsigned char seed[SEEDSIZE];

int handleCmdArgs(int argc, char** argv, char *rawseed)
{
    if(argc <2)
    {
        printf("type a seed\n");
        getstring(rawseed, RAWSEEDMAX);
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
    return 0;
}

int main(int argc, char** argv)
{
    char rawseed[RAWSEEDMAX];
    handleCmdArgs(argc, argv, rawseed);
    initSeed(rawseed);
    loadAndInit();
    int doGameLoop = 1;
    static int time;
    char controller = 'z';
    assert(webui_init()==0);
    while(doGameLoop)
    {
        webui_handle();
/*
 * oof, what am I doing here...
 * okay,
 * server side keeps track of everything
 * can the server spawn the client? do I want it to?
 * maybe for single player/testing?
 *
 * i guess first is to create some socks, eh?
 *
 * then we'll set up the game world, and start taking clients...
 * not going to worry about threads yet.
 *
 *
 */
        time += 1;
        if(!feof(stdin))
        {
            getstring(&controller, 1);
            if(controller != 'z')
            {
                printf("echo: %c\n", controller);
                if(controller == 'q') doGameLoop = 0;
                controller = 'z';
            }
        }

    }
    printf("time: %d\n", time);
    return 0;
}
