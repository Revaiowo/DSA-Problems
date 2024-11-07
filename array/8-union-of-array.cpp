#include <iostream>
#include <vector>

void printArr(std::vector<int>& arr){

    for (int i=0; i<arr.size(); i++)
        std::cout <<i <<' ';

    std::cout <<'\n';
}

std::vector<int> arrayUnion(std::vector<int>& arr1, std::vector<int>& arr2) {

    std::vector<int> arr { };

    int a1 { 0 };
    int a2 { 0 };

    while (a1 < arr1.size() && a2 < arr2.size()) {

        if (arr1[a1] < arr2[a2]) 
            arr.push_back(arr1[a1++]);

        else if (arr2[a2] < arr1[a1]) 
            arr.push_back(arr2[a2++]);
       
        else {
            arr.push_back(arr1[a1++]);
            a2++;
        }

        // printArr(arr);
    }

    for (int i=a1; i<arr1.size(); i++) 
        arr.push_back(arr1[i]);
    

    for (int i=a2; i<arr2.size(); i++) 
        arr.push_back(arr2[i]);
    
    return arr;
}

int main() {

    std::vector<int> arr1 { 1, 5, 8 };
    std::vector<int> arr2 { 3, 5, 6, 10 };

    std::vector<int> arr { arrayUnion(arr1, arr2) };

    for (int& i : arr)
        std::cout <<i <<' ';
}