#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target){

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left + right)/2 };

        if (arr[mid] < target)
            left = mid+1;
        
        else if (arr[mid] > target)
            right = mid-1;
        
        else    
            return arr[mid];
    }
    return -1;
}

int main(){

    std::vector<int> arr { 2, 4, 5, 8, 14, 16 };
    int k { 14 };

    int result { binarySearch(arr, k) };

    std::cout <<result;

    return 0;   
}