#include <iostream>
#include <vector>

bool sortedOrNot(std::vector<int>& arr) {

    for(int i=0; i<arr.size()-1; i++) {

        if (arr[i] > arr[i+1])
            return false;
    }

    return true;
}

int main() {

    std::vector<int> arr { 2, 5, 8, 9, 10, 13, 15, 20, 33, 35, 44 };

    bool isSorted { sortedOrNot(arr) };

    std::cout <<std::boolalpha;
    std::cout <<isSorted;

    return 0;
}