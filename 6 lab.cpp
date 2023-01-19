#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main(){
    srand(time(nullptr));
    int n = 0, f = 0;
    cout << "Enter n: ";
    cin >> n;

    while(cin.fail() || n <=0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error, try again " << endl;
        cin >> n;
    }
    int** MAS = new int* [n];
    do {
        cout << endl << "Choose manual filling (1) or random (2): " << endl;
        cin >> f;

    } while (f < 1 || f > 2);
    for (int i = 0; i < n; i++) MAS[i] = new int[n];
    switch (f) {
        case 1: {
            // Ввод элементов массива
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cout << "[" << i << "][" << j << "] : ";
                    cin >> MAS[i][j];
                    while (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error, try again " << endl;
                        cout << "[" << i << "][" << j << "] : ";
                        cin >> MAS[i][j];
                    }
                }
                cout << endl;
            }
            cout << "Matrix: " << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cout << setw(4) << MAS[i][j];
                }
                cout << endl;
            }
            break;
        }
        case 2: {
            // Заполнение случайными числами элементов массива
            cout << "Matrix: " << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    MAS[i][j] = 10 - rand() % 20;
                    cout << setw(4) << MAS[i][j];
                }
                cout << endl;
            }
            break;
        }
    }
    cout << endl;
    int max;
    int flag = 1;
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j > n - i - 1; j--) {
            if(flag){
                max = MAS[i][j];
                flag = 0;
            }
            if (max < MAS[i][j])  max = MAS[i][j];
        }
        cout << endl;
    }
    cout << endl << "Max value is " << max << endl;
    for (int i = 0; i < n; i++) delete[] MAS[i];
    delete[]MAS;
    return 0;
}