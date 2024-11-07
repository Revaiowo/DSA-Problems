#include <iostream>
#include <vector>

int lastOccurance(std::vector<int>& arr, int target){

    int index { -1 };

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left+right) / 2 };

        if (arr[mid] == target){

            index = mid;
            left = mid+1;
        }
        else if (arr[mid] > target) 
            right = mid-1;
        else    
            left = mid+1;
    }

    return index;
}

int main(){

    std::vector<int> arr { 3,4,13,13,13,20,40 };
    int target { 13 };

    int result { lastOccurance(arr, target) };

    std::cout <<result;

    return 0;
}