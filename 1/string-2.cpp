#include <iostream>
#include <sstream>
using namespace std;

int countWord(string text){
    istringstream ss(text);
    string token;
    int sum = 0;
    while(getline(ss, token, ' ')){
        sum++;
    }
    return sum;
}

int main(){
    cout << countWord("alma korte kecske") << endl;

    return 0;
}