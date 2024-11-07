#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> nextGreaterElement(std::vector<int>& arr){

    std::stack<int> s;
    std::vector<int> nge { };

    int size { arr.size() };

    for (int i = 2*size-1; i>=0; i--){

        while (!s.empty() && arr[i%size] >= s.top())
            s.pop();    
        
        if (i < size ){

            if (!s.empty() && arr[i&size] < s.top())
                nge.push_back(s.top());
            else 
                nge.push_back(-1);

            s.push(arr[i%size]);
        }
    }

    std::reverse(nge.begin(), nge.end());   
    return nge;
}

int main(){

    std::vector<int> arr { 5, 7, 1, 4, 6, 0 };

    std::vector<int> result { nextGreaterElement(arr) };

    for (auto& i : result)
        std::cout <<i <<' ';

    return 0;
}