#include <iostream>
#include <vector>

int countSubarray(std::vector<int>& arr, int k){

    int count { };
    int sum { };

    for (int i=0; i<arr.size(); i++){

        sum = 0;

        for (int j=i; j<arr.size(); j++){

            sum += arr[j];

            if (sum == k)
                count++;
        }
    }

    return count;
}

int main(){

    std::vector<int> arr { 3, 1, 2, 4 };
    int k { 6 };

    int result { countSubarray(arr, k) };

    std::cout <<result;

    return 0;
}