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
    bool text = false;
    while (getline (MyReadFile, line)) {
        if(line.empty()){
            text = true;
            continue;
        }
        for(auto &it: line){
            it = (char)toupper(it);
            if(!isupper(it)) {
                it = ' ';
            }
        }
        istringstream ss(line);
        if (!text) {
            string indexname;
            getline(ss, indexname);
            index.insert(make_pair(indexname, set<int>()));
        } else {
            string word;
            while(ss >> word){
                if(index.contains(word)){
                    index[word].insert(lineNumber);
                }
            }
            lineNumber++;
        }

    }
    MyReadFile.close();
}

void TextIndexer::print() {
    for(auto &it: index){
        int lastLine = 0;
        cout << it.first << ":";
        for(auto &it2: it.second){
            cout << it2 << " ";
        }
        cout << endl;
    }
}
