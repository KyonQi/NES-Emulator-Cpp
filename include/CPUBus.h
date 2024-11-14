#pragma once
#include <vector>
#include <cstdint>

namespace ns {
    using Byte = std::uint8_t;
    using Address = std::uint16_t;

    class CPUBus {
        private:
            std::vector<Byte> m_RAM; // CPU RAM: 0x0 - 0x0800, 2KB
            // std::vector<Byte> m_extRAM; // cartridge RAM: 0x6000 - 0x8000, 8KB
            // lack of mapper now
            
        public:
            CPUBus(); // allocate the CPU RAM
            Byte read(Address address);
            void write(Address address, Byte data);
            
    };
    
}