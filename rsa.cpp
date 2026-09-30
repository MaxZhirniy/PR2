#include "rsa.h"
#include "euclid.h"
#include "math_utils.h"
#include <fstream>
#include <iostream>

using namespace std;
const string LOGPATH = "log.txt";


void encryptFileRsa(const string inputPath, const char *encryptedPath, int e, int n, ofstream &logFile){
    ifstream input(inputPath, ios::binary);
    ofstream encrypted(encryptedPath);
    if (!input.is_open()){
        cout << "Не удалось открыть " << inputPath << "\n";
        return;
    }
    if (!encrypted.is_open()){
        cout << "Не удалось создать " << encryptedPath << "\n";
        return;
    }
    char symbol;
    int number = 0;
    while (input.read(reinterpret_cast<char*>(&symbol), sizeof(symbol))){
        string log;
        int m = static_cast<unsigned char>(symbol);
        int c = binaryMod(m, e, n);
        encrypted.write(reinterpret_cast<const char*>(&c), sizeof(c));
        cout << "Байт " << number << ": " << m << "^" << e << " mod " << n << " = " << c << "\n";
        logFile << "Байт " << number << ": " << m << "^" << e << " mod " << n << " = " << c << "\n";
        ++number;
    }
}

void decryptFileRsa(const char *encryptedPath, const char *decryptedPath, int d, int n, ofstream &logFile){
    ifstream encrypted(encryptedPath);
    ofstream decrypted(decryptedPath, ios::binary);
    if (!encrypted.is_open()){
        cout << "Не удалось открыть " << encryptedPath << "\n";
        return;
    }
    if (!decrypted.is_open()){
        cout << "Не удалось создать " << decryptedPath << "\n";
        return;
    }
    int c;
    int number = 0;
    while (encrypted.read(reinterpret_cast<char*>(&c), sizeof(c))){
        int m = binaryMod(c, d, n);
        unsigned char symbol = static_cast<unsigned char>(m);
        decrypted.write(reinterpret_cast<const char*>(&symbol), sizeof(symbol));
        cout << "Байт " << number << ": " << c << "^" << d << " mod " << n << " = " << m << "\n";
        logFile << "Байт " << number << ": " << c << "^" << d << " mod " << n << " = " << m << "\n";
        ++number;
    }
}

void runRsa(){
    ofstream logFile(LOGPATH);
    string inputPath;
    const char *encryptedPath = "encrypted_rsa.bin";
    const char *decryptedPath = "decrypted.txt";
    cout << "Введите путь к исходному файлу: ";
    getline(cin >> ws, inputPath);
    int p = 17;
    int q = 23;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 3;
    cout << "p = " << p << ", q = " << q << "\n";
    logFile << "p = " << p << ", q = " << q << "\n";
    cout << "n = " << p << " * " << q << " = " << n << "\n";
    logFile << "n = " << p << " * " << q << " = " << n << "\n";
    cout << "phi(n) = " << p - 1 << " * " << q - 1 << " = " << phi << "\n";
    logFile << "phi(n) = " << p - 1 << " * " << q - 1 << " = " << phi << "\n";
    cout << "e = " << e << ", НОД(" << e << ", " << phi << ") = " << gcdInt(e, phi) << "\n";
    logFile << "e = " << e << ", НОД(" << e << ", " << phi << ") = " << gcdInt(e, phi) << "\n";
    int u, v;
    int gcd = extendedEuclid(e, phi, u, v);
    if (gcd != 1){
        cout << "Невозможно найти d.\n";
        return;
    }
    int d = normalizeMod(u, phi);
    cout << "d = " << d << "\n";
    cout << "Проверка: " << e << " * " << d << " mod " << phi << " = " << e * d % phi << "\n";
    cout << "Открытый ключ: (" << n << ", " << e << ")\n";
    cout << "Закрытый ключ: (" << n << ", " << d << ")\n";
    cout << "\nШифрование:\n";
    logFile << "\nШифрование:\n";
    encryptFileRsa(inputPath, encryptedPath, e, n, logFile);
    cout << "\nРасшифрование:\n";
    logFile << "\nРасшифрование:\n";
    decryptFileRsa(encryptedPath, decryptedPath, d, n, logFile);
}