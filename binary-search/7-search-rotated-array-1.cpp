#include <iostream>
#include <vector>

int searchRotatedArray(std::vector<int>& arr, int target){

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left+right) / 2 };

        if (arr[mid] == target)
            return mid;

        // left sorted section
        if (arr[left] <= arr[mid]){

            if (arr[left] <= target && target < arr[mid])
                right = mid-1;
            else
                left = mid+1;
        }

        // Right sorted section
        else{

            if (arr[mid] > target && target <= arr[right])
                left = mid+1;
            else
                right = mid-1;
        }
    }
    return -1;
}

int main(){

    std::vector<int> arr { 4,5,6,7,0,1,2,3 };
    int target { 5 };

    int result { searchRotatedArray(arr, target) };

    std::cout <<result;

    return 0;
}