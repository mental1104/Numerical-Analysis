#include<iostream>
#include<cmath>

struct Solution{
    double x1;
    double x2;
};

Solution f(double a, double b, double c){
    Solution x;
    x.x1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
    x.x2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);
    return x;
}

Solution g(double a, double b, double c){
    Solution x;
    x.x1 = -((2*c)/(b+sqrt(pow(b,2)-4*a*c)));
    x.x2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);
    return x;
}

int main(){
    Solution x = g(1, pow(9,12), -3);
    std::cout << x.x1 << "\t" << x.x2 << std::endl;
    return 0;
}

