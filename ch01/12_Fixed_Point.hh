#include<functional>
#include<iostream>  
#include<vector>

#define TIME 50

class Fixed_Point {
public: 
    Fixed_Point() = delete;
    Fixed_Point(std::function<double(double)> f, double a):func(f), x(a){
        temp.reserve(TIME);
        evaluate();
    }
    double get() {  return y;   }
    void print();
private:
    void evaluate();
    std::function<double(double)> func;
    double x;
    double y;
    std::vector<double> temp;
};

void
Fixed_Point::evaluate(){
    double res = x;
    temp[0] = res;
    int i;
    for(i = 1; i < TIME; i++){
        res = func(res);
        temp[i] = res;
    }
    y = temp[i-1];
    return;
}

void 
Fixed_Point::print(){
    for(int i = 0; i < TIME; i++){
        printf("%d: %.13f\n", i, temp[i]);
    }
    return;
}