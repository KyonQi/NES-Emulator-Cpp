#include "Cartridge.h"

namespace ns {
    const std::vector<Byte>& Cartridge::get_prg_rom() {
        return m_prg_rom;
    }

    const std::vector<Byte>& Cartridge::get_chr_rom() {
        return m_chr_rom;
    }

    const Byte Cartridge::get_mapper() {
        return m_mapper;
    } 
}