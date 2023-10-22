#include "logger.hpp"

#include <iostream>

void Logger::info(const char* info) {
    std::cout << info << std::endl;
}

void Logger::warning(const char* warning) {
    std::cout << warning << std::endl;
}

void Logger::error(const char* error) {
    std::cerr << error << std::endl;
    
    exit(EXIT_FAILURE);
}