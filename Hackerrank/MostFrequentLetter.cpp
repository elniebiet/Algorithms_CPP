#include <iostream>
using namespace std;

int main()
{
    string str = "I am a man in a house";
    int countOccurrence = 0;
    char highestLetter;
    int currentMax = 0;

    for(int i=0; i<str.length(); i++){
        for(int k=0; k<str.length(); k++){
            if((str[i] == str[k]) && str[i] != ' '){
                countOccurrence++;
            }
        }
        if(countOccurrence > currentMax){
            currentMax = countOccurrence;
            highestLetter = str[i];
        }
        countOccurrence = 0;
    }

    cout<<highestLetter;
    return 0;
}
