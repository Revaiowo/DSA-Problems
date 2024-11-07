#include <iostream>
#include <vector>

void leftRotateBy1(std::vector<int>& arr) {
    
    int j { arr[0] };

    for (int i=0; i<arr.size(); i++) {

        arr[i] = arr[i+1];
    }

    arr[arr.size()-1] = j;
}

int main() {

    std::vector<int> arr { 3, 6, 2, 1, 7, 20, 12, 2 };

    leftRotateBy1(arr);

    for (int i : arr)
        std::cout <<i <<' ';

    return 0;
}