#include <iostream>

using namespace std;

//deklaracja funkcji, ktora wymaga wprowadzenia liczby (n)
int Funkcja(int n) {
    int p = 1;
    int q = n;
    int s;
    int licznik = 0;
    //petla - rob cos dopoki spelniony warunek
    do {
        s = (p + q) / 2;

        if ((s * s * s) < n) {
            p = s + 1;
        }
        else q = s;
        //to jest licznik, ktory sprawdza ile razy wykonana zostala petla (zwieksza sie o 1 z kazdym obrotem)
        licznik++;
    } while (p < q); //warunek
    cout << p << "  -  " << licznik; // funkcja wypisuje "p" oraz ile obrotow zrobila petla
    return 0;
}

int main()
{
    
    int n;
    //petla for aby wywolac funkcje dla kazdego argumentu od 1 do 2000
    for (int i = 1;i <2000;i++) {
        //przy wyniku dodatkowo podaje dla jakiej liczby zostala wywolana funkcja
        cout << i << "  -  ";
        Funkcja(i);
        cout << endl;
    }
    
}
