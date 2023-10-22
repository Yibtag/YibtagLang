#include "generator.hpp"

#include <sstream>

std::string Generator::generate() const {
    std::stringstream result;
    result << "global _start\n_start:\n";
    result << "    mov rax, 60\n";
    result << "    mov rdi, " << m_root.expresion.inta.value.value() << "\n";
    result << "    syscall";
    
    return result.str();
}