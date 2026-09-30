#include "fermat.h"
#include "math_utils.h"
#include <iostream>

using namespace std;

int mod(int base, int power, int modulo){
    base %= modulo;
    power %= modulo - 1;
    int result = 1;
    cout << "Уменьшенная степень: " << power << "\n";
    for (int i = 0; i < power; ++i){
        result *= base;
        result %= modulo;
        cout << "Шаг " << i + 1 << ": " << result << "\n";
    }
    return result;
}

void runFermat(){
    int a, x, p;
    cout << "Введите a, x и p: ";
    cin >> a >> x >> p;
    if (x < 0 || p <= 1){
        cout << "Некорректные данные.\n";
        return;
    }
    cout << "p " << (isPrime(p) ? "простое" : "не простое") << ", НОД(" << a << ", " << p << ") = " << gcdInt(a, p) << "\n";
    if (isPrime(p) && gcdInt(a, p) == 1){
        cout << "\nТеорема Ферма:\n";
        int resultFermat = mod(a, x, p);
        cout << "Ответ: " << resultFermat << "\n";
    } else{
        cout << "Теорему Ферма применить нельзя.\n";
    }
    cout << "\nБинарное возведение:\n";
    int resultBinary = binaryMod(a, x, p, true);
    cout << "Ответ: " << resultBinary << "\n";
}