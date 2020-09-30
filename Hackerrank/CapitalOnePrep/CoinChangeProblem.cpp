#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int amount = 1950;
    vector<int> denominations;
    denominations.push_back(500);
    denominations.push_back(100);
    denominations.push_back(50);
    denominations.push_back(10);
    denominations.push_back(5);
    denominations.push_back(2);
    denominations.push_back(1);

    int remainder = amount;
    int i=0;
    while(remainder != 0){
        if(amount > denominations[i]){
            remainder = amount % denominations[i];
            cout<<denominations[i]<< " x "<<int(amount/denominations[i])<<endl;
            amount = remainder;
        }
        i++;
    }
    return 0;
}
