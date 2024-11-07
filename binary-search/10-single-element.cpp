#include <iostream>
#include <vector>

int singleElement(std::vector<int>& arr){

    int left { };
    int right { arr.size() - 1 };

    while (left <= right){

        int mid { (left+right) / 2 };

        if (arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1])
            return arr[mid];

        if (mid % 2 == 0){

            if (arr[mid] == arr[mid+1]) 
                left = mid+1;

            else if (arr[mid-1] == arr[mid])
                right = mid-1;          
        }
        else {

            if (arr[mid-1] == arr[mid]) 
                left = mid+1;

            else if (arr[mid] == arr[mid+1])
                right = mid-1;
        }

    }
    return -1;
}

int main(){

    std::vector<int> arr { 1,1,2,3,3,4,4,5,5,6,6,7,7 };

    int result { singleElement(arr) };

    std::cout <<result;

    return 0;
}