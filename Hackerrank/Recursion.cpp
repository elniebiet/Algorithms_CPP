#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    } else if(n == 1){
        return 1;
    } else return (fib(n-1) + fib(n-2));
}

void printN(int n){

    if(n >= 0){
        printN(n - 1);
        cout<<n<<" - ";
    }
}

int factorial(int n){
   if(n > 1){
        cout<<n<<" - ";
        return n * factorial(n - 1);
   } else {
        ;
   }
}


int main()
{
    int n = 3;

    for(int i=0; i<=7; i++){
        cout<<fib(i)<<" - ";
    }

    cout<<fib(5);
    //cout<<factorial(1000);
    //cout<<factorial(7);
    //printN(100);


//    int a;
//    int i=0;
//    int prev1 = 0, prev2 = 1, current = 0;
//
//    while(i<7){
//        current = prev1 + prev2;
//        prev1 = prev2;
//        prev2 = current;
//        cout<<current<<" - ";
//        i++;
//    }



}
