#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> getNumbersFromString(string line){

    line += "\n"; //delimeter
    //extract words
    vector<int> numbers;
    string currentNumber = "";
    for(int i=0; i<line.length(); i++){
        if(isdigit(line[i])){
            currentNumber += line[i];
        } else {
            //convert number to string
            if(currentNumber.length() > 0){
                int _currentNumber = 0;
                for(int j=0; j<currentNumber.length(); j++){
                    _currentNumber = _currentNumber * 10 + (currentNumber[j] - 48);
                }
                numbers.push_back(_currentNumber);
//                cout<<_currentNumber<<endl;
                _currentNumber = 0;
            }
            currentNumber = "";
        }
    }

    return numbers;
}


int main()
{
    string line;
    getline(cin, line);
    vector<string> lines;
    lines.push_back(line);

    vector<int> line1 = getNumbersFromString(lines[0]);
    vector<vector<int> > aArrays;
    //get a arrays
    for(int i=0; i<line1[0]; i++){
        getline(cin, line);
        vector<int> elements = getNumbersFromString(line);
        aArrays.push_back(elements);
    }

    vector<int> queryResults;
    //at this point we have the arrays, now get queries
    for(int i=0; i<line1[1]; i++){
        getline(cin, line);
        vector<int> query = getNumbersFromString(line);
        queryResults.push_back(aArrays[query[0]][query[1] + 1]);
//        cout<<aArrays[query[0]][query[1] + 1]<<endl;
    }

    for(int i=0; i<queryResults.size(); i++){
        cout<<queryResults[i]<<endl;
    }

    return 0;
}
