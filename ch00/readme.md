# Chapter 0 Fundamentals  

## 0.1 Evaluating a Polynomial  


[01_poly.hpp](./01_poly.hpp)  
[01_poly.cpp](./01_poly.cpp)  

```cpp
#include"poly.hpp"  

using namespace::std;

int main(){
    Poly p(4, {-1,5,-3,3,2}, 0.5);
    cout << p.get() << endl;
}
```

`g++ 01_poly.cpp`  
`./a.out`  

```
1.25
```

### Computer Problems  

#### 1. Use the function nest to evaluate P (x) = 1 + x + · · · + x 50 at x = 1.00001. (Use the Matlab ones command to save typing.) Find the error of the computation by comparing with the equivalent expression Q(x) = (x 51 − 1)/(x − 1).

[01_1_CP.cpp](./01_1_CP.cpp)  

```
➜  ch00 git:(main) ✗ g++ 01_1_CP.cpp
➜  ch00 git:(main) ✗ ./a.out
Function Q:   51.012752082745230
Polynomial:   51.012752082749991
```  

#### 2. Use nest.m to evaluate P (x) = 1 − x + x 2 − x 3 + · · · + x 98 − x 99 at x = 1.00001. Find a simpler, equivalent expression, and use it to estimate the error of the nested multiplication.

[01_2_CP.cpp](./01_2_CP.cpp)  

```
➜  ch00 git:(main) ✗ g++ 01_2_CP.cpp
➜  ch00 git:(main) ✗ ./a.out
-0.000500
```  


## 0.2 Binary Numbers  

