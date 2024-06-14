#include <stdint.h>

// GPIO Register Definitions for Port N

#define SYSCTL_RCGCGPIO    (*((volatile uint32_t *)0x400FE608U)) // 400FE000 + 608

// GPIO Registers for Port N
#define GPION_DIR          (*((volatile uint32_t *)0x40064400U)) // GPIO Direction
#define GPION_DEN          (*((volatile uint32_t *)0x4006451CU)) // GPIO Digital Enable


//Initialisation of GPIO Port N
 void GPIO_N_Init()
 {
     // Enable clock for GPIO N
     SYSCTL_RCGCGPIO = 0x1030U;

     // Enable digital I/O on of GPIO N
     GPION_DEN = 0x03U;

     // Set Pin-1 & Pin-0 of GPIO N as output
     GPION_DIR = 0x03U;
 }
