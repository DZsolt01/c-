#include "functions.h"
using namespace std;
#include <time.h>

double random_num(int min, int max){
    return rand() % (max - min) + min;
}

int main(){
    for(int i = 0; i < 128; ++i){
        cout << countBits(i) << endl;
    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }

    srand(time(NULL));
    double a[100];
    for(int i = 0; i < 100; ++i){
        a[i] = random_num(10, 100);
    }
    cout << "Tomb atlag erteke:" << mean(a, 100) << endl;
    cout << "STDDEV:" << stddev(a, 100) << endl;

    pair<double, double> p = max2(a, 100);
    cout << p.first << " " << p.second << endl;
    return 0;
}