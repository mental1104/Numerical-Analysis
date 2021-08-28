#include "12_Fixed_Point.hh"  
#include <cmath>

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <init>\n", argv[0]);
        return 0;
    }

    double INIT = atof(argv[1]);

    std::cout << "x = 1 - x^3: " << std::endl;
    Fixed_Point a([](double x){ return 1 - pow(x, 3); }, INIT);
    a.print();

    std::cout << "--------------------------" << std::endl;

    std::cout << "x = (1 - x)^1/3: " << std::endl;
    Fixed_Point b([](double x){ return pow((1-x), 1/3.0); }, INIT);
    b.print();
    std::cout << "--------------------------" << std::endl;

    std::cout << "x = (1 + 2 * x^3)/(1 + 3 * x^2): " << std::endl;
    Fixed_Point c([](double x){ return (1+2*pow(x,3))/(1+3*pow(x,2)); }, INIT);
    c.print();
    std::cout << "--------------------------" << std::endl;

    std::cout << "x = cos(x): " << std::endl;
    Fixed_Point d([](double x){ return cos(x); }, INIT);  
    d.print();
    std::cout << "--------------------------" << std::endl;  

    std::cout << "x = x + cos(x) - sin(x): " << std::endl;
    Fixed_Point f([](double x){ return x + cos(x) - sin(x); }, INIT);  
    f.print();
    std::cout << "--------------------------" << std::endl;

    std::cout << "x = 2.8x - x^2: " << std::endl;
    Fixed_Point g([](double x){ return 2.8*x - pow(x,2); }, INIT);  
    g.print();
    std::cout << "--------------------------" << std::endl;  

    std::cout << "x = (x+2/x)/2: " << std::endl;
    Fixed_Point h([](double x){ return (x + 2/x)/2; }, INIT);  
    h.print();
    std::cout << "--------------------------" << std::endl;

    
    return 0;
}