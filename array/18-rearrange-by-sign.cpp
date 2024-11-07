#include <iostream>
#include <vector>

std::vector<int> rearrangeBySign(std::vector<int>& arr) {

    std::vector<int> arrangedArr { };
    std::vector<int> positiveArr { };
    std::vector<int> negativeArr { };

    for (int i=0; i<arr.size(); i++){

        if (arr[i] > 0)
            positiveArr.push_back(arr[i]);
        
        else
            negativeArr.push_back(arr[i]);
    }

    int positiveSize { };
    int negativeSize { };

    int max { std::max(positiveArr.size(), negativeArr.size()) };

    for (int i=0; i<max; i++){
        
        if (positiveSize < positiveArr.size())
            arrangedArr.push_back(positiveArr[positiveSize++]);
        
        if (negativeSize < negativeArr.size())
            arrangedArr.push_back(negativeArr[negativeSize++]);
    }   

    return arrangedArr;
}

int main() {

    std::vector<int> arr { -3, 4, 1, 8, 9, 11, -4, -8 };

    std::vector<int> result { rearrangeBySign(arr) };

    for (int& i : result)
        std::cout << i << ' ';

    return 0;
}