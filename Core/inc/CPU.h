#pragma once
#include <cstdint>

namespace Gamefynx
{
	struct Registre
	{
		uint8_t a;
		uint8_t f;
		uint8_t b;
		uint8_t c;
		uint8_t d;
		uint8_t e;
		uint8_t h;
		uint8_t l;
		uint16_t sp;
		uint16_t pc;
	};
	

	class CPU
	{
	public:
		CPU();
		~CPU();
		
		enum RegType
        {
            R_NONE,
            //8 bits
            R_A,
            R_F,
            R_B,
            R_C,
            R_D,
            R_E,
            R_H,
            R_L,
            //16 bits
            R_AF,
            R_BC,
            R_DE,
            R_HL,
            R_SP,
            R_PC
        };
		uint16_t getRegistre(RegType reg);
		void setReg(RegType r, uint16_t val);
		void setFlags(uint8_t z, uint8_t n, uint8_t h, uint8_t c);
		uint8_t flagZ(){return (regs.f & 1 << 7 ? 1:0);};
		uint8_t flagN(){return (regs.f & 1 << 6 ? 1:0);};
		uint8_t flagH(){return (regs.f & 1 << 5 ? 1:0);};
		uint8_t flagC(){return (regs.f & 1 << 4 ? 1:0);};

	private:
		Registre regs;
	};
}