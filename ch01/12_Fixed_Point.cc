#include "12_Fixed_Point.hh"  
#include <cmath>

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <init>\n", argv[0]);
        return 0;
    }

    double INIT = atof(argv[1]);

    std::cout << "g(x) = (x + 2/x)/2" << std::endl;
    Fixed_Point h([](double x){ return (x + 4/x)/2; }, INIT);  
    std::cout << "--------------------------" << std::endl;
    
    return 0;
}