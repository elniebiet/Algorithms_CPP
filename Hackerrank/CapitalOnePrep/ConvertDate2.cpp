#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string date = "02-30-19";
    int day, month, year;
    char dash;
    stringstream ss(date);
    ss>>month;
    ss>>dash;
    ss>>day;
    ss>>dash;
    ss>>year;

    vector<string> months;
    months.push_back("Jan");
    months.push_back("Feb");
    months.push_back("Mar");
    months.push_back("Apr");
    months.push_back("May");
    months.push_back("Jun");
    months.push_back("Jul");
    months.push_back("Aug");
    months.push_back("Sept");
    months.push_back("Oct");
    months.push_back("Nov");
    months.push_back("Dec");

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

    year = (year < 20) ? 2000 + year : 1900 + year;
    int dayIndex = day % 10;
    cout<<months[month - 1]<<" "<<day<<suffixes[dayIndex]<<", "<<year;

    return 0;
}
