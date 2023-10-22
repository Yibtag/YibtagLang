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

bool Util::write_file(std::string path, std::string content) {
    std::ofstream file(path);

    if (!file.is_open()) {
        return false;
    }

    file << content;
    file.close();

    return true;
}