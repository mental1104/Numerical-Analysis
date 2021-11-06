#include "./Matrix.hpp"

int main(){
    Matrix m({
		 {1,1,1},
         {1,2,3},
         {1,3,6}
	}, {5,7,11});

    for(auto i: m.evaluate())
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}