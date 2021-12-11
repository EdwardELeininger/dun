#include "entities.h"
static stack* recycle;
static int entityCount = 0;
char** c_name;
int entities_init()
{
    c_name = malloc(INITIALENTITYCOUNT * sizeof(char*));
    c_name[0] = malloc(INITIALENTITYCOUNT * MAXNAMESIZE);
    for(int i=0;i<MAXNAMESIZE;i++)
    {
        c_name[i] = c_name[0] +i * MAXNAMESIZE;
    }
    recycle = (stack*)malloc(sizeof(stack));
    return 0;
}
int entities_add(char name[MAXNAMESIZE])
{
    static int newEntityCount = -1;
    int entitynum = -1;
    if((*recycle).next != NULL)
    {
        entitynum = (int)(stack_pop(&(recycle)));
        printf("recycling id# %d\n",entitynum);
    }else
    {
        entitynum = ++newEntityCount;
        printf("new id# %d\n",entitynum);
    }
    entityCount++;
    strncpy(c_name[entitynum], name, MAXNAMESIZE);
    printf("adding %s to entities with id of %d\n", name, entitynum);
    return entitynum;
}
int entities_remove(int entity)
{
    printf("removing entity with id# %d\n",entity);
    stack_push(&recycle, (void*)entity);
    strncpy(c_name[entity], "NULL", MAXNAMESIZE);
    entityCount--;
    return 0;
}

int main()
{
    entities_init();
    int player = entities_add("player");
    int cat = entities_add("cat");
    int dog = entities_add("dog");
    int mab = entities_add("mab");
    printf("there are %d entities\n",entityCount);
    for(int i = 0; i < entityCount; i++)
    {
        printf("%s id# is %d\n", c_name[i], i);
    }
    entities_remove(dog);
    int maev = entities_add("maev");
    entities_remove(maev);
    int sam = entities_add("sam");
    int bob = entities_add("bob");

    printf("there are %d entities\n",entityCount);
    for(int i = 0; i < entityCount; i++)
    {
        printf("%s id# is %d\n", c_name[i], i);
    }
    return 0;
}
