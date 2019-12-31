#include <iostream>
#include <thread>
#include <future>
#include "CaesarCipher.hpp"
#include <string>
using std::string;

#include <vector>
using std::vector;

int main(void)
{   

    vector<string> v;

    while(!std::cin.eof())
    {
        string s;
        std::cin >> s;
        v.push_back(std::move(s));
    }

    for(auto& s: v)
    {
        std::promise<string> cipherPromise;
        std::future<string> cipheredTextFuture = cipherPromise.get_future();
        std::thread myThread(CaesarCipher::cipherWithCaesar, std::move(cipherPromise), s, 3);
        std::cout << cipheredTextFuture.get() << "\n";
        myThread.join();
    }
    return 0;
}