#include "Log.h"


int main(int argc, char **argv) {
    std::ofstream log_file("myNES.log");
    if (log_file.is_open() && log_file.good()) 
        ns::Log::get_instance().init(ns::LEVEL_INFO, log_file);
    LOG(ns::LEVEL_DEBUG) << "Test the Log." << std::endl;
    return 0;
}