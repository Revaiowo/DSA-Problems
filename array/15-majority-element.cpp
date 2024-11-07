#include <iostream>
#include <vector>
#include <algorithm>

int majorityElement(std::vector<int>& arr){

    std::sort(arr.begin(), arr.end());
    int target { arr.size()/2 };

    std::cout <<target <<'\n';

    for (int& i : arr)
        std::cout <<i <<' ';

    std::cout <<'\n';

    int count { };

    for (int i=0; i<arr.size(); i++){


        if (arr[i] == arr[i+1])
            count++;

        if (count+1 > target)
            return arr[i];

        if (arr[i] != arr[i+1]) 
            count = 0;
    }

    return -1;
}

int main(){

    std::vector<int> arr { 2,2,1,1,1,2,2 };

    int result { majorityElement(arr) };

    std::cout <<'\n' <<result;

    return 0;
}