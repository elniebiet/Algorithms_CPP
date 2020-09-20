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
    string tagName = string("");
    string attributes = string("");
    string tagLevel = string("");
    tag *next = NULL;
};

typedef struct tag tag_t;

string getFirstTag(string str){
    string firstTag = string("");
    stringstream fT(str);
    fT>>firstTag;
    return firstTag;
}

void setAttributes(string attrs, tag_t tag){
    // stringstream attrbs(attrs);
    // string currentAttbs, currentValue;
    // char equalsSign;
    // while(!attrbs.eof()){
    //     attrbs >> currentAttbs;
    //     attrbs >> equalsSign;
    //     attrbs >> currentValue;
    //     tag.attributes[currentAttbs] = currentValue;
    // }
}
int main() {
    //handle first tag contents first, we can loop later to handle everything
    string mainString = "<tag1 value = \"HelloWorld\"><tag2 name = \"Name1\"></tag2></tag1>";
    //remove quotes from mainstring;
    mainString.erase(remove(mainString.begin(), mainString.end(), '\"'), mainString.end());

    //create headTag

    tag_t *headTag; // = (tag_t*) malloc(sizeof(tag_t));

    int counter = 0;
    while(1){
        //get first tag details
        string firstTag = getFirstTag(mainString);
        //cout<<"First tag: "<<firstTag<<endl;

        string tagName = firstTag.substr(1, firstTag.length()-1);
        string lastTag = "</" + tagName + ">";
        int firstTagIndex = mainString.find(firstTag);
        string attrs = mainString.substr(mainString.find(firstTag) + firstTag.length(), mainString.find(">")-firstTag.length());
        //headTag = (tag_t*) malloc(sizeof(tag_t));

        if(counter == 0){
            headTag = (tag_t*) malloc(sizeof(tag_t));

            //set tagName
            headTag->tagName = tagName;

            //set tag level
            headTag->tagLevel = tagName;

            //set attrbs
            headTag->attributes = attrs;
            cout<<"tag: "<<firstTag<<endl;
//            cout<<"first loop head: "<<head<<endl;
//            cout<<"first loop headtag: "<<headTag<<endl;
        } else {
//            cout<<"second loop head is: "<<head<<endl;
//            cout<<"second loop headtag is: "<<headTag<<endl;
            headTag = headTag->next;
//            cout<<"head is: "<<head<<endl;
            //head->next = &headTag;
        }

        //set previous: is null, already null

        //set next if there is a next tag
        int nextInnerTagIndex = mainString.find('<', firstTagIndex + firstTag.length());
        //if there is a next tag, set the next attr, and the tag level of the next tag
        if(mainString[nextInnerTagIndex + 1] != '/'){ //if next '<' is not '</'
            mainString = mainString.substr(nextInnerTagIndex);
            //get first tag details
            string firstTg = getFirstTag(mainString);
            cout<<"tag: "<<firstTg<<endl;

            string tgName = firstTg.substr(1, firstTg.length()-1);
            string lastTg = "</" + tgName + ">";
            int firstTgIndex = mainString.find(firstTg);
            string attrbts = mainString.substr(mainString.find(firstTg) + firstTg.length(), mainString.find(">")-firstTg.length());

            //string getTagName
            //mainString = mainString.substr(nextInnerTagIndex+2);

            tag_t *nextTag = (tag_t*) malloc(sizeof(tag_t));
            nextTag->tagName = tgName;
            nextTag->attributes = attrbts;
            //setAttributes(attrbts, nextTag);
            nextTag->tagLevel = (headTag->tagLevel).append(".").append(tagName);
            headTag->next = nextTag;
            //cout<<"head is: "<<head<<" headTag is: "<<&headTag<<endl;
            // cout<<"heads next is: "<<head->next<<endl;
            //head = head->next;

        } else break;

        counter++;
    }




    return 0;
}
