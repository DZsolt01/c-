#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define MAX 1000

using namespace std;



int main(){
    int x[100];
    int n = 10;
    cout<<"x = [";
    for( int i=0; i<n; ++i ){
        x[i] = rand() % MAX;
        cout<<x[i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legkisebb : " << *min_element(x, x+n) << endl;
    vector<int> v;
    v.reserve(100);
    cout<<"v = [";
    for( int i=0; i<n; ++i ){
        v.emplace_back( rand() % MAX );
        cout<<v[ i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legnagyobb: " << *max_element(v.begin(),v.end()) << endl;
    return 0;
}