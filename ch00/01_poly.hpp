#include<vector>
#include<cassert>

using std::vector;

class Poly{
public:
    Poly() = delete;
    Poly(int e, vector<double> c, double v, vector<double> b);
    Poly(int e, vector<double> c, double v);
    double get() {  return y; }
    void reset(double tempX){   this->x = tempX; evaluate(); }
private:
    double evaluate();

    int exp;//degree d of polynomial
    vector<double> coefficient;//array of d+1 coefficients c(constant term first)
    vector<double> base_point;//array of base points
    double x;
    double y;
};

//if base points are needed
Poly::Poly(int e, vector<double> c, double v, vector<double> b):
    exp(e), coefficient(c), x(v), base_point(b)
{
    assert(coefficient.size() == (exp+1));//if coefficient is not permissible, it crash.
    assert(base_point.size() == exp);//if base points are not permissible, it crash.
    evaluate();
}

//if base points are not needed
Poly::Poly(int e, vector<double> c, double v):exp(e), coefficient(c), x(v)
{
    assert(coefficient.size() == (exp+1));//if coefficient is not permissible, it crash.
    base_point.resize(e,0);// We manually insert corresponding zero into the array.  
    evaluate();
}

//evalute
double Poly::evaluate(){
    y = coefficient[exp];
    for(auto c = coefficient.crbegin()+1, b = base_point.crbegin();
            c!=coefficient.crend(); c++, b++)//reverse iterators
        y = y * (x-*b) + *c;
    return y;
}