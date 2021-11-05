
#include<vector>
#include<cmath>
#include<cassert>
#include<iostream>
#include<unistd.h>

using std::vector;

#define EPS 0.00001

class Matrix {
public:
    Matrix(size_t row = 1, size_t col = 1): matrix(row, vector<double>(col, 0.0)) {}
	Matrix(const vector<vector<double>> & data): matrix(data) {}
	~Matrix(){}
	Matrix& operator=(const vector<vector<double>>& data){
		this->matrix = data;
		return *this;
	}
    Matrix naive();
    void show();
    vector<vector<double>> matrix;
};

Matrix Matrix::naive(){
    int size = matrix.size();
    for(int j = 0; j < size-1; j++){
        assert(abs(matrix[j][j])>=EPS);
        for(int i = j+1; i < size; i++){
            double mult = matrix[i][j]/matrix[j][j];
            for(int k = j; k < size; k++){
                matrix[i][k] = matrix[i][k] - mult * matrix[j][k];
            }
        }
    }
    return matrix;
}

void 
Matrix::show(){
	for(size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[0].size(); ++j)
			printf("%8.2f ", matrix[i][j]);
		puts("");
    }
	return;

}

int main(){
    Matrix m({
		 {1,1,0,0},
         {1,2,1,0},
         {0,1,2,1},
         {0,0,1,2},
	});
    Matrix U = m.naive();
    //U.show();
}

