#include <iostream>
#include <string>
using namespace std;

int main()
{
    char array1[] = {'3', '5', '9'};
    char array2[] = {'1', '2', '8', '4'};

    int num1=0, num2=0;

    for(int i=0; i<(sizeof(array1)/sizeof(char)); i++){
        num1 = num1 * 10 + (array1[i] - 48);
    }
    for(int i=0; i<(sizeof(array2)/sizeof(char)); i++){
        num2 = num2 * 10 + (array2[i] - 48);
    }

    int sum = num1 + num2;
    string _sum = "";
    while(!(sum <= 9)){
        //cout<<sum%10;
        _sum = char(sum%10 + 48) + _sum;
        sum = sum/10;

    }

    _sum = char(sum + 48) + _sum;

    cout<<_sum;

    char array3[_sum.length()];
    for(int i=0; i<_sum.length(); i++){
        array3[i] = _sum[i];
    }

    cout<<endl;

    for(int i=0; i<sizeof(array3)/sizeof(char); i++){
        cout<<array3[i]<<" ";
    }


    return 0;
}
