#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int factorial(int f){
    if (f==0) return 1;
    else return f*factorial(f-1);
}
void Out_Rez(int number_func, double x, double n);
int main(){
    setlocale(LC_ALL, "Russian");
    int number_func;
    cout << "Выберите номер функции которую хотите посчтитать:\n1. S(x)\n2. Y(x)\n3. |Y(x)-S(x)|"<<endl;
    cin >> number_func;
    while(cin.fail() || (1 > number_func || number_func > 3)){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Повторите снова" << endl;
        cin >> number_func;
    }
    cout << "Введите значения для функции" << endl;
    double a, b, h, n, s, x, y;
    cout << "a = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nh = ";
    cin >> h;
    cout << "\nn = ";
    cin >> n;
    for(;a<b;a+=h) {
        x = a;
        Out_Rez(number_func, x, n);
    }
}
void Out_Rez(int number_func, double x, double n) {
    switch (number_func) {
        case 1: {
            double s = 0;
            for (int k = 1; k < n; k++) {
                s += pow(-1, k) * (pow(2 * x, 2 * k) / factorial(2 * k));
            }
            printf("\nX=%7.7f\t S(x)=%7.7f", x, s);
            break;
        }
        case 2: {
            double y;
            y = 2 * (pow(cos(x), 2) - 1);
            printf("\nX=%7.7f\t Y(x)=%7.7f", x, y);
            break;
        }
        case 3:{
            double y, s=0;
            y = 2*(pow(cos(x), 2)-1);
            for (int k = 1; k<n; k++){
                s += pow(-1, k) * (pow(2*x, 2*k)/ factorial(2*k));
            }
            printf("\nX=%7.7f\t S(x)=%7.7f\t Y(x)=%7.7f\t |Y(x)-S(x)|=%7.7f", x, s, y, abs(y-s));
            break;
        }
    }
}