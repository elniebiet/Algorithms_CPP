#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> integers;

    int num; char ch;
    while(!ss.eof()){
        ss>>num;
        integers.push_back(num);
        ss>>ch;
    }
    return integers;

}

int main()
{

//    stringstream ss("23 4 56");
//    char ch;
//    int a, b, c;
//    //ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
//    ss>>a>>b>>c;
//    cout<<a<<" "<<b<<" "<<c<<endl;
//
//    stringstream st("23, 4, 56");
//    st>>a;
//    st>>ch;
//    st>>b;
//    st>>ch;
//    st>>c;
//    cout<<a<<" "<<b<<" "<<c<<endl;
//
//    stringstream su("");
//    su<<"ID:"<<" "<<1;
//    string id; int number;
//    su>>id>>number;
//    cout<<id<<number<<endl;

    string str = "1,2,3,4,5";
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    map<string, string> str2;
    string nm = "name";
    str2[nm] = "Aniebiet";
    cout<<str2["name"];


}
