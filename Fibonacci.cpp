#include <iostream> 
using namespace std;


float fib(float n){
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}//end Fibonacci
 
int main (){
    
    float n = 50;

    cout << fib(n);
    getchar();

    return 0;
}//end main