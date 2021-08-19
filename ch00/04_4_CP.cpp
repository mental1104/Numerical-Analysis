#include <iostream>
#include <cmath>

inline long double oldFunc(long double c, long double d){
    return sqrt(pow(c,2)+d)-c;
}

inline long double newFunc(long double c, long double d){
    return d/(sqrt(pow(c,2)+d)+c);
}

int main(){
    printf("Old version:    %.20Lf\n", oldFunc(246886422468,13579));
    printf("New version:    %.20Lf\n", newFunc(246886422468,13579));
    return 0;
}