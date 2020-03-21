#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector <char> tab;
vector <string> tablica;

bool czyOddalone10(char znak1, char znak2) {
    if (abs((int)znak1 - (int)znak2) >= 10) { // zamiana na ASCII
        return true;
    }
    else return false;
}


int main()
{

    bool test;
    string line;
    ifstream plik;
    //otwarcie pliku sygnaly.txt
    plik.open("C:\\sygnaly.txt");

    if (plik.is_open())
    {
        ofstream file;
        file.open("wyniki4.txt");
        while (getline(plik, line))
        {
            test = true;


            for (int i = 1; i < line.size(); i++) {
                if (czyOddalone10(line[i], line[i - 1]) == true) {
                    test = false;
                    break;
                }
            }

            if (test == true) {
                cout << line << endl;
                file << line; // zapisanie lini do pliku
            }
  
        } 
        plik.close();
        file.close();
    } 
    return 0;
}


