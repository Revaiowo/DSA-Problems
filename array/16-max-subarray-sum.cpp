#include <iostream>
#include <vector>

std::vector<int> maxSubarraySum(std::vector<int>& arr){

    int max { INT_MIN };
    int sum { };
    int startIndex { -1 };
    int endIndex { -1 };
    int start { };
    std::vector<int> subArr { };

    for (int i=0; i<arr.size(); i++){

        if (sum == 0) 
            start = i;
            
        sum += arr[i];

        if (max < sum){
            max = sum;
            startIndex = start;
            endIndex = i;
        }
        
        if (sum < 0)
            sum = 0;
    }
    
    for (int i = startIndex; i<=endIndex; i++)
        subArr.push_back(arr[i]);
    
    return subArr;
}

int main(){

    std::vector<int> arr { -2,1,-3,4,-1,2,1,-5,4 };

    std::vector<int> result { maxSubarraySum(arr) };

    for (auto& i : result)
        std::cout <<i <<' ';

    return 0;
}