#include <iostream>
#include <string>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& query) {
    for (const auto& element : arr) {
        if (element == query)
            return true;
    }
    return false;
}

int main() {
    std::vector<std::string> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::vector<int> nums {1, 2, 3, 4, 6};
    int userNum { 0 };
    std::string userName {};
    std::cout << "Enter a name: ";
    std::cin >> userName;
    std::cout << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> userNum;
    std::cout << std::endl;

    std::cout << "Was your name found? " << isValueInArray(names, userName) << std::endl;
    std::cout << "Was your number found? " << isValueInArray(nums, userNum) << std::endl;

    return 0;

    /*
    
    for (std::string_view name: names) {
        if (userName == name) {
            nameFound = true;
        }
    }
    if (nameFound == true)
        std::cout << userName << " was found.";
    else 
        std::cout << userName << " was not found.";

    return 0;
    */
    
}