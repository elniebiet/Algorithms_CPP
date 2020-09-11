#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
  string line;
  //while (getline(cin, line)) {
    //cout << line << endl;
  //}
  getline(cin, line);

  //store all characters in alphabets
  char alphabets[52];
  for(int i=65, k=0; i<=90; i++,k++){
    alphabets[k] = (char)(i);
  }
  for(int i=97, k=26; i<=122; i++,k++){
    alphabets[k] = (char)(i);
  }

  string output = "";
  //for each character, check if all the characters exist
  for(int i=0, l=26; i<26; i++, l++){
    int found = 0;
    for(int k=0; k<line.length(); k++){
      if(alphabets[i] == line[k] || alphabets[l] == line[k]){
        found = 1;
      }
    }

    if(found == 0){
      cout<<alphabets[l];
    }
  }

  //for(int i=0; i<line.length(); i++){
    //int found = 0;
    //for(int k=0; k<52; k++){
     // if(line[k] == alphabets[i]){
       // found = 1;
      //}
    //}
    //if(found == 0){
      //output += line[i];
    //}

  //}
  //cout<<output<<endl;
  //sorry i will use my compiler

}
