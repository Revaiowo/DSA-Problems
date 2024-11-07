#include <iostream>
#include <vector>

int longestSubarray(std::vector<int>& arr, int k){

    int sum { };
    int j { 0 };
    int len { -1 };

    for (int i=0; i<arr.size(); i++){
         
        while (sum > k)
            sum -= arr[j++];

        // if (sum < k)
        //     sum += arr[i];

        if (sum <= k){
            sum += arr[i];
        }

        if (sum == k){
            len = std::max(len, i-j);
        }


        std::cout<< sum<< '\n';
    }

    return len+1;
}

int main(){

    std::vector<int> arr { 3, 1, 2, 3, 7, 1, 1, 1, 1 };
    int k { 5 };

    int result { longestSubarray(arr, k) };

    std::cout<<"Result : " <<result;

    return 0;
}