#include <iostream>
#include <vector>

int firstOccurance(std::vector<int>& arr, int target){

    int index { -1 };

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left+right) / 2 };

        if (arr[mid] == target){

            index = mid;
            right = mid-1;
        }
        else if (arr[mid] > target) 
            right = mid-1;
        else    
            left = mid+1;
    }

    return index;
    
}

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

int countOccurance(std::vector<int>& arr, int target){

    int first { firstOccurance(arr, target) };
    int last { lastOccurance(arr, target) };

    return last - first + 1;
}

int main(){

    std::vector<int> arr { 2, 2 , 3 , 3 , 3 , 3, 3,3 , 4 };
    int target { 3 };

    int result { countOccurance(arr, target) };

    std::cout <<result;

    return 0;
}