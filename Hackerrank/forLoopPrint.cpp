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

    int a, b;
    cin>>a>>b;


    if(a < b){
        for(int i=a; i<=b; i++){
            if(i>=1 && i<=9){
                cout<<numbers.find(i)->second<<endl;
            }
        }
        for(int i=a; i<=b; i++){
            if(i>9 && i%2 == 0){
                cout<<"even"<<endl;
            } else if(i>9 && i%2 == 1) {
                cout<<"odd"<<endl;
            }
        }
    }

    return 0;
}
