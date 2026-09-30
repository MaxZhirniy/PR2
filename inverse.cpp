#include "inverse.h"
#include "euclid.h"
#include "math_utils.h"
#include <iostream>

using namespace std;

void runInverse(){
    int c, m, u, v;
    cout << "Введите c и m: ";
    cin >> c >> m;
    if (c <= 0 || m <= 1){
        cout << "Некорректные данные.\n";
        return;
    }
    int d = extendedEuclid(c, m, u, v);
    if (d != 1){
        cout << "Обратного элемента не существует.\n";
        return;
    }
    int inverse = normalizeMod(u, m);
    cout << c << " * " << u << " + " << m << " * " << v << " = 1\n";
    cout << c << "^(-1) mod " << m << " = " << inverse << "\n";
    cout << "Проверка: " << c << " * " << inverse << " mod " << m << " = " << c * inverse % m << "\n";
}