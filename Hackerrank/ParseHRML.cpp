#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

//for every tag, if it has an inner tag, set the level of the inner tag
struct tag {
    string tagName = "";
    map<string, string> attributes;
    string tagLevel = "";
    tag *next = NULL;
};

typedef struct tag tag_t;

int main() {
    //handle first tag contents first, we can loop later to handle everything
    string mainString = "<tag1 value = \"HelloWorld\"><tag2 name = \"Name1\"></tag2></tag1>";
    //remove quotes from mainstring;
    mainString.erase(remove(mainString.begin(), mainString.end(), '\"'), mainString.end());

    //get first tag details
    string firstTag = "";
    stringstream fT(mainString);
    fT>>firstTag;
    string tagName = firstTag.substr(1, firstTag.length()-1);
    string lastTag = "</" + tagName + ">";
    string attrs = mainString.substr(mainString.find(firstTag) + firstTag.length(), mainString.find(">")-firstTag.length());

    tag_t headTag;// = (tag_t*) malloc(sizeof(tag_t*));
    headTag.tagName = tagName;
    //set attrbs
    stringstream attrbs(attrs);
    string currentAttbs, currentValue;
    char equalsSign;
    while(!attrbs.eof()){
        attrbs >> currentAttbs;
        attrbs >> equalsSign;
        attrbs >> currentValue;
        headTag.attributes[currentAttbs] = currentValue;
    }

   // cout<<headTag->attributes.size()<<endl;

    return 0;
}
