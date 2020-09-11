#include <iostream>
#include <map>
#include <cstdio>
#include <math.h>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    int max = a;
    max = (b > max) ? b : max;
    max = (c > max) ? c : max;
    max = (d > max) ? d : max;
    return max;
}
int main() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<max_of_four(a, b, c, d)<<endl;

    return 0;
}
