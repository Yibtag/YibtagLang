#pragma once

#include <optional>
#include <string>

// TOKEN

enum class TokenType {
    illegal,
    exit,
    inta,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

// NODES

struct NodeExpr {
    Token inta;
};

struct NodeExit {
    NodeExpr expresion;
};