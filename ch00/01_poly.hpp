#include<vector>
#include<cassert>

using std::vector;

class Poly{
public:
    Poly() = delete;
    Poly(int e, vector<double> c, double v, vector<double> b);
    Poly(int e, vector<double> c, double v);
    double get() {  return y; }
private:
    double evaluate();
    int exp;
    vector<double> coefficient;
    double x;
    double y;
    vector<double> base_point;
};

Poly::Poly(int e, vector<double> c, double v, vector<double> b):
    exp(e), coefficient(c), x(v), base_point(b)
{
    assert(coefficient.size() == (exp+1));
    assert(base_point.size() == exp);
    evaluate();
}

Poly::Poly(int e, vector<double> c, double v):exp(e), coefficient(c), x(v)
{
    assert(coefficient.size() == (exp+1));
    base_point.resize(e,0);
    evaluate();
}

double Poly::evaluate(){
    y = coefficient[exp];
    for(auto pc = coefficient.crbegin()+1, pb = base_point.crbegin();
            pc!=coefficient.crend()&&pb!=base_point.crend(); pc++, pb++)
        y = y * (x-*pb) + *pc;
    return y;
}