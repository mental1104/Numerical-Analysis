#include "01_poly.hpp"  
#include <iostream>

int main(){
    vector<double> vec;
    vec.reserve(105);
    double init = 1.0;
    for(int i = 0; i < 100; i++){
        vec.push_back(init);
        init = -init;
    }
    Poly poly(99, vec, 1.00001);
    printf("%lf\n", poly.get());
    return 0;
}