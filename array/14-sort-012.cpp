#include <iostream>
#include <vector>
#include <algorithm>

void sortArray(std::vector<int>& arr){

    int low { 0 };
    int mid { 0 };
    int high { arr.size()-1 };

    while (mid <= high){

        if (arr[mid] == 0){
            std::swap(arr[low++], arr[mid++]);
        }

        else if (arr[mid] == 1){
            mid++;
        }
        
        else if (arr[mid] == 2){
            std::swap(arr[mid], arr[high--]);
        }
    }
}

int main(){

    std::vector<int> arr { 1, 2, 2, 0, 0, 1, 2, 0 };

    sortArray(arr);

    for (int& i : arr)
        std::cout <<i <<' ';

    return 0;
}