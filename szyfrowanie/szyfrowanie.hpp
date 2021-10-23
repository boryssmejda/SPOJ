#include <cstdint>
#include <string>
#include <variant>
#include <vector>
#include <utility>

struct BrokenCiffre
{
    uint32_t key;
    std::string decryptedMessage;
};

using IllegibleText = std::string;

using BrokenCiffreOrIllegibleText = std::variant<BrokenCiffre, IllegibleText>;

BrokenCiffreOrIllegibleText breakTheCiffre(const std::vector<uint32_t>& t_encryptedMessage);

bool isPrimeNumber(const uint32_t t_number);
