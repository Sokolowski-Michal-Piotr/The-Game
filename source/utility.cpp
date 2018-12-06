#include "utility.hpp"

std::string my::utility::strip(const std::string & path, const size_t level)
{
    size_t marker = std::string::npos;
    for (size_t i = 0; i <= level; i++)
        marker = path.find_last_of("\\/", marker) - 1;
    return path.substr(0, marker + 2);
}
