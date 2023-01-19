#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int factorial(int f){
    if (f==0) return 1;
    else return f*factorial(f-1);
}
int main(){
    double a, b, h, n, s, x, y;
    cout << "a = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nh = ";
    cin >> h;
    cout << "\nn = ";
    cin >> n;
    for(;a<b;a+=h){
        x = a;
        y = 2*(pow(cos(x), 2)-1);
        s = 0;
        for (int k = 1; k<n; k++){
            s += pow(-1, k) * (pow(2*x, 2*k)/ factorial(2*k));
        }
        printf("\nX=%7.7f\t S(x)=%7.7f\t Y(x)=%7.7f\t |Y(x)-S(x)|=%7.7f", x, s, y, abs(y-s));
    }
}