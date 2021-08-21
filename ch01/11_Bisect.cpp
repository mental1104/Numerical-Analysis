#include "11_Bisect.hpp"  
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::function;
using std::vector;

unique_ptr<Bisect> factory(function<double(double)> f, double a, double b){
    return unique_ptr<Bisect>(new Bisect(f, a, b));
}

int main(){
    auto func1 = [](double x){  return pow(x, 3) + x - 1; };
    auto func2 = [](double x){  return cos(x)-x;    };
    
    vector<unique_ptr<Bisect>> vec;

    vec.push_back(factory(func1, 0, 1));
    vec.push_back(factory(func2, 0, 1));

    int counter = 0;
    for(auto& i: vec){
        counter++;
        cout << "EXAMPLE1." << counter << ":    " << i->getRoot() << std::endl;
    }
    return 0;    
}