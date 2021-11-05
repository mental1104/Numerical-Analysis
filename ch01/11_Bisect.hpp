#include <functional>  
#include <cassert>

class Bisect{
public:
    Bisect() = delete;
    Bisect(std::function<double(double)> func, double a, double b)
    :f(func){
        assert(f(a)*f(b) < 0);
        evaluate(a, b);
    }
    double get() {  return root; }
private:
    void evaluate(double a, double b);
    std::function<double(double)> f;
    double root;
};

void 
Bisect::evaluate(double a, double b){
    double c;
    for(int i = 0; i < 30; i++){
        c = (a + b) / 2;
        if(f(c) == 0.00)
            break;

        if(f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    root = (a + b)/2;
}