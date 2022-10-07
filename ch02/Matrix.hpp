#include<vector>
#include<cmath>
#include<cassert>
#include<iostream>
#include<unistd.h>

using std::vector;

#define EPS 0.00000001

/*
class Matrix;

struct Factor{
    Matrix first;
    Matrix second;
};*/

class Matrix {
public:
    Matrix(size_t row = 1, size_t col = 1): matrix(row, vector<double>(col, 0.0)) {}
    Matrix(const Matrix& rhs):matrix(rhs.matrix), vec(rhs.vec){}
    Matrix(const vector<vector<double>> & data): matrix(data){}
	Matrix(const vector<vector<double>> & data, const vector<double>& vec): matrix(data), vec(vec) {}
	~Matrix(){}
	Matrix& operator=(const Matrix& data){
		this->matrix = data.matrix;
        this->vec = data.vec;
		return *this;
	}

    Matrix naive();
    //Factor LU();
    void show();
    vector<double> evaluate();

    vector<vector<double>> matrix;
    vector<double> vec;
};

Matrix Matrix::naive(){
    Matrix m;
    vector<vector<double>> U(this->matrix);
    vector<double> b(this->vec);
    int size = U.size();

    for(int j = 0; j < size-1; j++){
        assert(abs(U[j][j])>=EPS);
        for(int i = j+1; i < size; i++){
            double mult = U[i][j]/U[j][j];
            for(int k = j; k < size; k++){
                U[i][k] = U[i][k] - mult * U[j][k];
            }
            b[i] = b[i] - mult * b[j];
        }
    }

    m.matrix = U;
    m.vec = b;
    return m;
}

vector<double> 
Matrix::evaluate(){
    Matrix U = this->naive();
    vector<vector<double>> A = U.matrix;
    vector<double> b = U.vec;

    vector<double> x;
    size_t n = this->matrix.size();
    x.resize(n);

    for(int i = n - 1; i >= 0; i--){
        for(int j = i+1; j < n; j++)
            b[i] = b[i] - A[i][j] * x[j];
        x[i] = b[i]/A[i][i];
    }

    return x;
}

void 
Matrix::show(){
    std::cout << "A: \n";
	for(size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[0].size(); ++j)
			printf("%8.2f ", matrix[i][j]);
		puts("");
    }
    /*
    std::cout << "b: \n";
    for(auto i : vec){
        printf("%8.2f ", i);
    }
    std::cout << std::endl;
    */

	return;
}

Matrix identity(int m){
    assert(m > 0);
    Matrix I(m,m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j){
                I.matrix[i][j] = 1;
            } else {
                I.matrix[i][j] = 0;
            }
        }
    }
    return I;
}

struct Factor {
    Matrix first;
    Matrix second;
};

Factor LU(Matrix A){
    int m = A.matrix.size();
    Matrix U = A;
    Matrix L = identity(m);

    for(int i = 0; i < m; i++){
        assert(U.matrix[i][i]>EPS);
        for(int j = i+1; j < m; j++){
            double a = U.matrix[j][i]/U.matrix[i][i];
            L.matrix[j][i] = a;
            for(int k = i; k < m; k++){
                U.matrix[j][k] = U.matrix[j][k] - a * U.matrix[i][k];
            }
        }
    }
    Factor val;
    val.first = L;
    val.second = U;
    return val;
}

