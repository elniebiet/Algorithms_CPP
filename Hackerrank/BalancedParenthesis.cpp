#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main()
{
    map<char, char> listOfCharacters;
    stack<char> characters;

    listOfCharacters.insert(make_pair('{', '}'));
    listOfCharacters.insert(make_pair('[', ']'));
    listOfCharacters.insert(make_pair('(', ')'));

    string testString = "{}[]{{}}[[[]]]";

    for(int i=0; i<testString.length(); i++){
        if(listOfCharacters[testString[i]] != NULL){
            characters.push(testString[i]);
        } else {
            if(listOfCharacters[characters.top()] == testString[i]){
                characters.pop();
            }
        }
    }
    cout<<characters.size();
    return 0;
}
