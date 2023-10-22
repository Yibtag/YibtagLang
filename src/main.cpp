#include <iostream>
#include <string.h>
#include <string>

#include "generator.hpp"
#include "tokenizer.hpp"
#include "parser.hpp"

#include "logger.hpp"
#include "util.hpp"

int main(int argc, char* argv[]) {
    logger = std::make_unique<Logger>();

    if (argc != 2) {
        logger->error("Incorrect usage: yiblang <source.yb>");
    }

    const std::string file = argv[1];

    if (file.empty()) {
        logger->error("Invalid file supplied in secound parameter!");
    }

    if (file.substr(file.find_first_of(".") + 1) != "yb") {
        logger->error("Invalid file extention!");
    }

    const std::string contents = Util::read_file(file);

    if (contents.empty()) {
        logger->error("File provided was empty or invalid!");
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeExit> program = parser.parse();

    if (!program.has_value()) {
        logger->error("Failed to parse the program!");
    }

    Generator generator(std::move(program.value()));
    std::string generated =  generator.generate();

    if (!Util::write_file("out.asm", generated)) {
        logger->error("Unable to create output file!");
    }

    system("nasm -felf64 out.asm");
    system("ld -o out out.o");

    logger->info("Compiled succesfuly!");

    return EXIT_SUCCESS;
}