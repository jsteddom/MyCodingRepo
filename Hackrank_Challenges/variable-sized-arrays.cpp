#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numQs { 0 };
    int numArrs { 0 };
    std::cin >> numQs;
    std::cin >> numArrs;
    std::vector<std::vector<int>> list;
    int arrLen { 0 };
    int numsQCount { numQs };
    do {
        std::cin >> arrLen;
        std::vector<int> k(arrLen);
        for (int index { 0 }; index < arrLen; ++index) {
            std::cin >> k[index];
        }
        list.push_back(k);
        //std::cout << k[k.size() - 1] << std::endl;
        --numsQCount;
    } while(numsQCount > 0);
    do {
        int arrIndex { 0 };
        int index { 0 };
        std::cin >> arrIndex;
        std::cin >> index;
        std::cout << list[arrIndex][index];
        --numQs;
        std::cout << std::endl;
    } while(numQs > 0);
    std::cout << "reached end";
    return 0;
}