#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello";
    int found=str.find('.');
    std::cout << "Period found at: " << found << '\n';
}
