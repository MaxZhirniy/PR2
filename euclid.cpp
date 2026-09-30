#include "euclid.h"
#include "math_utils.h"
#include <iostream>

using namespace std;

int extendedEuclid(int a, int b, int &u, int &v){
    int u0 = 1, u1 = 0;
    int v0 = 0, v1 = 1;
    int tmp_v, tmp_u;
    int q, r;
    cout << "r\tu\tv\tq\n";
    cout << a << "\t" << u0 << "\t" << v0 << "\t-\n";
    cout << b << "\t" << u1 << "\t" << v1 << "\t-\n";
    while (b != 0){
        q = a / b;
        r = a % b;
        a = b;
        b = r;
        tmp_u = u1;
        u1 = u0 - q * u1;
        u0 = tmp_u;
        tmp_v = v1;
        v1 = v0 - q * v1;
        v0 = tmp_v;
        cout << b << "\t" << u1 << "\t" << v1 << "\t" << q << "\n";
    }
    u = u0;
    v = v0;
    return a;
}

void runEuclid(){
    int c, m, u, v;
    cout << "Введите c и m: ";
    cin >> c >> m;
    if (c <= 0 || m <= 0){
        cout << "Числа должны быть положительными.\n";
        return;
    }
    int d = extendedEuclid(c, m, u, v);
    cout << "НОД = " << d << "\n";
    cout << c << " * " << u << " + " << m << " * " << v << " = " << d << "\n";
    if (d == 1){
        int inverse = normalizeMod(u, m);
        cout << "d = " << inverse << "\n";
        cout << c << " * " << inverse << " mod " << m << " = " << c * inverse % m << "\n";
    } else{
        cout << "Обратного элемента нет.\n";
    }
}