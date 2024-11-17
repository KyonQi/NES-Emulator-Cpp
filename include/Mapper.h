#pragma once

#include <memory>
#include <Cartridge.h>

namespace ns {
    class Mapper {
        protected:
            std::shared_ptr<Cartridge> m_cartridge;

        public:
            Mapper(std::shared_ptr<Cartridge> cartridge);
            virtual Byte read_prg(Address address) = 0;
            virtual Byte read_chr(Address address) = 0;
            virtual void write_prg(Address address, Byte data) = 0;
            virtual void write_chr(Address address, Byte data) = 0;
    };  
}