#include <iostream>
#include <vector>
#include <unordered_map>

int numberAppearOnce(std::vector<int>& arr) {

    std::unordered_map<int, int> hashArr { };

    for (int i=0; i<arr.size(); i++)
        hashArr[arr[i]]++;

    for (auto& i : hashArr){

        if (i.second == 1)
            return i.first;
    }

    return -1;
}

int main() {

    std::vector<int> arr { 5, 1, 1, 5,3, 3, 8, 7 , 7};

    int result { numberAppearOnce(arr) };

    std::cout <<result;

    return 0;

}