#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {

    int liczba, ile2, ile, wynik;

   //tablica wektorowa (mozna ja rozszerzac w trakcie dzialania programu)
    vector <int> tablica;

    srand(time(NULL));
    cout << "Ile liczb ma podac Malgosia: ";
    cin >> ile;

    cout << "Ile liczb ma podac Jas: ";
    cin >> ile2;

    //zapisanie liczb ma³gosi
    for (int i = 0; i < ile; i++) {
        liczba = rand() % 100 +1; // losowanie liczby z przedzialo od 1 do 100
        if ((liczba % 2) == 1) { // jesli reszta z dzielenia = 1 to wpisujemy liczbe do tablicy
            tablica.push_back(liczba);
        }
        else i--; // jesli reszta = 0 cofamy sie o jeden obrot w petli (bo nie przypisalismy do tablicy)
    }
    //zapisanie liczb jasia
    for (int i = 0; i < ile2; i++) {
        liczba = rand() % 100 + 1;
        if ((liczba % 2) == 0) { // analogicznie z Jasiem
            tablica.push_back(liczba);
        }
        else i--;
    }

    for (int i = 0; i < ile + ile2; i++) {
        cout << tablica[i] << endl; // wypisanie calej tablicy
    }


    //algorytm
    for (int i = 0; i < ile + 1; i++) { // petla musi sie wykonac tylko 1 raz wiecej niz wypisala elementow Malgosia (bo po nim odrazu jest liczba Jasia)
        if (tablica[i] % 2 == 0) { // szuka elementu, który jest parzysty
            wynik = tablica[i];
            break;
        }
    }

    cout << endl;
    cout << endl;

    cout << "Pierwsza liczba zapisana przez Jasia jest:  "<< wynik << endl;

}