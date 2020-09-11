#include <iostream>
#include <map>
#include <cstdio>
#include <math.h>
using namespace std;

int main() {
    map<int, string> numbers;
    map<int, string>::iterator it = numbers.begin();
    numbers[1] = "one";
    numbers[2] = "two";
    numbers[3] = "three";
    numbers[4] = "four";
    numbers[5] = "five";
    numbers[6] = "six";
    numbers[7] = "seven";
    numbers[8] = "eight";
    numbers[9] = "nine";

    long n;

    cin>>n;
    if(n >  pow(10, 9)){
        ;
    }
    else if(n > 9){
        cout<<"Greater than 9";
    }
    else if(n < 1){
        cout<<"Less than 1";
    }
    else {
        cout<<numbers.find(n)->second<<endl;
    }

    return 0;
}
