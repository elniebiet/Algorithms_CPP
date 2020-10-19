#include <iostream>
#include <sstream>
using namespace std;

int reverseNumber(int num){
    stringstream ss;
    ss<<num;
    string _num;
    ss>>_num;
    string cString  = _num;
    for(int i=0, k=_num.length()-1; i<_num.length(); i++, k--){
        cString[i] = _num[k];
    }
    stringstream _ss(cString);
    int reversedNumber;
    _ss>>reversedNumber;
    return reversedNumber;
}

bool isPallindrome(int num){
    stringstream ss;
    ss<<num;
    string _num;
    ss>>_num;
    string cString  = _num;
    for(int i=0, k=_num.length()-1; i<_num.length(); i++, k--){
        cString[i] = _num[k];
    }
    stringstream _ss(cString);
    int reversedNumber;
    _ss>>reversedNumber;
    if(reversedNumber == num){
        return true;
    } else {
        return false;
    }
}
int main()
{
    int number = 121;
    int reversedNumber = 0;
    bool foundPal = false;
    while(foundPal == false){
        reversedNumber = reverseNumber(number);
        int sum = number + reversedNumber;
        if(isPallindrome(sum)){
            foundPal = true;
            cout<<sum<<endl;
        }
        number = sum;
    }


    return 0;
}
