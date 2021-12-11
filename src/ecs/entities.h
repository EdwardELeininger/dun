#ifndef ENTITIES_H
#define ENTITIES_H
#include "../tools/stack.h"
#include "../config.h"

int entities_init();
int entities_add(char name[MAXNAMESIZE]);
int entities_remove(int entity);
#endif
