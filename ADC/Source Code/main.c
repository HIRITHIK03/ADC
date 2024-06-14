#include <stdint.h>
#include "ADC0Init.h"
#include "GPIO_E_Init.h"
#include "GPIO_N_Init.h"

// ADC Registers

#define ADC0_PSSI          (*((volatile uint32_t *)0x40038028U)) // ADC Processor Sample Sequence Initiate-
#define ADC0_RIS           (*((volatile uint32_t *)0x40038004U)) // ADC Raw Interrupt Status
#define ADC0_SSFIFO3       (*((volatile uint32_t *)0x400380A8U)) // ADC Sample Sequence Result FIFO
#define ADC0_ISC           (*((volatile uint32_t *)0x4003800CU)) // ADC Interrupt Status and Clear

// GPIO Registers
#define GPION_DATA         (*((volatile uint32_t *)0x400643FCU)) // GPIO Data


int main(void)
{
    unsigned int result;

    //Initialisation of GPIO Port N
    GPIO_N_Init();

    // GPIO E Port Initialization
    GPIO_E_Init();

    // ADC0 Initialization
    ADC0Init();


    while (1)  // Infinite Loop
    {
        ADC0_PSSI |= 0x08;        // Enable SS3 conversion or start sampling data from AN0
        while ((ADC0_RIS & 0x08) == 0); // Wait until sample conversion completed
        result = ADC0_SSFIFO3;     // Read ADC conversion result from SS3 FIFO
        ADC0_ISC = 0x08;           // Clear conversion complete flag bit

        if(result<1000)
        {
            GPION_DATA=0x01;
        }
        else if(result>=1000 && result<2000)
        {
            GPION_DATA=0x02;
        }
        else
        {
            GPION_DATA=0x00;
        }
    }
}
