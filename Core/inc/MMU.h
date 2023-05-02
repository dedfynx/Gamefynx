#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "Cartouche.h"

namespace Gamefynx
{
    class MMU
    {
    public:
        MMU();
        ~MMU();
        uint8_t BusRead(uint16_t address);
        void BusWrite(uint16_t address, uint8_t value);

        void loadCartouche(std::string path){
            cartouche.load(path);
        }
    private:
        Cartouche cartouche;
        std::vector<uint8_t> vram{}; //8Kib | 32Kib (GBC) Video Ram $8000-9FFF
        std::vector<uint8_t> wram{}; //8Kib | 16Kib (GBC) Work Ram  $C000-CFFF Bank 0/$D000-DFFF Bank 1-7
        std::vector<uint8_t> oam{};  //Object Attribute Memory $FE00-FE9F
        std::vector<uint8_t> hram{}; //High Ram $FF80-FFFE
    };
}
