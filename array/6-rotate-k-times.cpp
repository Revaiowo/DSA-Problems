#include <iostream>
#include <vector>

std::vector<int> rotate(std::vector<int>& arr, int num, bool left) {
    
    std::vector<int> temp { };

    int k = left ? num : arr.size() - num; // rotates right if left is false

    for (int i=k; i<arr.size(); i++)
        temp.push_back(arr[i]);

    for (int i=0; i<k; i++)
        temp.push_back(arr[i]);

    return temp;
}

int main() {

    std::vector<int> arr { 3, 6, 2, 12, 2 }; 
    int k { 2 };
    bool left { false };

    std::vector<int> newArr { rotate(arr, k, left) };

    for (int i : newArr)
        std::cout <<i <<' ';

    return 0;
}