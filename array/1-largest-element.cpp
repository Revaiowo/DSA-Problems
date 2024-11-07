#include <iostream>
#include <vector>

int largestElement(std::vector<int>& arr) {

    int largest { 0 };

    for (int i=0; i<arr.size(); i++) {

        if (arr[largest] < arr[i]){
            largest = i;
        }
    }

    return largest;
}

int main(){

    std::vector<int> arr { 4, 8, 22, 1, 7, 888 };

    int result { largestElement(arr) };

    std::cout <<arr[result];

    return 0;
}