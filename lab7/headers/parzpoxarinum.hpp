#ifndef PARZPOXARINUM_HPP
#define PARZPOXARINUM_HPP

#include <string>

class ParzPoxarinum {
public:
    ParzPoxarinum() = default;
    std::string encrypt(const std::string& text, const std::string& key);
    std::string decrypt(const std::string& text, const std::string& key);
};

#endif