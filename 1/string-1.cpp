#include <iostream> // cout
#include <sstream> // stringstream, istringstream, ostringstream
using namespace std;
int main(int argc, char * argv[]){
istringstream iss("1 2 3 alma 4");
double number;
while(iss >> number){
cout<<number<<endl;
}
return 0;
}
