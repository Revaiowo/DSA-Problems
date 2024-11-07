#include <iostream>
#include <vector>

bool searchRotatedArray(std::vector<int>& arr, int target){

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left+right) / 2 };

        if (arr[mid] == target)
            return true;
        
        if (arr[left] == arr[mid] && arr[mid] == arr[right]){
            left++;
            right--;
        }

        // left sorted section
        else if (arr[left] <= arr[mid]){

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
    return false;
}

int main(){

    std::vector<int> arr { 3,1,2,3,3,3,3,3,3,3,3,3,3 };
    int target { 1 };

    bool result { searchRotatedArray(arr, target) };

    std::cout <<std::boolalpha;
    std::cout <<result;

    return 0;
}