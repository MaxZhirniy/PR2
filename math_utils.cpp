#include "math_utils.h"
#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0) return false;
    }
    return true;
}

int gcdInt(int a, int b){
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int normalizeMod(int a, int m){
    a %= m;
    if (a < 0) a += m;
    return a;
}

int binaryMod(int base, int power, int modulo, bool printSteps){
    base %= modulo;
    int result = 1;
    if (printSteps) cout << "Степень\tОснование\tБит\tРезультат\n";
    while (power > 0){
        int bit = power % 2;
        if (bit == 1) result = result * base % modulo;
        if (printSteps) cout << power << "\t" << base << "\t\t" << bit << "\t" << result << "\n";
        base = base * base % modulo;
        power /= 2;
    }
    return result;
}