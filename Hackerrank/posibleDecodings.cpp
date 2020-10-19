#include <iostream>
#include <map>

using namespace std;

int countDecodings(string str){
    if(str.length() == 0){
        return 0;
    }
    map<char, int> characters;
    for(int i=65, k=1; i<(65+26); i++, k++){
        characters.insert(make_pair((char)i, k));
        //cout<<(char)i<<" "<<k<<endl;
    }

    int numWays = 0;
    if(str.length() >= 0){
        numWays++;
    }
    for(int i=1; i<str.length(); i++){

        if((str[i] - 48) != 0){
            if((str[i-1] - 48 != 0) && (str[i-1] - 48) <= 2 && (str[i] - 48) <= 6){
                numWays++;
            }
        }
    }

    return numWays;
}
int main()
{
    //12345
    string str = "123456789";
    cout<<countDecodings(str);

    return 0;
}
