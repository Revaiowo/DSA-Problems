#include <iostream>
#include <vector>
#include <algorithm>

void rotateMatrix(auto& matrix){

    int row { matrix.size() };
    int col { matrix[0].size() };

    int edge { };

    std::vector<std::vector<int>> result (row, std::vector<int>(col));

    for (int i=0; i<row; i++){

        for (int j=i; j<col; j++){

            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i=0; i<row; i++){

        std::reverse(matrix[i].begin(), matrix[i].end());
    }

    // Approach with O(n^2) space complexity cause we use new array 
    // for (int i=0; i<row; i++){
        
    //     edge = row - 1;

    //     for (int j=0; j<col; j++){

    //         result[i][j] = matrix[edge--][i];
    //     }
    // }

}

int main(){

    std::vector<std::vector<int>> matrix { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    rotateMatrix(matrix);

    for (auto& i: matrix){
        for (auto& j : i){
            std::cout <<j <<' ';
        }
        std::cout <<'\n';
    }

    return 0;
}