#pragma once

#include <vector>

#include "defines.hpp"

class Parser {
public:
    inline Parser(std::vector<Token> tokens) : m_tokens(std::move(tokens)) { }

    std::optional<NodeExpr> parse_expr();
    std::optional<NodeExit> parse();
private:
    const std::vector<Token> m_tokens;
    int m_index = 0;

    std::optional<Token> peek(int offset = 0) const;
    Token consume();
};