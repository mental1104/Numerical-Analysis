#include <functional>  
#include <cassert>

class Bisect{
public:
    Bisect() = delete;
    Bisect(std::function<double(double)> f, double x, double y):func(f), a(x), b(y){
        assert(func(a)*func(b) < 0);
        evaluate();
    }
    double getRoot() {  return root; }
private:
    void evaluate();
    std::function<double(double)> func;
    double a;
    double b;
    int accuracy;
    double root;
};

void 
Bisect::evaluate(){
    double fa = func(a);
    double fb = func(b);

    double _a = a;
    double _b = b;
    double c;
    double fc;
    for(int i = 0; i < 30; i++){
        c = (_a + _b) / 2;
        fc = func(c);
        if(fc == 0.00)
            break;
        if(fc * fa < 0){
            _b = c;
            fb = fc; 
        }else{
            _a = c;
            fa = fc;
        }
    }
    root = (_a + _b)/2;
}