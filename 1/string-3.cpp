#include <iostream>
#include <sstream>
using namespace std;

string code(string text){
    for(int i = 0; i < text.length(); ++i){
        if( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ){
        
        if(text[i] == 'z'){
            text[i] = 'a';
            continue;
        }
        if(text[i] == 'Z'){
            text[i] = 'A';
            continue;
        }
        text[i] = char( ( (int)text[i] ) + 1);
        }
    }
    return text;
}

int main(){
    cout << code("abczAZBCD#21A") << endl;

    return 0;
}