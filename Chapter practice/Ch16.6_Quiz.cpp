#include <iostream>
#include <vector>

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T>& arr, size_t index) {
    for (size_t index { 0 }; index < size(arr); index++) {
        std::cout << arr[index] << ' ';
    }
    if (index >= arr.size()) {
        std::cout << "\nThe number " << index << " was not found";
    }
    else {
        std::cout << "\nThe number " << index << " has index " << arr[index];
    }
    
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    int userVal { 0 };
    do 
    {  
        std::cout << "Enter a value between 1 & 9\n";
        std::cin >> userVal; 
        std::cout << "userVal: " << userVal;
    } while (userVal < 0 && userVal > arr.size() - 1);
    printArray(arr, static_cast<size_t>(userVal)); // use function template to print array

    return 0;
}