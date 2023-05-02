#pragma once

#include <cstdint>
#include <string>

#include "CPU.h"
#include "MMU.h"

namespace Gamefynx
{
    class Emulator
    {
    public:
        Emulator(std::string filepath);
        ~Emulator();

        CPU cpu{};
        MMU mmu{};
    private:
        
    };
}
