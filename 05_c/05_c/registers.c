#include <stdio.h>
#include "registers.h"

Register_t ADCCON3 = 0xa14c99f7;

#define ADC_DIGEN7 (1 << 23)
#define ADC_DIGEN6 (1 << 22)
#define ADC_DIGEN0TO5 (0b111111 << 16)
#define ADC_CONCLKDIV (0b111111 << 24)
#define ADC_VREFSEL (0b111 << 13)

void setRegisters(Register_t* reg) {
    *reg &= ~ADC_DIGEN0TO5; // Disable ADC digital channels 0 to 5
    *reg |= (ADC_DIGEN7 | ADC_DIGEN6); // Enable ADC digital channels 6 and 7

    *reg &= ~ADC_CONCLKDIV; // Clear ADC clock divider bits
    *reg |= (60 << 24); // Set ADC clock divider to 60 (Tq = 60 * Tclk)

    *reg &= ~ADC_VREFSEL; // Clear ADC voltage reference bits
    *reg |= (0b01 << 13); // Set ADC voltage reference to Internal VREFH

    printf("Modified register using bitwise operators: 0x%08X\n", *reg);
}

struct ADCCON3Reg {
    uint32_t reserved : 16;
    uint32_t VREFSEL : 3;
    uint32_t reserved2 : 4;
    uint32_t CONCLKDIV : 6;
    uint32_t reserved3 : 3;
    uint32_t DIGEN0TO5 : 6;
    uint32_t reserved4 : 2;
    uint32_t DIGEN6 : 1;
    uint32_t DIGEN7 : 1;
};

void setRegistersStruct(Register_t* reg) {
    struct ADCCON3Reg* adcReg = (struct ADCCON3Reg*)reg;
    adcReg->DIGIN7 = 1; // Enable ADC digital channel 7
    adcReg->DIGIN6 = 1; // Enable ADC digital channel 6
    adcReg->DIGIN0TO5 = 0; // Disable ADC digital channels 0 to 5

    adcReg->CONCLKDIV = 60; // Set ADC clock divider to 60 (Tq = 60 * Tclk)

    adcReg->VREFSEL = 0b01; // Set ADC voltage reference to Internal VREFH

    printf("Modified register using structs: 0x%08X\n", *reg);
}
