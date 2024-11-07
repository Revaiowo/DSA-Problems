#include <iostream>
#include <vector>

std::vector<int> secondSmallestLargest(std::vector<int>& arr) {

    int smallest { 0 };
    int largest { 0 };
    int secondSmallest { 0 };
    int secondLargest { 0 };

    for (int i=0; i<arr.size(); i++) {

        if (arr[smallest] > arr[i])
            smallest = i;
        
        if (arr[largest] < arr[i])
            largest = i;

        if (arr[secondSmallest] > arr[i] && arr[i] != arr[smallest])
            secondSmallest = i;
        
        if (arr[secondLargest] < arr[i] && arr[i] != arr[largest])
            secondLargest = i;
    }

    std::cout <<arr[smallest] <<'\n' <<arr[largest] <<'\n';

    return { arr[secondSmallest], arr[secondLargest] };
}

int main(){

    std::vector<int> arr { 4, 8, 22, 90, 2, 1, 7, 888, 55, 45 };

    std::vector<int> result { secondSmallestLargest(arr) };

    for (int i : result) {
        
        std::cout <<i <<'\n';
    }
    
    return 0;
}