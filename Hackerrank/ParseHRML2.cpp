#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//tags
struct tag {
    string tagName;
    string tagAttribs;
    string tagLevel;
};

typedef struct tag tag_t;

int main()
{
    int hrmlLines, queries;
    string line;
    getline(cin, line);
    stringstream st(line);
    st>>hrmlLines;
    st>>queries;

    string hrmlString = "";
    vector<string> _queries;
    for(int i=0; i<hrmlLines; i++){
        getline(cin, line);
        hrmlString += line;
    }
    for(int i=0; i<queries; i++){
        getline(cin, line);
        _queries.push_back(line);
    }

    vector<tag_t> tags;

    //string hrmlString = "<tag1 value = \"HelloWorld\"><tag2 name = \"Name1\"><tag3 me=\"abhay\"></tag3></tag2></tag1>";
    //remove " sign
    hrmlString.erase(remove(hrmlString.begin(), hrmlString.end(), '\"'), hrmlString.end());
    //cout<<hrmlString<<endl;

    int counter = 0;

    while(1){
        tag_t tag;

        //get outer tag
        stringstream ss(hrmlString);
        char firstChar;
        string tagName;
        ss>>firstChar;
        ss>>tagName;
        tag.tagName = tagName;

        //get attributes

        string attrbs = hrmlString.substr(hrmlString.find(tagName)+tagName.length(), hrmlString.find(">") - tagName.length() - 1);
        //cout<<attrbs<<endl;
        tag.tagAttribs = attrbs;

        if(counter == 0){
            tag.tagLevel = tagName;
            tags.push_back(tag);
        } else {
            tags[counter].tagAttribs = attrbs;
        }

        //check if string has inner tag, find next < sign, and check if it has a following /
        int res = hrmlString.find("<", hrmlString.find(">"));
        if(hrmlString[res+1] != '/'){
            //create new tag
            hrmlString = hrmlString.substr(hrmlString.find(">") + 1);
            stringstream sstring(hrmlString);
            tag_t tg;
            char frstChar;
            string tgName;
            sstring>>frstChar;
            sstring>>tgName;
            tg.tagName = tgName;
            tg.tagLevel = tags[counter].tagLevel + "." + tgName;

            tags.push_back(tg);

        } else break;

        counter++;

    }



    for(int i=0; i<_queries.size(); i++){
        //get attribute
        string tagLevel, qry = _queries[i];
        string _attrib = qry.substr(qry.find("~")+1);
        tagLevel = qry.substr(0, qry.length() - _attrib.length()-1);
        //cout<<tagLevel<<endl;

        //find the attribute
        for(vector<tag_t>::iterator it = tags.begin(); it != tags.end(); it++){
            //cout<<(*it).tagName<<" "<<(*it).tagAttribs<<" "<<(*it).tagLevel<<endl;
            if((*it).tagLevel == tagLevel){
                bool found = false;
                //split attributes
                stringstream su((*it).tagAttribs);
                string name;
                char equals;
                string val;

                //cout<<_attrib<<endl;
                while(!su.eof()){
                    su>>name;
                    su>>equals;
                    su>>val;
                    //cout<<name<<" "<<val<<endl;
                    if(name == _attrib){
                        cout<<val<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"Not Found!"<<endl;
                }

            }
        }

    }

}
