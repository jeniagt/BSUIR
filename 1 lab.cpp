#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x, y, z, a, b, c, f;
    cout << "Enter x,y,z: ";
    cin >> x >> y >> z;
    a = pow(x - 1, 1 / 3.0);
    b = pow(y + a, 1 / 4.0);
    c = abs(x - y) * (pow(sin(z), 2) + tan(z));
    f = b / c;
    cout << "f= " << f << '\n';
    return 0;
}
