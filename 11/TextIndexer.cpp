//
// Created by Adek on 2021. 12. 02..
//

#include "TextIndexer.h"

TextIndexer::TextIndexer(const string &fileName) {
    ifstream MyReadFile(fileName);
    if(!MyReadFile){
        throw runtime_error("ERROR!");
    }
    string line;
    int lineNumber = 1;
    while (getline (MyReadFile, line)) {
        if(line.empty()){
            break;
        }
        for(auto &it: line){
            it = (char)toupper(it);
            if(!isupper(it)) {
                it = ' ';
            }
        }
        istringstream ss(line);
        string indexname;
        getline(ss, indexname);
        index.insert(make_pair(indexname, set<int>()));
    }
    while (getline (MyReadFile, line)) {
        if(line.empty()){
            break;
        }
        for(auto &it: line){
            it = (char)toupper(it);
            if(!isupper(it)) {
                it = ' ';
            }
        }
        istringstream ss(line);
        string word;
        while(ss >> word){
            if(index.contains(word)){
                index[word].insert(lineNumber);
            }
        }
        lineNumber++;
    }
    MyReadFile.close();
    }

void TextIndexer::print() {
    for(auto &it: index){
        cout << it.first << ":";
        for(auto &it2: it.second){
            cout << it2 << " ";
        }
        cout << endl;
    }
}
