#include <iostream>
#include <vector>
#include <cassert>

namespace Animals{
    enum Pets {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxAnimals,
    };
}

int main() {
    std::vector<int> legs{2, 4, 4, 4, 2, 0};
    assert(std::size(legs) == Animals::Pets::maxAnimals);

    std::cout << "Elephant legs: " << legs[static_cast<int>(Animals::Pets::elephant)];

    return 0;
}