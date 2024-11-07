#include <iostream>
#include <vector>

std::vector<int> leader(std::vector<int>& arr){

    std::vector<int> result { };

    int max { INT_MIN };

    for (int i=arr.size()-1; i>=0; i--){

        if (arr[i] > max){
            result.push_back(arr[i]);
            max = arr[i];
        }
    }

    return result;
}

int main(){

    std::vector<int> arr { 10, 1, 22, 12, 3, 0, 6 };

    std::vector<int> result { leader(arr) };

    for (int& i : result)
        std::cout <<i <<' ';

    return 0;
}