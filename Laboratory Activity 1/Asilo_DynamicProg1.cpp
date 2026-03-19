#include <iostream>

using namespace std;

int fibonacciNum(int n){

    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0; 
    int b = 1; 
    int current = 0;

    for (int i = 2; i <= n; i++) {
        current = a + b; 
        
        a = b;       
        b = current; 
    }

    return current;
    
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << n <<"-th Fibonacci number is: " << fibonacciNum(n) << endl;

    return 0;
}
