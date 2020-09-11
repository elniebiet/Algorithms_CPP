#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//int main(){
//    string length;
//    bool doPrint = true;
//    getline(cin, length);
//
//    //get length
//    int len = 0;
//    for(int i=0; i<length.length(); i++){
//        len = len * 10 + (length[i] - 48);
//    }
//
//    //get numbers
//    string numbers = "";
//    getline(cin, numbers);
//    string singleNums;
//    string printString = "";
//    int counter = 0;
//    for(int i = numbers.length()-1; i >= 0; i--){
//
//        if(numbers[i] != ' '){
//            singleNums += numbers[i];
//        } else {
//            //reverse singleNums
//            string temp = singleNums;
//            for(int k=0,l=singleNums.length()-1; k<singleNums.length(); k++,--l){
//                singleNums[k] = temp[l];
//            }
//
//            //check number is within constraints
//            //get number
//            int num = 0;
//            for(int i=0; i<singleNums.length(); i++){
//                num = num * 10 + (singleNums[i] - 48);
//            }
//            if(num < 1 || num > 10000){
//                doPrint = false;
//            }
//
//            counter++;
//            printString += singleNums + " ";
//            singleNums = "";
//        }
//        if(i == 0){
//            //reverse singleNums
//            string temp = singleNums;
//            for(int k=0,l=singleNums.length()-1; k<singleNums.length(); k++,--l){
//                singleNums[k] = temp[l];
//            }
//
//            //check number is within constraints
//            //get number
//            int num = 0;
//            for(int i=0; i<singleNums.length(); i++){
//                num = num * 10 + (singleNums[i] - 48);
//            }
//            if(num < 1 || num > 10000){
//                doPrint = false;
//            }
//            counter++;
//            printString += singleNums;
//        }
//    }
//
//    if(len != counter)
//        doPrint = false;
//    if(doPrint)
//        cout<<printString;
//
//}
//






vector<int> extractIntWords(string str){

    vector<int> intWords;
    string intWord = "";
    char prevChar = '\n';
    for(int i=str.length()-1; i>=0; i--){

        if(i<str.length()-1){
            prevChar = str[i+1];
        }

        if(isdigit(str[i])){
            if(isdigit(str[i]) && prevChar == ' '){
                //new intWord

                //reverse number
                string temp = intWord;
                for(int k=0,l=intWord.length()-1; k<intWord.length(); k++,--l){
                    intWord[k] = temp[l];
                }
                //get number from string
                int num = 0;
                for(int i=0; i<intWord.length(); i++){
                    num = num * 10 + (intWord[i] - 48);
                }
                intWords.push_back(num);
                intWord = "";
            }
            intWord += str[i];
        }
        else {
            ;
        }

        if(i == 0){
            //reverse number
            string temp = intWord;
            for(int k=0,l=intWord.length()-1; k<intWord.length(); k++,--l){
                intWord[k] = temp[l];
            }
            //get number from string
            int num = 0;
            for(int i=0; i<intWord.length(); i++){
                num = num * 10 + (intWord[i] - 48);
            }
            intWords.push_back(num);
        }

    }


    return intWords;
}

inline std::string trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
    return str;
}

int main() {
    bool _print = true;
    string length;
    int _length;
    getline(cin, length);
    _length = extractIntWords(length)[0];

    _print = (_length < 1 || _length > 1000) ? false : _print;
    string numbers;
    getline(cin, numbers);
    numbers = trim(numbers);
    vector<int> _numbers = extractIntWords(numbers);

    string printString = "";
    for(int i=0; i<_numbers.size(); i++){
        _print = (_numbers[i] < 1 || numbers[i] > 10000) ? false : _print;
        printString += to_string(_numbers[i]) + " ";
    }

    _print = (_numbers.size() != _length) ? false : _print;

    if(_print){
        cout<<printString;
    }


    return 0;
}
