#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> words;
vector<int> wordsamount;

bool change(int i, int j){
    if(i > j){
        string tempword = words[i];
        words[i] = words[j];
        words[j] = tempword;
        return 1;
    }
    return 0;
}

int main(){

    string text;
    try
    {
        ifstream MyReadFile("bible.txt");
        while(getline(MyReadFile, text) ){
            istringstream ss(text);
            string word2;
            while( getline(ss, word2, ' ') ){
                const auto p = find(words.begin(), words.end(), word2);
                if(p != words.end()){
                    int index = p - words.begin();
                    wordsamount[index]++;
                }
                else{
                    words.push_back(word2);
                    wordsamount.push_back(0);
                }

            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    sort(wordsamount.begin(), wordsamount.end(), change);
    for(int i = 0; i < 10; ++i){
        cout << words[i] + ':';
        cout << wordsamount[i] << endl;
    }

    return 0;
}
    
