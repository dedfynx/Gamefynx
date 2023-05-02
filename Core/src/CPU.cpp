#include "CPU.h"

#include <iostream>
#include <bitset>

namespace Gamefynx
{
    CPU::CPU()
    {
        
        setReg(R_AF, 0xAA00);
        setReg(R_BC, 0xBBCC);
        setReg(R_DE, 0xDDEE);
        setReg(R_HL, 0x9966);

        std::cout << "CPU setup" << std::endl;
    }

    CPU::~CPU()
    {
    }

    uint16_t CPU::getRegistre(RegType r)
    {
        switch (r)
        {
        case R_NONE:
            return 0;
        case R_A:
            return regs.a;
        case R_F:
            return regs.f;
        case R_B:
            return regs.b;
        case R_C:
            return regs.c;
        case R_D:
            return regs.d;
        case R_E:
            return regs.e;
        case R_H:
            return regs.h;
        case R_L:
            return regs.l;
        //
        case R_AF:
            return (regs.a << 8) | regs.f;
        case R_BC:
            return (regs.b << 8) | regs.c;
        case R_DE:
            return (regs.d << 8) | regs.e;
        case R_HL:
            return (regs.h << 8) | regs.l;

        case R_SP:
            return regs.sp;
        case R_PC:
            return regs.pc;
        }
        return 0;
    };

    void CPU::setReg(RegType r, uint16_t val)
    {
        switch (r)
        {
        case R_A:
            regs.a = val & 0xFF;
            break;
        case R_F:
            regs.f = val & 0xF0; //f : ZNHC0000
            break;
        case R_B:
            regs.b = val & 0xFF;
            break;
        case R_C:
            regs.c = val & 0xFF;
            break;
        case R_D:
            regs.d = val & 0xFF;
            break;
        case R_E:
            regs.e = val & 0xFF;
            break;
        case R_H:
            regs.h = val & 0xFF;
            break;
        case R_L:
            regs.l = val & 0xFF;
            break;

        case R_AF:
            regs.a = (val & 0xFF00) >> 8;
            regs.f = val & 0xFF;
            break;
        case R_BC:
            regs.b = (val & 0xFF00) >> 8;
            regs.c = val & 0xFF;
            break;
        case R_DE:
            regs.d = (val & 0xff00) >> 8;
            regs.e = val & 0xff;
            break;
        case R_HL:
            regs.h = (val & 0xff00) >> 8;
            regs.l = val & 0xff;
            break;

        case R_PC:
            regs.pc = val;
            break;
        case R_SP:
            regs.sp = val;
            break;
        case R_NONE:
            break;
        }
    }

    void CPU::setFlags(uint8_t z, uint8_t n, uint8_t h, uint8_t c){
        if (z != -1)
        {
            if (z) regs.f |= (1 << 7);else regs.f &= ~(1 << 7);
        }
        if (n != -1)
        {
            if (n) regs.f |= (1 << 6);else regs.f &= ~(1 << 6);
        }
        if (h != -1)
        {
            if (h) regs.f |= (1 << 5);else regs.f &= ~(1 << 5);
        }
        if (c != -1)
        {
            if (c) regs.f |= (1 << 4);else regs.f &= ~(1 << 4);
        }
    }
}
