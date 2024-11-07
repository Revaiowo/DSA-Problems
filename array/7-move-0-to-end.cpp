#include <iostream>
#include <vector>
#include <algorithm>    

void move0ToEnd(std::vector<int>& arr) {

    int j { };

    for (int i=0; i<arr.size(); i++) {

        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    for (int i=j+1; i<arr.size(); i++) {

        if (arr[i] != 0) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
}
 
int main() {

    std::vector<int> arr { 2, 1, 5, 0, 0, 0, 0, 1, 0, 0, 44, 2, 1, 0, 0, 4, 0 };

    move0ToEnd(arr);

    for (int i : arr) {

        std::cout <<i << ' ';
    }

    return 0;
}