#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int const ilosc = 40;

int main()
{
    int x, y;
    bool powtorzona;
    float X[ilosc];
    float Y[ilosc];
    float Odleglosc[ilosc];
    float Szczyty[ilosc][3];
    float Tymczasowe;

    srand(time(NULL));
    for (int i = 0; i < ilosc; i++) { // losowanie liczb tak aby sie nie powtarzaly oraz aby Y byl dodatni i zeby x nie wystepowal dwa razy w punkcie 0
        x = (std::rand() % 40) - 20;
        y = (std::rand() % 20) + 1;
        powtorzona = false;
        for (int j = 0; j < i; j++) {
            if ((Szczyty[j][0] == x && Szczyty[j][1] == y) || (Szczyty[j][0] == 0 && x == 0)) {
                i--;
                powtorzona = true;
                break;
            }
        } 
        if (powtorzona == false) {
            Szczyty[i][0] = x;
            Szczyty[i][1] = y;
            Szczyty[i][2] = Szczyty[i][0] / Szczyty[i][1]; // liczymy odleglosc
        }

    }
    
    for (int i = 0; i < ilosc; i++) {
        cout << "X: "<< Szczyty[i][0] << "     Y: " << Szczyty[i][1] <<"    Odleglosc:  "<< Szczyty[i][2] << endl;
    }

    for (int i = 0; i < ilosc; i++) { // algorytm sortowania (babelkowego)
        for (int j = 1; j < ilosc; j++) {
            if (Szczyty[j][2] < Szczyty[j-1][2]) {
                Tymczasowe = Szczyty[j-1][2];
                Szczyty[j-1][2] = Szczyty[j][2];
                Szczyty[j][2] = Tymczasowe;

                Tymczasowe = Szczyty[j - 1][0];
                Szczyty[j - 1][0] = Szczyty[j][0];
                Szczyty[j][0] = Tymczasowe;

                Tymczasowe = Szczyty[j - 1][1];
                Szczyty[j - 1][1] = Szczyty[j][1];
                Szczyty[j][1] = Tymczasowe;
            }
        }
    }
    cout << "Posortowane odleglosci: " << endl;
    for (int i = 0; i < ilosc; i++) {
        cout << "X: " << Szczyty[i][0] << "     Y: " << Szczyty[i][1] << "    Odleglosc:  " << Szczyty[i][2] << endl;
    }

    cout << "Szczytem polozonym najbardziej na lewo jest:  X: " << Szczyty[0][0] << "     Y : " << Szczyty[0][1] <<endl;


}


