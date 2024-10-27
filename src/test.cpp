/**
 * 
 */

#include "../include/LatticeICE.h"

uint32_t test1(uint32_t v)
{
    return FpgaInterfaceClass::scatter(v);
}

uint32_t test2(uint32_t v)
{
    return FpgaInterfaceClass::gather(v);
}

