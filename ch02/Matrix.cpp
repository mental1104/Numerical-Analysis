#include "./Matrix.hpp"

int main(){
    Matrix A({
        {9,2,3},
        {-1,0,2},
        {-4,6,-9}
    });
    Factor val = LU(A);
    val.first.show();
    val.second.show();
    return 0;
}