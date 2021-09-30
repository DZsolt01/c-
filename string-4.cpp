#include <iostream>
#include <sstream>
using namespace std;

string capitalizeWords(string text){
    istringstream ss(text);
    string newString = "";
    string word;
    while(getline(ss, word, ' ') ){
        word[0] = toupper(word[0]);
        for(int i = 1; i < word.length(); ++i){
            word[i] = tolower(word[i]);
        }
        newString += (word + ' ') ;
    }
    return newString;
}

int main(){
    string line;
    while( getline(cin, line) && !line.empty() ){
        cout << capitalizeWords(line) << endl;
    }

    return 0;
}