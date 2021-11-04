#include "PointSet.h"
#include <iomanip>
#include "Polynomial.h"


int main(){
    /*
    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;

        n = n << 1;
    }
    PointSet pset1(10);
    cout<<"#points: " <<Point::getCounter()<<endl;
    PointSet pset2(20);
    cout<<"#points: " <<Point::getCounter()<<endl;
     */
    double ps[] = {1,2,3};
    double ps2[] = {1, 1, 1, 1 ,1 ,1};
    Polynomial polinoms (3, ps);
    polinoms.printPolynomial(cout);
    cout << polinoms.degree() << endl;
    cout << polinoms.evaluate(1);
    cout << endl;
    Polynomial pol = polinoms.derivative();
    pol.printPolynomial(cout);
    Polynomial pol2  = (polinoms + pol);
    pol2.printPolynomial(cout);
    Polynomial pol3 (6, ps2);
    Polynomial pol4 = (pol3 - polinoms);
    Polynomial pol5 = polinoms * polinoms;
    pol4.printPolynomial(cout);
    cout << -pol4;
}