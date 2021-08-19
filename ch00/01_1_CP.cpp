#include "01_poly.hpp"
#include <cmath>
#include <iostream>

double Q(double x){
    return (pow(x,51)-1)/(x-1);
}

int main(){
    vector<double> init(51, 1.0);
    Poly poly(50, init, 1.00001);
    printf("Function Q:   %.15lf\n", Q(1.00001));
    printf("Polynomial:   %.15lf\n", poly.get());
    return 0;
}