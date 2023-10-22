#include <string>

namespace Util {
    std::string read_file(std::string path);
    bool write_file(std::string path, std::string content);
}