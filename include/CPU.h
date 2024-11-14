#pragma once
#include <memory>

#include "CPUBus.h"
#include "Opcodes.h"

namespace ns {
    struct f_P {
        Byte C: 1; // bit 0, carry bit
        Byte Z: 1; // bit 1, zero bit
        Byte I: 1; // bit 2, interrupt disable
        Byte D: 1; // bit 3, decimal mode
        Byte B: 1; // bit 4, brk
        Byte U: 1; // bit 5, unused
        Byte V: 1; // bit 6, overflow
        Byte N: 1; // bit 7, negative
    };

    class CPU {
        private:
            // CPU bus
            std::shared_ptr<CPUBus> m_bus; 
            // registers
            Address m_r_PC; // program counter
            Byte m_r_SP; // stack pointer
            Byte m_r_A; // accumulator
            Byte m_r_X; // index X
            Byte m_r_Y; // index Y
            f_P  m_r_PS; // process status

        public:
            CPU(std::shared_ptr<CPUBus> bus);
            void step(); // simulate the clock
            void reset(); // reset the cpu at the beginning
            void execute();
    };
}