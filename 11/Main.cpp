//
// Created by Adek on 2021. 12. 02..
//
#include <map>
#include "TextIndexer.h"

int main(){
    TextIndexer textIndexer("index.txt");
    textIndexer.print();
    TextIndexer textIndexer1("bible.txt");
    textIndexer1.print();
}