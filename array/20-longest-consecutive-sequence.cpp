#include <iostream>
#include <vector>
#include <algorithm>

int longestConsecutiveSequence(std::vector<int>& arr){

    std::sort(arr.begin(), arr.end());

    int count { };
    int max { -1 };

    for (int i=0; i<arr.size()-1; i++){

        if (arr[i+1] - arr[i] == 1)
            count++;
        else    
            count = 0;
        
        if (count > 0)
            max = std::max(max, count);
    }

    return max+1;
}

int main(){

    std::vector<int> arr { 10, 7, 2, 9, 5, 6 };

    int result { longestConsecutiveSequence(arr) };

    std::cout <<result;

    return 0;

}