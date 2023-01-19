#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(nullptr));
    int* a;  // указатель на массив
    int i = 0, size = 0;
    int f = 0;
    int sum = 0; //сумма модулей
    int flag = 0; //флаг что найден отрицательный элемент в массиве
    system("clear");
    cout << "Enter array size:";
    cin >> size;
    while (cin.fail() || (size <= 0)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error, try again " << endl;
        cin >> size;
    }
    a = new int[size];
    // Выделение памяти
    do {
        cout << endl << "Choose manual filling (1) or random (2): " << endl;
        cin >> f;
    } while (f < 1 || f > 2);
    switch (f) {
        case 1: {
            // Ввод элементов массива
            for (i = 0; i < size; i++) {
                cout << "a[" << i << "]=";
                cin >> a[i];
                while (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Error, try again " << endl;
                    cout << "a[" << i << "]=";
                    cin >> a[i];
                }
            }
            break;
        }
        case 2: {
            // Заполнение случайными числами элементов массива
            for (i = 0; i < size; i++) {
                a[i] = 10 - rand() % 20;
            }
            break;
        }
    }
    cout << endl;
    // Вывод элементов массива
    for (i = 0; i < size; i++) {
        cout << "a["; cout << i; cout << "]=";
        cout << a[i];
        cout << endl;
    }
    // Суммируем модули после отрицательного числа
    for (i = 0; i < size; i++) {
        if (flag) sum += abs(a[i]);
        if (a[i] < 0 && i != size-1) flag = 1;
    }
    if (flag) cout << endl << "Sum of modules is : " << sum << endl;
    else cout << endl << "No negative numbers" << endl;
    delete[]a;
    return 0;
}
