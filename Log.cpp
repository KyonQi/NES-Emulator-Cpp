#include "Log.h"

namespace ns {
    Log::Log() {
        init(LEVEL_NONE);
    }

    void Log::set_level(LEVEL level) {
        this->m_log_level = level;
    }

    void Log::set_stream(std::ostream &stream) {
        this->m_log_stream = &stream;
    }

    void Log::init(LEVEL level, std::ostream &stream) {
        set_level(level);
        set_stream(stream);
    }

    Log& Log::get_instance() {
        static Log instance;
        return instance;
    }

    LEVEL Log::get_level() {
        return m_log_level;
    }

    std::ostream& Log::get_stream() {
        return *m_log_stream;
    }

    Log::~Log() {
    }  
}



