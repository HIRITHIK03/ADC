#include <stdint.h>

// Clock Gating Control Registers for ADC
#define SYSCTL_RCGCADC     (*((volatile uint32_t *)0x400FE638U)) // 400FE000 + 638

// ADC Registers
#define ADC0_ACTSS         (*((volatile uint32_t *)0x40038000U)) // ADC Active Sample Sequencer
#define ADC0_EMUX          (*((volatile uint32_t *)0x40038014U)) // ADC Event Multiplexer Select
#define ADC0_SSMUX3        (*((volatile uint32_t *)0x400380A0U)) // ADC Sample Sequence Input Multiplexer
#define ADC0_SSEMUX3       (*((volatile uint32_t *)0x400380B8U)) // ADC Sample Sequence Event Input Multiplexer
#define ADC0_SSCTL3        (*((volatile uint32_t *)0x400380A4U)) // ADC Sample Sequence Control
#define ADCSSTSH3          (*((volatile uint32_t *)0x400380BCU)) // ADC Sample Sequence Sample and Hold Time
#define ADCSSOP3           (*((volatile uint32_t *)0x400380B0U)) // ADC Sample Sequence 3 Operation
#define ADC0_PSSI          (*((volatile uint32_t *)0x40038028U)) // ADC Processor Sample Sequence Initiate-
#define ADC0_RIS           (*((volatile uint32_t *)0x40038004U)) // ADC Raw Interrupt Status
#define ADC0_SSFIFO3       (*((volatile uint32_t *)0x400380A8U)) // ADC Sample Sequence Result FIFO
#define ADC0_ISC           (*((volatile uint32_t *)0x4003800CU)) // ADC Interrupt Status and Clear

void ADC0Init()
{
    SYSCTL_RCGCADC |= 0x01;        // AD0 clock enable

    // initialize sample sequencer3
    ADC0_ACTSS = 0x00;           // Disable SS3 during configuration
    ADC0_EMUX  = 0x00;          // Software trigger conversion
    ADC0_SSMUX3 = 0x0;               // Get input from channel 0
    ADC0_SSEMUX3 = 0x0;
    ADC0_SSCTL3  = 0x06;    // Take one sample at a time, set flag at 1st sample
    ADCSSTSH3   = 0x0;
    ADCSSOP3 = 0x0;
    ADC0_ACTSS = 0x08;            // Enable ADC0 sequencer 3
    ADC0_ISC = 0x08;
}
