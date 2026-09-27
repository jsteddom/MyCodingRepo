#include <iostream>
#include <vector>




// Write your printElement function here
template <typename T>
void printElement(const std::vector<T>& toPrint, const int index) {
    //std::cout << "\nVector size: " << toPrint.size() << "\n";
    if (index >= toPrint.size()) {
        std::cout << "Invalid index" << std::endl;
    }
    else {
        std::cout << "The element has a value of: " << toPrint[index] << std::endl;
    }
}


int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}