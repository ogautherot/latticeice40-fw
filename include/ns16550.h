/**
 * NS16550 + RS485 support + sync control
 */

#ifndef __NS16550_H_INCLUDED__
#define __NS16550_H_INCLUDED__

#include <stdint.h>

#ifndef __I
#define __I volatile
#define __IO volatile
#define __O volatile const
#endif // __I

typedef struct Ns16550Struct
{
    union
    {                      // 0x00
        __O uint32_t rbr;  // DLAB=0, receiver buffer register
        __I uint32_t thr;  // DLAB=0, transmit holding register
        __IO uint32_t dll; // DLAB=1, divisor latch LSB
    };
    union
    {                      // 0x04
        __IO uint32_t ier; // DLAB=0, interrupt enable register
        __IO uint32_t dlm; // DLAB=1, divisor latch MSB
    };
    union
    {                     // 0x08
        __O uint32_t iir; // Interrupt ID register
        __I uint32_t fcr; // FIFO control register
    };
    __IO uint32_t lcr; // 0x0c, line control register
    __IO uint32_t mcr; // 0x10, modem control register
    __IO uint32_t lsr; // 0x14, line status register
    __IO uint32_t msr; // 0x18, modem status register
    __IO uint32_t scr; // 0x1c, scratch pad register

    __IO uint32_t acr; // 0x20, auto-baud control
    __IO uint32_t icr; // 0x24
    __IO uint32_t fdr; // 0x28, fractional divider register
    __IO uint32_t osr; // 0x2c
    __IO uint32_t ter; // 0x30, transmit enable register
    uint32_t : 32;     // 0x34
    uint32_t : 32;     // 0x38
    uint32_t : 32;     // 0x3c

    __IO uint32_t hden;    // 0x40
    uint32_t : 32;         // 0x44
    __IO uint32_t scictrl; // 0x48
} Ns16550Struct;

typedef struct Ns16550Rs485Struct
{
    union
    {                      // 0x00
        __O uint32_t rbr;  // DLAB=0, receiver buffer register
        __I uint32_t thr;  // DLAB=0, transmit holding register
        __IO uint32_t dll; // DLAB=1, divisor latch LSB
    };
    union
    {                      // 0x04
        __IO uint32_t ier; // DLAB=0, interrupt enable register
        __IO uint32_t dlm; // DLAB=1, divisor latch MSB
    };
    union
    {                     // 0x08
        __O uint32_t iir; // Interrupt ID register
        __I uint32_t fcr; // FIFO control register
    };
    __IO uint32_t lcr; // 0x0c, line control register
    __IO uint32_t mcr; // 0x10, modem control register
    __IO uint32_t lsr; // 0x14, line status register
    __IO uint32_t msr; // 0x18, modem status register
    __IO uint32_t scr; // 0x1c, scratch pad register

    __IO uint32_t acr; // 0x20, auto-baud control
    __IO uint32_t icr; // 0x24
    __IO uint32_t fdr; // 0x28, fractional divider register
    __IO uint32_t osr; // 0x2c
    __IO uint32_t ter; // 0x30, transmit enable register
    uint32_t : 32;     // 0x34
    uint32_t : 32;     // 0x38
    uint32_t : 32;     // 0x3c

    __IO uint32_t hden;           // 0x40
    uint32_t : 32;                // 0x44
    __IO uint32_t scictrl;        // 0x48
    __IO uint32_t rs485ctrl;      // 0x4c, mode control
    __IO uint32_t rs485addrmatch; // 0x50, address match
    __IO uint32_t rs485dly;       // 0x54, direction control delay
} Ns16550Rs485Struct;

typedef struct Ns16550Rs485SyncStruct
{
    union
    {                      // 0x00
        __O uint32_t rbr;  // DLAB=0, receiver buffer register
        __I uint32_t thr;  // DLAB=0, transmit holding register
        __IO uint32_t dll; // DLAB=1, divisor latch LSB
    };
    union
    {                      // 0x04
        __IO uint32_t ier; // DLAB=0, interrupt enable register
        __IO uint32_t dlm; // DLAB=1, divisor latch MSB
    };
    union
    {                     // 0x08
        __O uint32_t iir; // Interrupt ID register
        __I uint32_t fcr; // FIFO control register
    };
    __IO uint32_t lcr; // 0x0c, line control register
    __IO uint32_t mcr; // 0x10, modem control register
    __IO uint32_t lsr; // 0x14, line status register
    __IO uint32_t msr; // 0x18, modem status register
    __IO uint32_t scr; // 0x1c, scratch pad register

    __IO uint32_t acr; // 0x20, auto-baud control
    __IO uint32_t icr; // 0x24
    __IO uint32_t fdr; // 0x28, fractional divider register
    __IO uint32_t osr; // 0x2c
    __IO uint32_t ter; // 0x30, transmit enable register
    uint32_t : 32;     // 0x34
    uint32_t : 32;     // 0x38
    uint32_t : 32;     // 0x3c

    __IO uint32_t hden;           // 0x40
    uint32_t : 32;                // 0x44
    __IO uint32_t scictrl;        // 0x48
    __IO uint32_t rs485ctrl;      // 0x4c, mode control
    __IO uint32_t rs485addrmatch; // 0x50, address match
    __IO uint32_t rs485dly;       // 0x54, direction control delay
    __IO uint32_t syncctrl;       // 0x58
} Ns16550Rs485SyncStruct;

#endif // __NS16550_H_INCLUDED__
