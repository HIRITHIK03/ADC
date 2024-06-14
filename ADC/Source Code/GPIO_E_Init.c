#include <stdint.h>

// Clock Gating Control Registers for GPIO
#define SYSCTL_RCGCGPIO    (*((volatile uint32_t *)0x400FE608U)) // 400FE000 + 608

// GPIO Registers for Port E
#define GPIOE_AFSEL        (*((volatile uint32_t *)0x4005C420U)) // GPIO Alternate Function Select
#define GPIOE_DEN          (*((volatile uint32_t *)0x4005C51CU)) // GPIO Digital Enable
#define GPIOE_AMSEL        (*((volatile uint32_t *)0x4005C528U)) // GPIO Analog Mode Select

void GPIO_E_Init()
{
    // initialize PE3 for AIN0 input
    GPIOE_DEN    = 0x00;            // Disable digital function
    GPIOE_AFSEL  = 0x08;           // Enable alternate function
    GPIOE_AMSEL  = 0x08;           // Enable analog function
}
