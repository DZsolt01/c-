//
// Created by Adek on 2021. 12. 02..
//

#ifndef INC_11_TEXTINDEXER_H
#define INC_11_TEXTINDEXER_H
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
class TextIndexer{
private:
    map<string, set<int>> index;
public:
    TextIndexer(const string &fileName);
    void print();
};
#endif //INC_11_TEXTINDEXER_H
