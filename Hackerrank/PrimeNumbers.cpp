#include <iostream>
using namespace std;

int main()
{

    int n;
    cin>>n;
    //loop through all the numbers
    //for each check from 2 to half if it is divisible
    bool primeNumber = false;

    if(n > 3){
        cout<<3<<" - ";
    }
    for(int i=2; i<n; i++){
        for(int k=2; k<=i/2; k++){
            if(i%k == 0){//not a prime number
                primeNumber = false;
                break;
            } else {
                primeNumber = true;
            }
        }

        if(primeNumber == true){
            cout<<i<<" - ";
            primeNumber = false;
        }
    }
    return 0;
}
