#include <iostream>
#include <vector>

int removeDuplicateAndReturnKey(std::vector<int>& arr) {

    int j { 0 };

    for (int i=0; i<arr.size(); i++) {

        if (arr[i] != arr[j])
            arr[++j] = arr[i];
    }
    return j;
}

int main() {

    std::vector<int> arr { 1, 1, 1, 2, 2, 2, 2, 6, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 12, 18, 18 };

    int result = removeDuplicateAndReturnKey(arr);

    for (int i=0; i<=result; i++)
        std::cout <<arr[i] << ' ';

    return 0;
}