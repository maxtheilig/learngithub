#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

int main()
{
double a,b,c,p,q;
cout << "Gib die Koeffizieten des Polynom zweiten Gerades an, dessen Nullstellen du berechnen möchtest." << endl;
cin >> a;
cin >> b;
cin >> c;
p = b/a; q = c/a;
complex<double> w = sqrt( pow(p/2,2) - q);
complex<double> x1 = -p/2 + w;
complex<double> x2 = -p/2 - w;
cout << "Die Nullstellen lauten: " << x1 << " und " << x2 << endl;

return 0;
}
