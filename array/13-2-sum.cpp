#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> twoSum(std::vector<int>& arr, int target){

    std::sort(arr.begin(), arr.end());

    int left { 0 };
    int right { arr.size()-1 };
    int sum { };

    while (left<right){

        sum = arr[left] + arr[right];

        if (sum > target)
            right--;
        
        else if (sum < target)
            left++;
        
        else 
            return { arr[left], arr[right]};
    }
    
    return { -1, -1 };
}

int main(){

    std::vector<int> arr { 1, 2, 3, 5, 8, 9 };
    int target { 8 };

    std::vector<int> result { twoSum(arr, target) };

    std::cout<< "Answer: " <<result[0]<<' ' <<result[1]; 

    return 0;
}