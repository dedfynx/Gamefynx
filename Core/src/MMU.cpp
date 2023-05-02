#include "MMU.h"

#include <iostream>

namespace Gamefynx
{
    MMU::MMU()
    {
        vram.resize(0x2000);
        wram.resize(0x2000);
        oam.resize(0xA0);
        hram.resize(0x7F);
        std::cout << "MMU setup" << std::endl;

    }
    MMU::~MMU()
    {
    }
    uint8_t MMU::BusRead(uint16_t address)
    {
        if (address < 0x8000)//ROM
        {
            return cartouche.read(address);
        }
        if (address < 0xA000)//VRAM
        {
            return vram[address - 0x8000];
        }
        if (address < 0xC000)//SRAM
        {
            std::cout << "SRAM Pas Fait" << std::endl;
            std::exit(0);
        }
        if (address < 0xE000)//WRAM
        {
            std::cout << "WRAM Pas Fait" << std::endl;
            std::exit(0);
        }
        if (address < 0xFE00)//Echo RAM
        {
            std::cout << "Echo RAM Pas Fait" << std::endl;
            std::exit(0);
        }
        if (address < 0xFEA0)//OAM
        {
            std::cout << "OAM Pas Fait" << std::endl;
            std::exit(0);
        }
        if (address < 0xFEFF)//Not Usable
        {
            return 0xFF;
        }
        if (address < 0xFF80)//IO
        {
            std::cout << "IO Pas Fait" << std::endl;
            std::exit(0);
        }
        if (address < 0xFFFF)//HRAM
        {
            return hram[address-0xff80];
        }

        std::cout << "IE Pas Fait" << std::endl;
        std::exit(0);
    }
    void MMU::BusWrite(uint16_t address, uint8_t value)
    {
        if (address < 0x8000)
        {
            cartouche.write(address, value);
            return;
        }
        std::cout << "Pas Fait" << std::endl;
        std::exit(0);
    }
}
