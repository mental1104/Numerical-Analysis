# Chapter 0 Fundamentals  

## 0.1 Evaluating a Polynomial  

[poly.hpp](./poly.hpp)  
[poly.cpp](./poly.cpp)  

```cpp
#include"poly.hpp"  

using namespace::std;

int main(){
    Poly p(4, {-1,5,-3,3,2}, 0.5);
    cout << p.get() << endl;
}
```

`g++ poly.cpp`  
`./a.out`  

```
1.25
```

