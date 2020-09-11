#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;

int main() {
    // Example string
    std::string str = "this is 56 my id 4321 93.";

    // For atoi, the input string has to start with a digit, so lets search for the first digit
    size_t i = 0;
    for ( ; i < str.length(); i++ ){ if ( isdigit(str[i]) ) break; }

    // remove the first chars, which aren't digits
    str = str.substr(i, str.length() - i );

    // convert the remaining text to an integer
    int id = atoi(str.c_str());

    // print the result
    std::cout << id << std::endl;
}
