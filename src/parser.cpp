#include "parser.hpp"

#include "logger.hpp"

// PUBLIC

std::optional<NodeExpr> Parser::parse_expr() {
    if (peek().has_value() && peek().value().type == TokenType::inta) {
        return NodeExpr(consume());
    }

    return {};
}

std::optional<NodeExit> Parser::parse() {
    std::optional<NodeExit> result;

    while (peek().has_value()) {
        if (peek().value().type == TokenType::exit) {
            consume();

            if (auto node_expr = parse_expr()) {
                result = NodeExit(node_expr.value());
            } else {
                logger->error("Exit must be followed by an expression!");
            }

            if (!peek().has_value() || peek().value().type != TokenType::semi) {
                logger->error("Missing \';\' !");
            }

            consume();
        }
    }

    m_index = 0;
    return result;
}

// PRIVATE

std::optional<Token> Parser::peek(int offset) const {
    if (m_index + offset >= m_tokens.size()) {
        return {};
    }

    return m_tokens.at(m_index + offset);
}

Token Parser::consume() {
    return m_tokens.at(m_index++);
}