#ifndef NOISE_H
#define NOISE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../config.h"

extern unsigned char seed[SEEDSIZE];

int initSeed(char* rawseed);
float squirrelNoises(int value);
unsigned char getSeedVal();
#endif
