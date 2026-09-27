#include <iostream>
#include <vector>

void printMyStack(const std::vector<int>& myStack){
    if (myStack.empty()) {
        std::cout << "(Stack: empty)" << std::endl;
    }
    else {
        std::cout << "(Stack: ";
        for (auto index: myStack) {
            std::cout << index << " ";
        }
        std::cout << ")" << std::endl;
    }
}
void pushPopStack(std::vector<int>& myStack, int val, int choice=0){
    if (choice == 1 && val >= 0) {
        myStack.push_back(val);
        std::cout << "Push " << val;
    }
    else {
        myStack.pop_back();
        std::cout << "Pop";
    }
}


int main() {
    std::vector<int> myStack;
    printMyStack(myStack);
    pushPopStack(myStack, 1, 1);

    printMyStack(myStack);
    pushPopStack(myStack, 2, 1);
    printMyStack(myStack);
    pushPopStack(myStack, 3, 1);
    printMyStack(myStack);
    pushPopStack(myStack, -1, 0);
    printMyStack(myStack);
    pushPopStack(myStack, 4, 1);
    printMyStack(myStack);
    pushPopStack(myStack, -1, 0);
    printMyStack(myStack);
    pushPopStack(myStack, -1, 0);
    printMyStack(myStack);
    pushPopStack(myStack, -1, 0);
    printMyStack(myStack);

    return 0;
}