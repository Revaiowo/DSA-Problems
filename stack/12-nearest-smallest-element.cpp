#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nearestSmallestElement(std::vector<int>& arr){

    std::stack<int> s;
    std::vector<int> result;

    for (int i=0; i<arr.size(); i++){

        while (!s.empty() && arr[i] < s.top())
            s.pop();

        if (!s.empty() && arr[i] > s.top())
            result.push_back(s.top());
        else    
            result.push_back(-1);

        s.push(arr[i]);
    }

    return result;
}

int main(){

    std::vector<int> arr { 4, 5, 2, 10, 8 };

    std::vector<int> result { nearestSmallestElement(arr) };

    for (int& i : result)
        std::cout <<i <<' ';
    
    return 0;
}