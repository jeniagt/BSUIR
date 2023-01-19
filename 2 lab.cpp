#include<iostream>
#include <cmath>
using namespace std;
int main(int argc, char* argv[]){
    setlocale(LC_ALL, "Russian");
    double x, z, n, k, m, rez, funct;
    int key;
    cout<< "z = ";
    cin >> z;
    cout<< "n = ";
    cin >> n;
    cout<< "k = ";
    cin >> k;
    cout<< "m = ";
    cin >> m;
    if (z > 1) x = z;
    else x = (pow(z, 2) + 1);
    do {
        cout << "\nВведите\n1 если хотите выбрать 2x,\n2 - если x ^ 2,\n3 - если x / 3 : ";
        cin >> key;
    } while (key<1 || key>3);
    cout << "\nПри функции: ";
    switch (key) {
        case 1:
            funct = 2 * x;
            cout << "2x";
            break;
        case 2:
            funct = pow(x, 2);
            cout << "x^2";
            break;
        case 3:
            funct = x / 3.0;
            cout << "x/3";
            break;
    }
    cout << "\nЗначениях:" << "\nn = " << n << "\nk = " << k << "\nm = " << m;
    cout << '\n' << "z = " << z << "\nx = ";
    if (z > 1) cout << "z = " << x;
    else cout << "z^2 + 1 = " << x;

    rez = sin(n *funct) + cos(k * x) + log10(m * x);
    cout << "\nРезультат вычисления: " << rez <<" \n";
    return 0;
}
