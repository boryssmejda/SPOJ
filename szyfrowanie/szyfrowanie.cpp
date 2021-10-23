#include "szyfrowanie.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>

bool isPrimeNumber(const uint32_t t_number)
{
    if (t_number <= 1)
    {
        return false;
    }
    else if (2 == t_number)
    {
        return true;
    }

    for (const uint32_t i : std::views::iota(2u, t_number))
    {
        if (t_number % i == 0)
        {
            return false;
        }
    }

    return true;
}

BrokenCiffreOrIllegibleText breakTheCiffre(const std::vector<uint32_t>& t_encryptedMessage)
{
    const auto primeNumBeginning{120u};
    const auto primeNumbersEnd{150u};
    auto primeNumbers = std::ranges::iota_view{primeNumBeginning, primeNumbersEnd + 1}
                      | std::views::filter(isPrimeNumber);

    auto decrypt = [&t_encryptedMessage](const auto primeNumber){
        auto applyModulo = [primeNumber](const auto letter){
            return letter % primeNumber;
        };

        auto decryptedMessage = t_encryptedMessage | std::views::transform(applyModulo);

        return std::pair{primeNumber, decryptedMessage};
    };
    
    auto isValid = [](const auto& vecPair){
        auto& [key, vec] = vecPair;
        return std::all_of(vec.begin(), vec.end(), [](const auto letter){
            return letter >= 'A' && letter <= 'Z';
        });
    };

    auto convertToString = [](const auto& vecPair){
        auto& [key, vec] = vecPair;
        std::pair<uint32_t, std::string> messageWithKey{
            key, std::string{vec.begin(), vec.end()}
        };

        return messageWithKey;
    };

    auto decryptedMessageView = primeNumbers | std::views::transform(decrypt)
                                             | std::views::filter(isValid)
                                             | std::views::transform(convertToString);

    if (!decryptedMessageView.empty())
    {
        auto [key, message] = decryptedMessageView.front();
        BrokenCiffre ciffre{key, message};
        return ciffre;
    }
    else
    {
        return std::string("NIECZYTELNE");
    }
}
