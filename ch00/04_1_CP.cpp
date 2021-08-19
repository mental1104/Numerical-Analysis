#include <iostream>
#include <cmath>

using namespace::std;

#define SEC(x) (1/cos(x))

inline double oldA(double x){
    return (1-SEC(x))/pow(tan(x),2);
}

inline double newA(double x){
    return -1/(SEC(x)+1);
}

inline double oldB(double x){
    return (1-pow(1-x,3))/x;
}

inline double newB(double x){
    return 3-3*x+pow(x,2);
}
int main(){
    double x = 0.1;
    printf("Old-A\n");
    for(int i = 1; i <= 14; x = x/10, i++)
        printf("10^-%d    %lf\n", i, oldA(x));
    printf("New-A\n");

    x = 0.1;
    for(int i = 1; i <= 14; x = x/10, i++)
        printf("10^-%d    %lf\n", i, newA(x));

    printf("Old-B\n");  
    x = 0.1;
    for(int i = 1; i <= 14; x = x/10, i++)
        printf("10^-%d    %lf\n", i, oldB(x));
    
    printf("New-B\n");  
    x = 0.1;
    for(int i = 1; i <= 14; x = x/10, i++)
        printf("10^-%d    %lf\n", i, newB(x));
}