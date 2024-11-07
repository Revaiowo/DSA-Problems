#include <iostream>
#include <vector>

int countOnes(std::vector<int>& arr) {

    int first { };
    int second { };

    for (int i=0; i<arr.size(); i++) {

        if (arr[i] == 1)
            first++;

        if (first > second) 
            second = first;
        
        if (arr[i] == 0)
            first = 0;
    }

    return second;
}

int main() {

    std::vector arr { 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

    int result { countOnes(arr) };

    std::cout <<result;

    return 0;
}