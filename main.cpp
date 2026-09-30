#include "fermat.h"
#include "euclid.h"
#include "inverse.h"
#include "rsa.h"
#include <iostream>

using namespace std;

enum class Task{
    Exit = 0,
    Fermat = 1,
    Euclid = 2,
    Inverse = 3,
    RSA = 4
};

int main(){
    int choice;
    do{
        cout << "\n1. Теорема Ферма и бинарное возведение\n";
        cout << "2. Расширенный алгоритм Евклида\n";
        cout << "3. Обратное число по модулю\n";
        cout << "4. RSA\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;
        cout << "\n";
        switch (static_cast<Task>(choice)){
            case Task::Fermat:
                runFermat();
                break;
            case Task::Euclid:
                runEuclid();
                break;
            case Task::Inverse:
                runInverse();
                break;
            case Task::RSA:
                runRsa();
                break;
            case Task::Exit:
                break;
            default:
                cout << "Неверный номер задания.\n";
        }
    } while (choice != static_cast<int>(Task::Exit));
    return 0;
}