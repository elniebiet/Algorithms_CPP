#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    vector<int> nums  = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int findNum = 19;

    sort(nums.begin(), nums.end());

    if(binary_search(nums.begin(), nums.end(), findNum)){
        cout<<"Default Binary Search: found! ";
    }
    auto it = lower_bound(nums.begin(), nums.end(), findNum);
    cout<<"at "<<distance(nums.begin(), it)<<endl;


    //check if left and right element
    int left = 0;
    int right = nums.size() - 1;
    int currentIndex = (right - left) / 2;

    int counter  = 0;
    while(1){
        if(nums[currentIndex] == findNum){
            cout<<"Custom found at: "<<currentIndex<<endl;
            break;
        } else if(nums[currentIndex + 1] == findNum){
            cout<<"Custom found at: "<<currentIndex + 1<<endl;
            break;
        } else if((currentIndex - 1 >= 0 ) && nums[currentIndex - 1] == findNum){
            cout<<"Custom found at: "<<currentIndex - 1<<endl;
            break;
        } else if(findNum < nums[currentIndex]){
            right = currentIndex;
        } else if(findNum > nums[currentIndex]){
            left = currentIndex;
        }

        currentIndex = (right - left) / 2 + left;
//        cout<<"left: "<<left<< " current: "<<currentIndex<<" right: "<<right<<endl;
        counter++;
    }

    cout<<"Loops: "<<counter<<endl;

    return 0;

}
