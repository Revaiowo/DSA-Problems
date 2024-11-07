#include <iostream>
#include <vector>

int lowerBound(std::vector<int>& arr, int target){

    int left { 0 };
    int right { arr.size() - 1 };

    int result { };

    while (left <= right){

        int mid { ( left + right ) / 2 };

        if (arr[mid] >= target){
            result = mid;
            right = mid-1;
        }

        else 
            left = mid+1;
    }

    return result;
}

int main(){

    std::vector<int> arr { 3,3,4,4,4,4,4,4,4,4,4 };
    int target { 4 };

    int result { lowerBound(arr, target) };

    std::cout <<result;

    return 0;
}