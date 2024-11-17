#pragma once

#include <vector>
#include <cstdint>

namespace ns {
    using Byte = std::uint8_t;
    using Address = std::uint16_t;

    class Cartridge {
        private:
            std::vector<Byte> m_prg_rom;
            std::vector<Byte> m_chr_rom;
            Byte m_mapper;
    
        public:
            const std::vector<Byte>& get_prg_rom();
            const std::vector<Byte>& get_chr_rom();
            const Byte get_mapper();
    };
}