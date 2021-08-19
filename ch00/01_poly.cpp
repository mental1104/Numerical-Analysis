#include"01_poly.hpp"  
#include<iostream>

using namespace::std;

int main(){
    Poly p(4, {-1,5,-3,3,2}, 0.5);
    cout << p.get() << endl;
}