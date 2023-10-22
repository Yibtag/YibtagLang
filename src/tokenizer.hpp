#pragma once

#include <optional>
#include <vector>
#include <string>

#include "defines.hpp"

class Tokenizer {
public:
    inline Tokenizer(const std::string& source) : m_source(std::move(source)) {}

    std::vector<Token> tokenize();
private:
    const std::string m_source;
    int m_index = 0;

    std::optional<char> peek(int offset = 0) const;
    char consume();

    Token handle_keyword(std::string keyword);
};