#include "CaesarCipher.hpp"

#include <string>
#include <numeric>
using std::string;
#include <iostream>

void CaesarCipher::cipherWithCaesar(std::promise<string>&& cipherText, string plainText, int moveBy)
{
    auto movingFunc = [moveBy](auto& init, auto& current){
        int range = ('Z' - 'A' + 1);
        return std::move(init) + static_cast<char>((current - 'A' + moveBy) % range + 'A');
    };

    string finalResult{""};
    finalResult = std::accumulate(plainText.begin(), plainText.end(), finalResult, movingFunc);

    cipherText.set_value(finalResult);
}
