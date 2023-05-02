#include "Emulator.h"

namespace Gamefynx
{
    Emulator::Emulator(std::string filepath){


        mmu.loadCartouche(filepath);
    }

    Emulator::~Emulator(){

    }
}