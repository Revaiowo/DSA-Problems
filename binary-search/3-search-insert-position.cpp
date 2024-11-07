#include <iostream>
#include <vector>

int searchPosition(std::vector<int>& arr, int target){

    int left { };
    int right { arr.size() - 1 };

    int ans { };

    while (left <= right){

        int mid { (left+right)/2 };

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target){
            ans = mid;
            right = mid-1;
        }
        else {
            ans = mid;
            left = mid+1;   
        }
    }

    return ans;
}

int main(){

    std::vector<int> arr { 1,2,4,5,7,8,10 };
    int target { 9 };

    int result { searchPosition(arr, target) };

    std::cout <<result;

    return 0;
}