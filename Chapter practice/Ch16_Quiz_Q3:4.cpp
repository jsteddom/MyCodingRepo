#include <iostream>
#include <vector>
#include <utility>

template <typename T>
std::pair<T,T> minMaxVector(const std::vector<T>& vect) {
    double min {vect[0]};
    double max {vect[0]};

    for(const auto& index: vect) {
        if (index < min)
            min = index;
        if (index > max) 
            max = index;
    }
    return {min, max};
}
template <typename T>
void print(const std::vector<T>& printVector) {
    bool comma { false };
    std::cout << "Elements: (";
    for (const auto& element:printVector) {
        if (comma)
            std::cout << ", ";
        std::cout << element;
        comma = true;
    }
    std::cout << ").";

}

int main() {
    std::vector<double> nums;
    double userInput { 0 };
    std::cout << "Enter non-negative numbers to add (use -1 to stop): ";
    while(userInput != -1) {
        std::cin >> userInput;
        if (userInput < 0) {
            std::cout << "please enter positive numbers" << std::endl;
            continue;
        }
        nums.push_back(userInput);
    }
    std::pair minMax { minMaxVector(nums) };
    print(nums);
    std::cout << "The minimum element: " << minMax.first << "\nThe maximum element: " << minMax.second;
    return 0;
}