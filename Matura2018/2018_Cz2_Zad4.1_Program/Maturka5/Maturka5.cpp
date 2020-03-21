#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int licznik = 0;
    string line, slowo;
    ifstream plik;
    //otwieram plik sygnaly
    plik.open("C:\\sygnaly.txt");

    if (plik.is_open())
    {
        //pobieram tekst wiersz po wierszu
        while (getline(plik, line))
        {
            cout << line << endl;
            // z kazda linia zwiekszam licznik
            licznik++;
            // jesli licnzik podzielny przez 40 to pobieram 10 znak z wiersza
            if (licznik % 40 == 0) {
                // przypisuje literke do zmiennej slowo
                slowo = slowo + line[9];
            }
        }
        plik.close();
    }

    cout << licznik << endl;
    cout << slowo << endl;
    //tworze plik w ktorym zapisuje odpowiedz
    ofstream file;
    file.open("wyniki4.txt");
    file << slowo;
    file.close();
    return 0;

}

