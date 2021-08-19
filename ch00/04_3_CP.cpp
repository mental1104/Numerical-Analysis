#include<iostream>
#include<cmath>

inline long double oldFunc(long double a, long double b){
    return a + sqrt(pow(a,2)+pow(b,2));
}

inline long double newFunc(long double a, long double b){
    return -(pow(b,2)/(a-sqrt(pow(a,2)+pow(b,2))));
}

int main(){
    printf("Old version:    %.20Lf\n", oldFunc(-12345678987654321,123));
    printf("New version:    %.20Lf\n", newFunc(-12345678987654321,123));
    return 0;
}