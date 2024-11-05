#ifndef MIXENCRYPT_HPP
#define MIXENCRYPT_HPP

#include <string>

#include "parzpoxarinum.hpp"
#include "rle.hpp"

class mixEncrypt {
    friend class ParzPoxarinum;
    friend class RunLengthEncoding;
public:
    mixEncrypt() = default;
    std::string encrypt(const std::string& text, const std::string& key);
    std::string decrypt(const std::string& text, const std::string& key);
};

#endif