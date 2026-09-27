#include <iostream>
#include <vector>

int main() {
    std::vector<char> myString {'h', 'e', 'l','l','o'};
    std::cout << "This array has: " << std::size(myString) << " elements." << std::endl;
    std::cout << myString[1] << myString.at(1);
    return 0;
}