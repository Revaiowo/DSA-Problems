#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

int trappingRainwater_pointer(std::vector<int>& arr){

    int total { };

    int left { };
    int right { arr.size()-1};

    int leftMax { arr[0] };
    int rightMax { arr[arr.size()-1] };

    while (left < right){

        if (leftMax <= rightMax){

            if (arr[left] < leftMax)
                total += leftMax - arr[left];
            
            leftMax = std::max(leftMax, arr[left++]);
        }

        else {

            if (arr[right] < rightMax)
                total += rightMax - arr[right];
            
            rightMax = std::max(rightMax, arr[right--]);
        }

    }

    return total;
}

int trappingRainwater_array(std::vector<int>& arr){

    int total { };
    int prefix { arr[0] };

    std::vector<int> sufix (arr.size());
    
    sufix[arr.size()-1] = arr[arr.size()-1];

    for (int i=arr.size()-2; i>=0; i--)
        sufix[i] = std::max(sufix[i+1], arr[i]);
    
    for (int i=1; i<arr.size()-1; i++){

        prefix = std::max(prefix, arr[i]);

        if (arr[i] < prefix && arr[i] < sufix[i])
            total += std::min(prefix, sufix[i]) - arr[i];
    }
    
    return total;
}

int main(){

    std::vector<int> arr { 0,1,0,2,1,0,1,3,2,1,2,1 };

    std::cout <<0.1 + 0.2 <<'\n';

    int result { trappingRainwater_pointer(arr) };
    
    std::cout <<result;

    return 0;
}