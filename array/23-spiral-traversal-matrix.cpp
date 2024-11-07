#include <iostream>
#include <vector>

void spiralTraversal(std::vector<std::vector<int>>& matrix){

    int row { matrix.size() };
    int col { matrix[0].size() };

    int top { 0 };
    int bottom { col - 1 };
    int right { col - 1 };
    int left { 0 };

    while (top <= bottom && left <= right){

        for (int k=top; k<=right; k++)
            std::cout <<matrix[top][k] <<' ';

        top++;

        for (int k=top; k<=bottom; k++)
            std::cout <<matrix[k][right] <<' ';

        right--;

        for (int k=right; k>=left; k--)
            std::cout <<matrix[bottom][k] <<' ';
        
        bottom--;

        for (int k=bottom; k>=top; k--)
            std::cout <<matrix[k][left] <<' ';

        left++;
    }
}

int main(){

    std::vector<std::vector<int>> matrix { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };

    spiralTraversal(matrix);

    return 0;
}