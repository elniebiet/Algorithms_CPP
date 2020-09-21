#include <iostream>
#include <stack>
#include <map>
using namespace std;
int main()
{
    stack<char> parenthesis;
    string testString = "{[([()])]}";
    map<int, int> listOfChars;
    listOfChars.insert(make_pair('{', '}'));
    listOfChars.insert(make_pair('(', ')'));
    listOfChars.insert(make_pair('[', ']'));

    for(char a: testString){
        if(parenthesis.empty()){
            parenthesis.push(a);
        } else if(a == listOfChars[parenthesis.top()]){
            parenthesis.pop();
        } else if(a != listOfChars[parenthesis.top()]){
            parenthesis.push(a);
        }
    }

   cout<<parenthesis.size()<<endl;
    return 0;
}
