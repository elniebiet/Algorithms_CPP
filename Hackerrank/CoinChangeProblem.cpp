#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int amount = 400;
    vector<int> currencies;

    currencies.push_back(500);
    currencies.push_back(100);
    currencies.push_back(50);
    currencies.push_back(20);
    currencies.push_back(10);
    currencies.push_back(5);
    currencies.push_back(1);

    //loop through starting from the largest currency,
    //if there is a remainder, use the next currency
    map<int, int> numTimes;
    while(amount > 0){
        for(int i=0; i<currencies.size(); i++){
            if(currencies[i] <= amount){
                int numCurrency = amount / currencies[i];
                numTimes.insert(make_pair(currencies[i], numCurrency));
//                for(int k=0; k<numCurrency; k++){
//                    cout<<currencies[i]<<" x ";
//                }
                amount = amount % currencies[i];
                break;
            }
        }
    }

    for(map<int, int>::iterator it = numTimes.begin(); it != numTimes.end(); it++){
        cout<<it->first<<"("<<it->second<<" times)";
    }
    return 0;
}
