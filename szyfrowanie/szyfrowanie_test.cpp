#include "szyfrowanie.hpp"

#include <cassert>
#include <iostream>
#include <variant>

struct VisitPackage
{
    void operator()(BrokenCiffre& bc) { std::cout << bc.key << " " << bc.decryptedMessage << std::endl; }
    void operator()(std::string& s) { std::cout << s << std::endl; }
};

int main()
{
    assert(!isPrimeNumber(0));
    assert(!isPrimeNumber(1));
    assert(isPrimeNumber(2));
    assert(isPrimeNumber(3));
    assert(!isPrimeNumber(4));
    assert(isPrimeNumber(5));
    assert(!isPrimeNumber(6));
    assert(isPrimeNumber(7));
    assert(!isPrimeNumber(8));

    const std::vector<uint32_t> message {720, 739, 477, 327, 984, 730};
    auto brokenCiffre = breakTheCiffre(message);

    std::visit(VisitPackage(), brokenCiffre);

    const std::vector<uint32_t> message2 {100, 100, 100};
    brokenCiffre = breakTheCiffre(message2);

    std::visit(VisitPackage(), brokenCiffre);

    const std::vector<uint32_t> message3 {822, 973, 381, 224, 824, 683};
    brokenCiffre = breakTheCiffre(message3);

    std::visit(VisitPackage(), brokenCiffre);
}
