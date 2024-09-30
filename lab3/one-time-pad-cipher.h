#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
public:
    virtual std::string encrypt(const std::string& text, const std::string& key) = 0;
    virtual std::string decrypt(const std::string& text, const std::string& key) = 0;
    virtual ~Cipher() = default;
};

class OneTimePadCipher : public Cipher {
public:
    OneTimePadCipher() = default;
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
};

#endif