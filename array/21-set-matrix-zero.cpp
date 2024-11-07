#include <iostream>
#include <vector>

void setMatrixZero(std::vector<std::vector<int>>& matrix){

    int rowSize { matrix.size() };
    int colSize { matrix.size() };

    int col0 { 1 };

    for (int i=0; i<matrix.size(); i++){

        for (int j=0; j<matrix[0].size(); j++){

            if (matrix[i][j] == 0){

                matrix[i][0] = 0; // row

                if (j == 0)
                    col0 = 0;
                else
                    matrix[0][j] = 0; // col
           }
        }
    }

    for (int i=1; i<matrix.size(); i++){

        for (int j=1; j<matrix[0].size(); j++){

            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }  

    if (matrix[0][0] == 0){

        for (int j=0; j<matrix.size(); j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0){

        for (int i=0; i<matrix[0].size(); i++)
            matrix[i][0] = 0;
    }

}

int main(){

    std::vector<std::vector<int>> matrix { {1, 1, 0}, {1, 0, 1}, {1, 1, 1} };
    
    setMatrixZero(matrix);

    for (auto& i : matrix){
        for (auto& j : i){
            std::cout <<j <<' ';
        }
        std::cout <<'\n';
    }
}