/**
 * NVIC
 */

#ifndef __NVIC_H_INCLUDED__
#define __NVIC_H_INCLUDED__

#include <stdint.h>

#define __I volatile
#define __O volatile const
#define __IO volatile

#define NVIC_BASE (0xe000e000)

typedef struct NvicStruct {
  uint8_t reserved[0x100];

  __IO uint32_t iser[2];   // 0x100-0x104
  uint8_t reserved2[0x78]; // 0x108-0x17f

  __IO uint32_t icer[2];   // 0x180-0x184
  uint8_t reserved2[0x78]; // 0x188-0x1ff

  __IO uint32_t ispr[2];   // 0x200-0x204
  uint8_t reserved2[0x78]; // 0x208-0x27f

  __IO uint32_t icpr[2];   // 0x280-0x284
  uint8_t reserved2[0x78]; // 0x288-0x2ff

  __O uint32_t iabr[2];    // 0x300-0x304
  uint8_t reserved2[0xf8]; // 0x308-0x3ff

  __IO uint32_t ipr[9]; // 0x400-0x420
  uint32_t : 32;        // 0x424
  uint32_t : 32;        // 0x428
  uint32_t : 32;        // 0x42c
  uint32_t : 32;        // 0x430
  uint32_t : 32;        // 0x434
  uint32_t : 32;        // 0x438
  uint32_t : 32;        // 0x43c

  uint8_t reserved2[0xac0]; // 0x440-0xeff

  __I uint32_t stir; // 0xf00
} NvicStruct;

#define NVIC ((NvicStruct *)NVIC_BASE)

#endif // __NVIC_H_INCLUDED__
