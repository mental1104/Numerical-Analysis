#include<functional>
#include<iostream>  
#include<vector>

#define TIME 50

class Fixed_Point {
public: 
    Fixed_Point() = delete;
    Fixed_Point(std::function<double(double)> func, double x):f(func){
        val.resize(TIME);
        evaluate(x);
        print();
    }
    void reset(double x) {  evaluate(x); print(); }
private:
    void print();
    void evaluate(double x);
    std::function<double(double)> f;
    std::vector<double> val;
};

void
Fixed_Point::evaluate(double x){
    val[0] = x;
    for(int i = 1; i < TIME; i++){
        x = f(x);
        val[i] = x;
    }
    return;
}

void 
Fixed_Point::print(){
    for(int i = 0; i < TIME; i++){
        printf("%.13f\n", val[i]);
    }
    return;
}