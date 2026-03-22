# include <iostream>
using namespace std;
# include <array>

int main()
{
double ad[4] = {0.0, 1.1, 2.2, 3.3};
cout << &ad[0] << "\n";
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
cout << &af[0]<< "\n";
int ai[3] = {0, 1, 2};
cout << &ai[0] << "\n";
int x = 1;
cout << &x << "\n";
float y = 1.1;
cout << &y << "\n";
(&y)[1] = 0; // x diventa 0 perchè è consecutivo a y (sto andando quattro byte oltre y, quattro byte è la misura del file)
cout << x << "\n";
return 0;
}
//fare il disegno della memoria convertendo le differenze in esadecimale in decimale e spiegare come la y influenza il valore di xs