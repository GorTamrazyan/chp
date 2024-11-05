#include "../headers/mixEncrypt.hpp"


std::string
mixEncrypt::encrypt(const std::string& text, const std::string& key)
{
    ParzPoxarinum code;
    RunLengthEncoding rle;
    std::string result;
    result = code.encrypt(text,key);
    result = rle.encode(result);
    return result;
}

std::string
mixEncrypt::decrypt(const std::string& text, const std::string& key)
{
    ParzPoxarinum code;
    RunLengthEncoding rle;
    std::string result;
    result = rle.decode(text);
    result = code.decrypt(result,key);
    return result;
}