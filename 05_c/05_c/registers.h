#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

typedef uint32_t Register_t;

extern Register_t ADCCON3;

void setRegisters(Register_t* reg);

void setRegistersStruct(Register_t* reg);

#endif
