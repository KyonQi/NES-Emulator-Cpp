#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <memory>

#ifndef __FILENAME__
#define __FILENAME__ __FILE__
#endif

#define LOG(level) \
if (level > ns::Log::get_instance().get_level()) ; \
else ns::Log::get_instance().get_stream() << "[" << __FILENAME__ << ":" << std::dec << __LINE__ << "]" \
                                          << "[" << ns::level_to_string(level) << "]: "

namespace ns {
    enum LEVEL {
        LEVEL_NONE,
        LEVEL_ERROR,
        LEVEL_WARNING,
        LEVEL_DEBUG,
        LEVEL_INFO,
    };

    inline const char* level_to_string(LEVEL level) {
        switch (level)
        {
        case LEVEL_NONE: return "NONE";
        case LEVEL_ERROR: return "ERROR";
        case LEVEL_WARNING: return "WARNING";
        case LEVEL_DEBUG: return "DEBUG";
        case LEVEL_INFO: return "INFO";
        default: return "UNKNOWN";
        }
    }

    class Log {
        private:
            Log();
            void set_level(LEVEL level);
            void set_stream(std::ostream &stream);
        private:
            LEVEL m_log_level;
            std::ostream *m_log_stream; // store the pointer of stream

        public:
            void init(LEVEL level, std::ostream &stream = std::cout);
            static Log& get_instance(); // provide one instance only
            LEVEL get_level();
            std::ostream& get_stream();
            ~Log();
    };
}