#pragma once

#include "defines.hpp"

class Generator {
public:
    inline Generator(NodeExit root) : m_root(std::move(root)) { }

    std::string generate() const;
private:
    const NodeExit m_root;
};