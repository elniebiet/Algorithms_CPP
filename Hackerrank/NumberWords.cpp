#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int number = 895;
    int tempNumber = number;
    stringstream ss;
    ss<<number;
    string _number;
    ss>>_number;
    //cout<<_number;

    vector<string> units;
    units.push_back("");
    units.push_back("one");
    units.push_back("two");
    units.push_back("three");
    units.push_back("four");
    units.push_back("five");
    units.push_back("six");
    units.push_back("seven");
    units.push_back("eight");
    units.push_back("nine");

    vector<string> tens;
    tens.push_back("");
    tens.push_back("ten");
    tens.push_back("twenty");
    tens.push_back("thirty");
    tens.push_back("fourty");
    tens.push_back("fifty");
    tens.push_back("sixty");
    tens.push_back("seventy");
    tens.push_back("eighty");
    tens.push_back("ninety");

    int currentDigit = _number.length() - 1;
    string output = "";
    for(int i=0; i<_number.length(); i++){
        if(i == 0){
            output = units[_number[currentDigit] - 48] + " " + output;
        } else if(i == 1){
            output = tens[_number[currentDigit] - 48] + " " + output;
        } else if(i == 2){
            output = units[_number[currentDigit] - 48] + " hundred" + " " + output;
        } else if(i == 3){
            output = units[_number[currentDigit] - 48] + " thousand" + " " + output;
        } else if(i == 4){
            ;
        }
        currentDigit--;
    }

    cout<<output;

    return 0;
}
