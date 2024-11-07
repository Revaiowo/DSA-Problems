#include <iostream>
#include <vector>

int searchRotatedArray(std::vector<int>& arr, int target){

    int left { };
    int right { arr.size() - 1 };

    int min { INT_MAX };

    while (left <= right){

        int mid { (left+right) / 2 };
        
        // left sorted section
        if (arr[left] <= arr[mid]){

            if (arr[left] < min)
                min = arr[left];

            left = mid+1;
        }

        // Right sorted section
        else{

            if (arr[mid] < min)
                min = arr[mid];
            
            right = mid-1;
        }
    }
    return min;
}

int main(){

    std::vector<int> arr { 12, 14, 15, 18, 21, 88, 111, 112, 113, 5, 9, 10 };
    int target { 1 };

    int result { searchRotatedArray(arr, target) };

    std::cout <<result;

    return 0;
}