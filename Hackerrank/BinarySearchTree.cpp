#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
//    getline(cin, line);

    //first extract numbers from input
    int num, operand1, operand2;

    int findFirstComma = line.find(",");
    string _num = line.substr(0, findFirstComma);

    string temp = line.replace(findFirstComma, 1, "!");

    int findEx = temp.find("!");
    int findSecondComma = temp.find(",");
    string _operand1 = temp.substr(findEx, findSecondComma);
    string _operand2 = temp.substr(findSecondComma, temp.length());

    operand1 = 0; operand2 = 0;
    for(int i=0; i<_operand1.length(); i++){
        if(isdigit(_operand1[i])){
            operand1 = operand1 * 10 + (_operand1[i] - 48);
        }
    }

    for(int i=0; i<_operand2.length(); i++){
        if(isdigit(_operand2[i])){
            operand2 = operand2 * 10 + (_operand2[i] - 48);
        }
    }


//    cout<<operand1<<endl;
//    cout<<operand2<<endl;


  //convert string to int
  int number = 0;
  for(int i=0; i<_num.length(); i++){
    number = number * 10 + (_num[i] - 48);
  }

  //convert number to binary
  vector<int> binaryBits;

  while(number > 2){
    int remainder = number % 2;
    binaryBits.push_back(remainder);
    number /= 2;
  }
  if(number == 1){
    binaryBits.push_back(1);
  } else {
    binaryBits.push_back(0);
    binaryBits.push_back(1);
  }

//  for(vector<int>::iterator it = binaryBits.begin(); it != binaryBits.end(); it++){
//    cout<<*it<<endl;
//  }

//    vector<int> binaryNumber;
//
//    for(int i=binaryBits.size()-1; i>= 0; i--){
//        binaryNumber.push_back(binaryBits[i]);
//    }
//    cout<<binaryBits.size();
    cout<<binaryBits[0];
    cout<<binaryBits[1];
    cout<<binaryBits[2];
    cout<<binaryBits[3];
    cout<<binaryBits[4];
    cout<<binaryBits[5];
    cout<<binaryBits[6];
    cout<<endl;

    bool resp = (binaryBits[operand1] == binaryBits[operand2]) ? true : false;
    cout<<resp<<endl;
//    for(vector<int>::iterator it = binaryBits.end(); it != it.begin(); it--){
//        binaryNumber.push_back(*it);
//    }

  //sorry I will use my own compiler

  }


}
