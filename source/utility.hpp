#pragma once

#include <string>

namespace my
{
    namespace utility
    {
        constexpr double pi = 3.141592653589793238462643383279502884;
        constexpr float pif = static_cast<float>(pi);
        constexpr double pi2 = 2 * pi;
        constexpr float pif2 = static_cast<float>(pi2);

        std::string strip(const std::string& path, const size_t level = 0);
    }
}
