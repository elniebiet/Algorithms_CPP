#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str = "hello have you know I know I have what you have";
    string subStr = "have";
    int counter = 0;
    while(str.find(subStr) != string::npos){
        str = str.substr(str.find(subStr) + subStr.length(), str.length()-1);
        counter++;
    }
    cout<<counter;
    return 0;
}
