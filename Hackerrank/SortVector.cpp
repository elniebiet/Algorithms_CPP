#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> numbers;
    numbers.push_back("zootopie");
    numbers.push_back("aniebiet");
    numbers.push_back("michael");
    numbers.push_back("big man");
    numbers.push_back("humble man");

    sort(numbers.begin(), numbers.end());
    for(vector<string>::iterator it = numbers.begin(); it != numbers.end(); it++){
        cout<<*it<<endl;
    }

}
