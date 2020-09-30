#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string string1 = "abaa";
    string string2 = "dog cat dog dog";

    //save unique characters from string1
    //save unique characters from string2
    //save complete string1
    //save complete string2
    //loop through string1 or string2
    //find the index of each word check that it tallies with the other
    vector<char> _string1;
    vector<char> chComplete;
    vector<string> _string2;
    vector<string> strComplete;

    for(int i=0; i<string1.length(); i++){
        chComplete.push_back(string1[i]);
        if(find(_string1.begin(), _string1.end(), string1[i]) == _string1.end()){
            _string1.push_back(string1[i]);
        }
    }
    stringstream ss(string2);
    string str;
    while(!ss.eof()){
        ss>>str;
        strComplete.push_back(str);
        if(find(_string2.begin(), _string2.end(), str) == _string2.end()){
            _string2.push_back(str);
        }
    }

    bool valid = true;
    int indexFound;
    vector<string>::iterator it;
    for(int i=0; i<strComplete.size(); i++){
        //get what index is that string
        for(int k=0; k<_string2.size(); k++){
            if(strComplete[i] == _string2[k]){
                indexFound = k;
                break;
            }
        }
        if(chComplete[i] != _string1[indexFound]){
            valid = false;
        }
    }

    cout<<valid;
    return 0;
}
