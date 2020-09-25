#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

int main()
{

    vector<int> numbers;
    string _numbers = "1 2 3 4 5 6 6 6 7 8 8 8 9 10";
    getline(cin, _numbers);
    int findNumber = 8;
    cin>>findNumber;

    int foundIndex = 0;
    bool found = false;
    stringstream ss(_numbers);
    int num;
    while(!ss.eof()){
        ss>>num;
        numbers.push_back(num);
    }

    int left = 0;
    int right = numbers.size() - 1;
    int position = floor((right - left) / 2);

    while(found == false){
        if(findNumber == numbers[position]){
            foundIndex = position;
            found = true;
            cout<<foundIndex;
//        } else if(findNumber == numbers[position - 1]){
//            foundIndex = position - 1;
//            found = true;
//            cout<<foundIndex;
//
//        } else if(findNumber == numbers[position + 1]){
//            foundIndex = position + 1;
//            found = true;
//            cout<<foundIndex;

        } else {
            //not found yet
            if(findNumber < numbers[position]){
                right = position;
                position = floor((right - left)/2);
            } else if(findNumber > numbers[position]){
                left = left + (position - left);
                position = left + floor((right - left)/2);
            }
        }
    }

    int temp = foundIndex;
    while(numbers[temp+1] == findNumber){
        temp++;
    }

    cout<<temp<<endl;

    return 0;
}
