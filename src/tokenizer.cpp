#include "tokenizer.hpp"

#include "logger.hpp"

// PUBLIC

std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> result;
    std::string buffer;

    while (peek().has_value()) {
        // Keywords
        if (std::isalpha(peek().value())) {
            buffer.push_back(consume());

            while (peek().has_value() && std::isalnum(peek().value())) {
                buffer.push_back(consume());
            }

            Token keyword = handle_keyword(buffer);

            if (keyword.type == TokenType::illegal) {
                logger->error("Illegal keyword!");
                return result;
            } else {
                result.push_back(keyword);
                buffer.clear();
                continue;
            }
        }

        // Intagers
        if (std::isdigit(peek().value())) {
            buffer.push_back(consume());

            while (peek().has_value() && std::isdigit(peek().value())) {
                buffer.push_back(consume());
            }

            result.push_back({.type = TokenType::inta, .value = buffer});
            buffer.clear();
            continue;
        }

        if (peek().value() == ';') {
            consume();
            result.push_back({.type = TokenType::semi});
            continue;
        }

        // White space
        if (std::isspace(peek().value())) {
            consume();
            continue;
        }

        logger->error("Syntax error!");
    }

    m_index = 0;
    return result;
}

// PRIVATE

std::optional<char> Tokenizer::peek(int offset) const {
    if (m_index + offset >= m_source.length()) {
        return {};
    }

    return m_source.at(m_index + offset);
}

char Tokenizer::consume() {
    return m_source.at(m_index++);
}

Token Tokenizer::handle_keyword(std::string keyword) {
    if (keyword == "exit") {
        return {.type = TokenType::exit, .value = {}};
    } else {
        return {.type = TokenType::illegal};
    }
}

