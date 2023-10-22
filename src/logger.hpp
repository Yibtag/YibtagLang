#pragma once

#include <memory>

class Logger {
public:
    void info(const char* info);
    void warning(const char* warning);
    void error(const char* error);
};

inline std::unique_ptr<Logger> logger;