#include <iostream>
#include <cmath>

inline long double oldFunc(long double x, long double y){
    return sqrt(pow(x,2)+pow(y,2))-x;
}

inline long double newFunc(long double x, long double y){
    return pow(y,2)/(sqrt(pow(x,2)+pow(y,2))+x);
}

int main(){
    printf("Old version:    %.20Lf\n", oldFunc(3344556600,1.2222222));
    printf("New version:    %.20Lf\n", newFunc(3344556600,1.2222222));
    return 0;
}