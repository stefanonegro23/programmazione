# include <iostream>
using namespace std;
# include <array>
# include <cmath>
int main()
{
static const int N = 10;
double arr[N]= {0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
double minimo = arr[0];
double massimo = arr[0];
for (int i = 0; i<N; i++)
{
    minimo = min(minimo,arr[i]);
    massimo = max(massimo,arr[i]);
}
cout << "Il minimo è" << minimo << " \n";
cout << "Il massimo è" << massimo << " \n";
double somma = 0.0;
for (int i=0; i < N; i++)
{
    somma += arr[i];
}
double media = somma/N;
cout << "La media è" << media << " \n";
double somma_scarti_quadratici = 0.0;
for (int i=0; i < N; i++)
{
    somma_scarti_quadratici += pow(arr[i]-media,2);
}
double varianza = somma_scarti_quadratici/N;
double dev_standard = sqrt(varianza);
cout << "La deviazione standard è" << dev_standard << " \n";
}