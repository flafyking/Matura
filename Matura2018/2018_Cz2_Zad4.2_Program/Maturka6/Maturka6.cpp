#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <char> tab;

// funkcja sprawdzajaca czy dany znak sie powtorzyl
bool czyPowtorzona(char znak) {
    for (int i = 0; i < tab.size(); i++) {
        if (tab[i] == znak) {
            return true;
        }
    }
    return false;
}

int main()
{
    
    int dlugosc;
    int tablica[1000];
    string line, slowo;
    ifstream plik;
    //otwarcie pliku sygnaly.txt
    plik.open("C:\\sygnaly.txt");

    if (plik.is_open())
    {
        int najdluzszy = 0;
        while (getline(plik, line))
        {
            cout << line << "        ";
            dlugosc = line.size();
            for (int i = 0; i < line.size(); i++) {
                if (czyPowtorzona(line[i]) == false) { // jesli nie powtorzona to wstawiam znak do tablicy wektorowej
                    tab.push_back(line[i]);
                }
            }
            if (tab.size() > najdluzszy) { // po wypisaniu ciagu liter ktore sie nie powtarzaja, szukam najdluzszego ciagu znaku
                najdluzszy = tab.size();
                slowo = line;
            }

            for (int i = 0; i < tab.size(); i++) { // wypisanie liter
                cout << tab[i];
            }
            cout << endl;
            tab.clear();

        }
        cout << "Najdluzsze: " << slowo << "   Liter: " << najdluzszy << endl; // wypisanie najdluzszego ciagu znakow 
       
        plik.close();
    }
    //zapisanie do pliku wyniki4.txt
    ofstream file;
    file.open("wyniki4.txt");
    file << slowo;
    file.close();
    return 0;

}


