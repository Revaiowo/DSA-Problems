#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& arr){

    if (arr[0] != 1)
        return 1;

    for (int i=0; i<arr.size()-1; i++){

        int num { arr[i] + 1 };

        if (arr[i+1] != num)
            return num;
    }
    return -1;
}

int main(){

    std::vector<int> arr { 1, 2, 3, 4, 6, 7, 8 };

    int result = missingNumber(arr);

    std::cout <<result;

    return 0;
}