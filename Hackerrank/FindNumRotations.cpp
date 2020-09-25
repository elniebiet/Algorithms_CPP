#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
    string _numbers  = "11 12 12 13 14 1 2 3 4 5 6 7 8 9 10";
    vector<int> numbers;

    stringstream ss(_numbers);
    int number;
    while(!ss.eof()){
        ss>>number;
        numbers.push_back(number);
    }

    int rotated = 0;
    //traverse the list, look for where there is a change
    for(int i=0; i<numbers.size()-1; i++){
        if(numbers[i] > numbers[i+1]){
            rotated = i+1;
            break;
        }
    }

    cout<<_numbers<<endl;
    if(rotated == 0){
        cout<<"not rotated"<<endl;
    } else {
        cout<<"rotated: "<<rotated<<endl;
    }

    return 0;
}
