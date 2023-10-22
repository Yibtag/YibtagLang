#include "util.hpp"

#include <string.h>
#include <fstream>
#include <sstream>

std::string Util::read_file(std::string path) {
    std::fstream file(path);
    std::ostringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}