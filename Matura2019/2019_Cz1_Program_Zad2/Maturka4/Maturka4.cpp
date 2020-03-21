#include <iostream>
#include <string>

using namespace std;

int licznik = 0;

int pisz(string s, unsigned int n, int k) {
    licznik++;
    if (s.size() == n) {
        cout << s << endl;
    }
    else {
        for (int i = 0; i <= k - 1; i++) {
             pisz(s + to_string(i), n, k );
        }
    }
    return 0;
}

int main()
{
    for (int i = 1; i < 4; i++) {
        for (int j = 2; j <= 10; j++) {
            licznik = 0;
            cout << "-------------------------------------------------" << endl;
            cout << "Pisz dla: " << "n : " << i << "    k : " << j << endl;
            pisz("", i, j);
            cout << "LICZNIK:  "<< licznik << endl;
        }
    }
}


