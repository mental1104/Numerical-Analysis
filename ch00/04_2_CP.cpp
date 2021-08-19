#include <iostream>
#include <cmath>

inline double A(double x){
    return (tan(x)-x)/pow(x,3);
}

inline double B(double x){
    return (exp(x)+cos(x)-sin(x)-2)/pow(x,3);
}

int main(){
    printf("A:  \n");
    double res;
    for(int i = 1; i < 20; i++){
        res = A(pow(10,-i));
        if(res == 0.0){
            printf("%d is the value that resulted in an incorrect significant digits.\n", i);
            break;
        }
        printf("10^-%d: %lf\n", i, res);
    }

    printf("\n\n");
    printf("B:  \n");
    for(int i = 1; i < 20; i++){
        res = B(pow(10,-i));
        if(res == 0.0){
            printf("%d is the value that resulted in an incorrect significant digits.\n", i);
            break;
        }
        printf("10^-%d: %lf\n", i, res);
    }

    return 0;
}