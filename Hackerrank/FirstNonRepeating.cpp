#include <iostream>
using namespace std;

int main()
{
    string str = "i am a man in a house";
    int countOccurrence = 0;
    for(int i=0; i<str.length(); i++){
        for(int j=0; j<str.length(); j++){
            if(str[i] == str[j]){
                countOccurrence++;
            }
        }
        if(countOccurrence == 1){
            cout<<str[i];
            break;
        }
        countOccurrence = 0;
    }
    return 0;
}
