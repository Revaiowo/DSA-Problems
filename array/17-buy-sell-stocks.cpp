#include <iostream>
#include <vector>

int  buySellStocks(std::vector<int>& arr){

    int buy_min { INT_MAX };
    int sell_max { INT_MIN };
    int profit { };

    for (int i=0; i<arr.size()-1; i++){

        if (buy_min > arr[i]){
            buy_min = arr[i];
            sell_max = INT_MIN;
        }

        sell_max = std::max(sell_max, arr[i+1]);

        profit = std::max(profit, sell_max - buy_min);   
    }

    return profit;
}

int main(){
    
    std::vector<int> arr { 7,6,4,3,1 };

    int result { buySellStocks(arr) };

    std::cout <<result;

    return 0;
}