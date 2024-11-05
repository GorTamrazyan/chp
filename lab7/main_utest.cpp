#include "headers/mixEncrypt.hpp"

#include <gtest/gtest.h>

TEST(mixEncrypt, crypt) 
{
    const std::string text = "barev bolorin";
    const std::string key =  "ashakertnerik";
    mixEncrypt crypt;
    std::string result = crypt.encrypt(text, key);
    std::cout << result << std::endl;
    result = crypt.decrypt(result, key);
    std::cout << result << std::endl;
    
}

int
main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

