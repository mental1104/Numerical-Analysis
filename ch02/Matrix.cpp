#include "./Matrix.hpp"

int main(){
    Matrix A({
        {1,1,1,1},
        {1,2,3,4},
        {1,3,6,10},
        {1,4,10,20}
    });
    Factor val = LU(A);
    val.first.show();
    val.second.show();
    return 0;
}