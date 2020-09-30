#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    int num = 7*6;
    stringstream ss;
    ss<<num;
    string _num;
    ss>>_num;
    cout<<_num.length();
}
