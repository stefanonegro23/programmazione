#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char *argv[]) {
    // cout << argc << "\n"; stampo numero di input +1 (che è il nome del file stesso)
    // cout << argv[0] << "\n";  stampo nome file e vado a capo
    // cout << argv[1] << "\n"; stampo nome file testo e vado a capo
    ifstream ifs(argv[1]);
    if (ifs.is_open()){
        while(!ifs.eof()){
            string location;
            double temp1, temp2, temp3, temp4;
            ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
            double media = (temp1 + temp2 + temp3 + temp4)/4;
            cout << "Avarage temperature in " << location << " is " << media << "\n";
        }
    }
return 0;
}