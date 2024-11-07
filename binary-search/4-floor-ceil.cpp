#include <iostream>
#include <vector>

std::vector<int> findFloorAndCeil(std::vector<int> arr, int target){

    int floor { };
    int ceil { };

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left + right) / 2 };

        if (arr[mid] == target)
            return { arr[mid], arr[mid] };
        
        if (arr[mid] > target){
            right = mid - 1;
            ceil = arr[mid];
           
        }
        else {
            left = mid + 1;
            floor = arr[mid];
         
        }
    }

    return { floor, ceil };
}

int main(){

    std::vector<int> arr { 3, 4, 4, 7, 8, 10, 12, 14, 17, 32, 43 };
    int target { 5 };

    std::vector<int> result { findFloorAndCeil(arr, target) };
    
    std::cout <<result[0] <<' '<<result[1];

    return 0;
}