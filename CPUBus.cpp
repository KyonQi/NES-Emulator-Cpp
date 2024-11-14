#include "CPUBus.h"

namespace ns {
    CPUBus::CPUBus() : m_RAM(0x0800, 0) {
    }
    
    Byte CPUBus::read(Address address) {
        if (address < 0x2000) {
            // deal with RAM mirroring
            return m_RAM[address & 0x07ff];
        } else if (address < 0x6000) {
            // do nothing here temporarily
            // related with PPU, registers, etc.
            return 0;
        } else if (address < 0x8000) {
            // deal with cartridge RAM, i.e., extRAM
            // maybe let mapper manage
            // return m_extRAM[address - 0x6000];
            return 0;
        }  else {
            // related with PRG ROM
            // mapper will deal with this range
            return 0;
        }
    }

    void CPUBus::write(Address address, Byte data) {
        if (address < 0x2000) {
            m_RAM[address & 0x07ff] = data;
        } else if (address < 0x6000) {
            // do nothing here temporarily
            // related with PPU, registers, etc
        } else if (address < 0x8000) {
            // deal with cartridge RAM, i.e., extRAM
            // maybe let mapper manage
        } else {
            // related with PRG ROM
            // mapper will deal with this range
        } 
    }
    
    
    

}