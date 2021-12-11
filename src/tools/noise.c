#include "noise.h"
float squirrelNoises(int value)
{
    unsigned int SQ5_BIT_NOISE1 = 0xd2a80a3f; // 11010010101010000000101000111111
    unsigned int SQ5_BIT_NOISE2 = 0xa884f197; // 10101000100001001111000110010111
    unsigned int SQ5_BIT_NOISE3 = 0x6C736F4B; // 01101100011100110110111101001011
    unsigned int SQ5_BIT_NOISE4 = 0xB79F3ABB; // 10110111100111110011101010111011
    unsigned int SQ5_BIT_NOISE5 = 0x1b56c4f5; // 00011011010101101100010011110101
    unsigned int mangledBits = (unsigned int) value;
    mangledBits *= SQ5_BIT_NOISE1;
    mangledBits += (unsigned int) getSeedVal();
    mangledBits ^= (mangledBits >> 9);
    mangledBits += SQ5_BIT_NOISE2;
    mangledBits ^= (mangledBits >> 11);
    mangledBits *= SQ5_BIT_NOISE3;
    mangledBits ^= (mangledBits >> 13);
    mangledBits += SQ5_BIT_NOISE4;
    mangledBits ^= (mangledBits >> 15);
    mangledBits *= SQ5_BIT_NOISE5;
    mangledBits ^= (mangledBits >> 17);
    /*
    return mangledBits;
    */
    float ONE_OVER_MAX_INT = (1.0 / (double) 0x7FFFFFFF);
    printf("lolwut:%f\n",ONE_OVER_MAX_INT);
    return (float)( ONE_OVER_MAX_INT * (double) (int) (mangledBits ));
}
unsigned char getSeedVal()
{
    static int index = 0;
    if(index > SEEDSIZE)
    {
        index = 0;
    }
    return seed[index++];
}

int initSeed(char* rawseed)
{
    const int rawseed_len = strlen(rawseed);
    for(int i = 0; i < SEEDSIZE; i++)
    {
        seed[i] = (unsigned char) rawseed[i%rawseed_len];
    }
    return 0;
}


