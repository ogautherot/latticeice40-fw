/**
 *
 */

#ifndef __LATTICE_ICE_H_INCLUDED__
#define __LATTICE_ICE_H_INCLUDED__

#include <stdint.h>

#include "lpc11u67.h"

typedef enum FpgaCmd
{
    FPGA_NOP = 0,
    FPGA_GET_STATUS
} FpgaCmd_t;

/**
 *  Bit mask used for gather() and scatter()
 */
typedef union
{
    uint32_t v;
    struct
    {
        uint32_t grp0 : 2;
        uint32_t grp1 : 4;
        uint32_t grp2 : 2;
    };
} CompactStruct;

/**
 *  Bit mask used for gather() and scatter()
 */
typedef union
{
    uint32_t v;
    struct
    {
        uint32_t : 2;
        uint32_t grp0 : 2;
        uint32_t : 2;
        uint32_t grp1 : 4;
        uint32_t : 10;
        uint32_t grp2 : 2;
    };
} ExpandedStruct;

class FpgaInterfaceClass
{
private:
    uint32_t sample;

public:
    static uint32_t Scatter(uint32_t v)
    {
        CompactStruct c = {v};
        ExpandedStruct x = {0};

        x.grp0 = c.grp0;
        x.grp1 = c.grp1;
        x.grp2 = c.grp2;

        return x.v;
    }

    static uint32_t Gather(uint32_t v)
    {
        CompactStruct c = {0};
        ExpandedStruct x = {v};

        c.grp0 = x.grp0;
        c.grp1 = x.grp1;
        c.grp2 = x.grp2;

        return c.v;
    }

    static void SetPin(uint8_t port, uint8_t pin, uint8_t val)
    {
        __IO uint8_t *ptr = GPIO0->byte_pin0;
        ptr[32 * port + pin] = val;
    }

    static void SetAccessMode(uint8_t rd, uint8_t cmd)
    {
        SetPin(1, 21, rd);
        SetPin(1, 20, cmd);
    }

    static void CycleClk(void)
    {
        SetPin(1, 13, 1);
        SetPin(1, 13, 0);
    }

    static void SetLaClk(uint8_t stat)
    {
        SetPin(1, 23, stat);
    }
};

#endif // __LATTICE_ICE_H_INCLUDED__
