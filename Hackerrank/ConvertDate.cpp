#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string input = "09-24-2020";
    stringstream st(input);
    int month, day;
    char dash;
    st>>month;
    st>>dash;
    st>>day;

    vector<string> months;
    months.push_back("January");
    months.push_back("February");
    months.push_back("March");
    months.push_back("April");
    months.push_back("May");
    months.push_back("June");
    months.push_back("July");
    months.push_back("August");
    months.push_back("September");
    months.push_back("October");

    vector<string> suffixes;
    suffixes.push_back("th");
    suffixes.push_back("st");
    suffixes.push_back("nd");
    suffixes.push_back("rd");
    suffixes.push_back("th");
    suffixes.push_back("th");
    suffixes.push_back("th");
    suffixes.push_back("th");
    suffixes.push_back("th");
    suffixes.push_back("th");

    cout<<months[month - 1]<<" "<<day;
    cout<<suffixes[day%10];

    //cout<<month<<" - "<<day;

    return 0;
}
