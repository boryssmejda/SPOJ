#ifndef _CAESAR_CIPHER_HPP_
#define _CAESAR_CIPHER_HPP_

#include <string>
#include <future>
#include <thread>

using std::string;

class CaesarCipher
{
    private:
        CaesarCipher() = default;

    public:
        static void cipherWithCaesar(std::promise<string>&& cipherText, string plainText, int moveBy);

};

#endif