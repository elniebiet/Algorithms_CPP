#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "abcdefgefdabcgbcdefagfedcbag";
//    string str = "whaatismennmenniswhaatiswhaatmenn";
    //start from length 1, check if next elements have same characters
    //else increment to two
    string foundAnagram = "";
    //found anagram
    int currentAnagLength = 1;

    while(currentAnagLength <= str.length()/2){
        string currentAnagram = str.substr(0, currentAnagLength);
        //check for other anagrams
        int currentPos = 0;
        string currentWord = "";
        bool isAnag = true;

        //while current position
        while(currentPos < str.length() - currentWord.length() + 1){
            //get current word
            currentWord = str.substr(currentPos, currentAnagLength);
            //cout<<currentPos<<" "<<currentPos + currentAnagLength<<" :"<<currentWord<<" "<<currentAnagram<<endl;

            //check for each word that all characters are same, if not stop checking
            for(int i=0; i<currentAnagram.length(); i++){
                if(  currentWord.find(currentAnagram[i], 0) == string::npos){
                    isAnag = false;
                    break;
                }
            }
            //stop checking
            currentPos += currentAnagLength;
            if(isAnag == false){
                break;
            }
        }

        //stop checking this anagram
        if(isAnag == true && currentPos == (str.length())){
            foundAnagram = currentAnagram;
            //cout<<currentAnagram<<endl;
            isAnag = true;
            break;
        } else {
            ;
        }
        currentAnagLength++;
    }

    //get the words of the anagram
    string word = "";
    word += str[0];
    for(int i=1; i<str.length()+1; i++){
        word += str[i];
        if((i+1)%(foundAnagram.length()) == 0){
            cout<<word<<" ";
            word = "";
        }
    }
    return 0;
}
